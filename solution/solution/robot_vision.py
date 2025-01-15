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
        self.rotate_client = self.create_client(Rotate, '/'+ self.robot_name +  '/rotate_robot')
        self.navigation_client = self.create_client(Task, '/'+ self.robot_name + '/navigate')
        self.vision_service = self.create_service(FindTarget, '/'+ self.robot_name + '/find_target', self.service_vision)
        
        # Time that robot last moved
        self.last_moved = None
        self.found_first_ball = False
        self.start_time = self.get_clock().now()
        # Location of previous ball
        self.previous_ball = [None, None]
        # Number of times that robot has rotated
        self.rotate_count = 0
        # Diameter of ball that the robot has locked onto
        self.target_diameter = -1
        self.previous_state = None
        self.collected_balls = []
        self.balls_collected = 0
        # Direction that the robot has rotated in
        self.rotation_direction = None
        self.load_up_time = 10
        self.state = State.FIND_TARGET
        # Diameter of ball
        self.ball_diameter = 0.075 * 2
        # Items that the robot can see
        self.items = None
        # Colour of ball that the robot is locked onto
        self.current_ball_colour = None

        while not self.rotate_client.wait_for_service(timeout_sec=1.0):
            #self.logger.info("waiting for rotate")
            pass
        
        self.create_timer(0.1, self.control_loop)
            
    
    # Service a request from robot vision to find next target
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
            #self.logger.info(e)
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
           #self.logger.info("Navigation started")
        else:
           #self.logger.info("Navigation failed to start")
           pass
        
    
    def item_callback(self, msg):
        self.items = msg.data
    
   
    def set_to_busy(self, state):
       self.previous_state = state
       self.state = State.BUSY
    
    # Check if a ball that the robot can see has been collected before        
    def is_ball_collected(self, x, y):
        for item in self.collected_balls:
            collected_x = item[0]
            collected_y = item[1]
            
            if abs(collected_x - x)  <= 0.25 and abs(collected_y - y) <= 0.25:
                return True
        return False
        
    
    def calculate_distance(self, perceived_diameter):
        return (self.ball_diameter * 530.4)/perceived_diameter
   
    def time_difference(self, t_a, t_b):
        return (t_a - t_b).nanoseconds / 10e9
    
    # Calculate position of ball from our rotation and predicted distance to ball
    def calculate_position(self, distance, angle):
         new_x = self.x + distance * math.cos(angle)
         new_y = self.y + distance * math.sin(angle)
         return new_x, new_y
        
    # Send navigation task to navigation node. Random walk and move to target are 
    # wrapped up into one request to simplify things
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
                
                #self.logger.info("rotate count: " + str(self.rotate_count))
                
                #if self.time_difference(self.get_clock().now(), self.start_time) < self.load_up_time:
                     #return
                
                self.set_to_busy(State.FIND_TARGET)
                data = self.items
                target_x = math.inf
                
                for i in range(len(data)):
                    colour = data[i].colour
                    diameter = data[i].diameter
                    chosen_diameter = -1
                    x = data[i].x
                    
                    distance = self.calculate_distance(diameter)
                    calculated_x, calculated_y = self.calculate_position(distance, self.yaw)
                    

                    if self.last_moved:
                       # If robot hasn't moved in 20 seconds send on random walk
                       if self.time_difference(self.get_clock().now(), self.last_moved) > 20:
                           self.send_navigation_task("random_walk", -1.0, "nil")
                           return
                    
                    # If a robot has rotated 600 times we go on a random walk
                    if not self.found_first_ball and abs(self.rotate_count) == 600:
                       self.send_navigation_task("random_walk", -1.0, "nil")
                       return
                    
                    # Skip if not correct colour ball
                    if self.colour != "any" and colour != self.colour:
                       continue
                    
                    
                    if self.is_ball_collected(calculated_x, calculated_y):
                        continue
                    
                    # Check to see if the ball we are looking at is closer to the
                    # center of the camera than current ball we have picked to lock on to    
                    if abs(x) < abs(target_x):
                        self.target_diameter = diameter
                        chosen_diameter = diameter
                        target_x = x
                        self.current_ball_colour = colour
                
                # Implies that no suitable balls in vision
                if target_x == math.inf:
                    self.state = State.NO_BALL_IN_SIGHT
                    return

                if target_x:
                   
                   # Ball is outside threshold to be aligned with robot
                    if abs(target_x) >= 12:
                        
                        # Right is true, left is false
                        request = Rotate.Request()
                        
                        if target_x < 0:
                           self.rotation_direction = "left"
                           request.direction = False
                        else:
                           self.rotation_direction = "right"
                           request.direction = True
                           
                        future = self.rotate_client.call_async(request)
                        future.add_done_callback(self.rotate_callback)
                    else:
                        # Ball is within 12 pixel threshold of center of camera meaning we
                        # can move to it
                        self.state = State.ALIGNED_WITH_TARGET
                    
    
            case State.ALIGNED_WITH_TARGET:
                #self.logger.info("Aligned with target")
                self.found_first_ball = True
                self.set_to_busy(State.ALIGNED_WITH_TARGET)
                self.send_navigation_task("move_to_target", self.target_diameter, self.current_ball_colour)

            # Runs when the robot cannot see a ball
            case State.NO_BALL_IN_SIGHT:
                #self.logger.info("No ball in sight")
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

