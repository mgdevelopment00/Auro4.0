import sys
import time
import os
import rclpy
import math
import random
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from assessment_interfaces.msg import ItemList
from auro_interfaces.srv import Rotate, Task, FindTarget
from geometry_msgs.msg import Quaternion
from auro_interfaces.action import Move
import logging
from rclpy.action import ActionClient
from example_interfaces.srv import SetBool
from std_msgs.msg import String
from enum import Enum
from functools import partial
from nav_msgs.msg import Odometry

class State(Enum):
    IDLE = 1
    FIND_TARGET = 2
    BUSY = 3
    ALIGNED_WITH_TARGET = 4
    NO_BALL_IN_SIGHT = 5

class RobotVision(Node):
    def __init__(self):
        super().__init__('robot_vision')
        
        self.declare_parameter("robot_name", "default")
        self.robot_name = self.get_parameter("robot_name").get_parameter_value().string_value

        self.logger = logging.getLogger('vision ' + self.robot_name)
        self.logger.setLevel(logging.DEBUG)
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'robot_vision' + self.robot_name + '.log')
        handler = logging.FileHandler(log_file_path)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)
        
        
        
        self.declare_parameter('x', 0.0)
        self.declare_parameter('y', 0.0)
        self.declare_parameter('yaw', 0.0)
        self.declare_parameter("num_robots", 1)
        self.x = self.get_parameter('x').get_parameter_value().double_value
        self.y = self.get_parameter('y').get_parameter_value().double_value
        self.yaw = self.get_parameter('yaw').get_parameter_value().double_value
        self.num_robots = self.get_parameter("num_robots").get_parameter_value().integer_value
        
        self.colour = None
        
        if self.num_robots == 1:
           self.colour = "any"
        else:
           if self.robot_name == "robot1":
               self.colour = "BLUE"
           elif self.robot_name == "robot2":
               self.colour = "RED"
           elif self.robot_name == "robot3":
               self.colour = "GREEN"
        
        self.item_subscription = self.create_subscription(ItemList, 'items', self.item_callback, 1)
        self.rotate_client = self.create_client(Rotate, '/rotate_robot')
        self.navigation_client = self.create_client(Task, '/navigate')
        self.vision_service = self.create_service(FindTarget, '/find_target', self.service_vision)
        
        
        # Deal with this
        self.last_moved = None
        self.found_first_ball = False
        self.start_time = self.get_clock().now()
        self.sector = None
        self.previous_ball = [None, None]
        self.rotate_count = 0
        self.target_diameter = -1
        self.previous_state = None
        self.collected_balls = []
        self.balls_collected = 0
        self.rotation_direction = None
        self.load_up_time = 10
        self.state = State.FIND_TARGET
        self.ball_diameter = 0.075 * 2
        self.items = None
        self.current_ball_colour = None

        while not self.rotate_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("waiting for rotate")
        
        self.create_timer(0.1, self.control_loop)
            
    
    
    def service_vision(self, request, response):
        if self.state == State.IDLE:
           self.state = State.FIND_TARGET
           response.success = True
        else:
           response.success = False
           
        return response
    
    
    def rotate_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
                if self.rotation_direction == "left":
                   self.rotate_count -= 1
                elif self.rotation_direction == "right":
                   self.rotate_count += 1
                
                self.rotation_direction = None
                
        except Exception as e:
            self.logger.info(e)
            pass
        finally:

            if self.previous_state == State.NO_BALL_IN_SIGHT:
               self.state = State.FIND_TARGET
            else:
               self.state = State.FIND_TARGET
    
    def navigation_callback(self, future):
        result = future.result()
        
        if result:
           self.last_moved = self.get_clock().now()
           self.logger.info("Navigation started")
        else:
           self.logger.info("Navigation failed to start")
        
    
    def item_callback(self, msg):
        self.items = msg.data
    
   
    def set_to_busy(self, state):
       self.previous_state = state
       self.state = State.BUSY
    
            
    def is_ball_collected(self, x, y):
        for item in self.collected_balls:
            collected_x = item[0]
            collected_y = item[1]
            
            if abs(collected_x - x)  <= 0.25 and abs(collected_y - y) <= 0.25:
                return True
        return False
        
    
    def calculate_distance(self, perceived_diameter):
        return (self.ball_diameter * 530.4)/perceived_diameter
        
    def is_ball_collected(self, x, y):
        for item in self.collected_balls:
           collected_x = item[0]
           collected_y = item[1]
            
           if abs(collected_x - x)  <= 0.25 and abs(collected_y - y) <= 0.25:
                return True
           return False

        
    def time_difference(self, t_a, t_b):
        return (t_a - t_b).nanoseconds / 10e9
    
    
    def calculate_position(self, distance, angle):
         new_x = self.x + distance * math.cos(angle)
         new_y = self.y + distance * math.sin(angle)
         return new_x, new_y
        
    
    def send_navigation_task(self, task, diameter, colour):
        request = Task.Request()
       
        if task == "move_to_target":
           request.move_to_target = True
           request.diameter = float(diameter)
           request.colour = colour
        elif task == "random_walk":
           request.move_to_target = False
           request.diameter = -1.0
           request.colour = "nil"
        
        self.state = State.IDLE
        future = self.navigation_client.call_async(request)
        future.add_done_callback(self.navigation_callback)
        
    
    def control_loop(self):
        data = self.items
         
        match self.state:
            
            case State.FIND_TARGET:
                
                self.logger.info("rotate count: " + str(self.rotate_count))
                
                if self.time_difference(self.get_clock().now(), self.start_time) < self.load_up_time:
                     return
                
                self.set_to_busy(State.FIND_TARGET)
                data = self.items
                closest_x = math.inf
                
                for i in range(len(data)):
                    colour = data[i].colour
                    diameter = data[i].diameter
                    chosen_diameter = -1
                    x = data[i].x
                    
                    distance = self.calculate_distance(diameter)
                    calculated_x, calculated_y = self.calculate_position(distance, self.yaw)
                    
                    
                    if self.last_moved:
                       if self.time_difference(self.get_clock().now(), self.last_moved) > 20:
                           self.send_navigation_task("random_walk", -1.0, "nil")
                           return
                    
                    if not self.found_first_ball and abs(self.rotate_count) == 600:
                       self.send_navigation_task("random_walk", -1.0, "nil")
                       return
                       
                    if self.colour != "any" and colour != self.colour:
                       continue
                    
                    
                    if self.is_ball_collected(calculated_x, calculated_y):
                        continue
                    
                        
                    if abs(x) < abs(closest_x):
                        self.target_diameter = diameter
                        chosen_diameter = diameter
                        closest_x = x
                        self.current_ball_colour = colour
                
                if closest_x == math.inf:
                    self.state = State.NO_BALL_IN_SIGHT
                    return

                if closest_x:
                    if abs(closest_x) >= 12:
                        
                        # Right is true, left is false
                        request = Rotate.Request()
                        
                        if closest_x < 0:
                           self.rotation_direction = "left"
                           request.direction = False
                        else:
                           self.rotation_direction = "right"
                           request.direction = True
                           
                        future = self.rotate_client.call_async(request)
                        future.add_done_callback(self.rotate_callback)
                    else:
                        self.state = State.ALIGNED_WITH_TARGET
                    
    
            case State.ALIGNED_WITH_TARGET:
                self.logger.info("Aligned with target")
                self.found_first_ball = True
                self.set_to_busy(State.ALIGNED_WITH_TARGET)
                self.send_navigation_task("move_to_target", self.target_diameter, self.current_ball_colour)

 
            case State.NO_BALL_IN_SIGHT:
                self.logger.info("No ball in sight")
                self.set_to_busy(State.NO_BALL_IN_SIGHT)
                request = Rotate.Request()
                self.rotation_direction = "left"
                request.direction = False
                
                future = self.rotate_client.call_async(request)
                future.add_done_callback(self.rotate_callback)
            
            
            
            
def main(args=None):
    rclpy.init(args=args)

    node = RobotVision()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        node.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    main()

