import sys
import time
import os
import rclpy
import math
import random
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from assessment_interfaces.msg import ItemList
from auro_interfaces.srv import ItemRequest, Sector, Collision, CheckGoal
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
    FINDING_TARGET = 1

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
        
        self.colour = None
        
        if self.robot_name == "robot1":
           self.colour = "BLUE"
        elif self.robot_name == "robot2":
           self.colour = "RED"
        elif self.robot_name == "robot3":
           self.colour = "GREEN"
        
        self.declare_parameter('x', 0.0)
        self.declare_parameter('y', 0.0)
        self.declare_parameter('yaw', 0.0)
        self.x = self.get_parameter('x').get_parameter_value().double_value
        self.y = self.get_parameter('y').get_parameter_value().double_value
        self.yaw = self.get_parameter('yaw').get_parameter_value().double_value
        
        self.state = State.FINDING_TARGET
        self.ball_diameter = 0.075 * 2
        self.item_subscription = self.create_subscription(ItemList, 'items', self.item_callback, 1)
        self.robot_controller_publisher = self.create_publisher(String, "route", 10)
        self.rotate_client = self.create_client(SetBool, '/rotate_robot')
        self.pick_up_client = self.create_client(ItemRequest, '/pick_up_item')
        self.drop_off_client = self.create_client(ItemRequest, '/offload_item')
        self.move_client = ActionClient(self, Move, self.robot_name + '/move_robot')
        self.sector_client = self.create_client(Sector, '/sector_service')
        self.collision_client = self.create_client(Collision, '/collision_avoidance')
        self.odom_subscriber = self.create_subscription(Odometry, '/' + self.robot_name + '/odom', self.odom_callback, 10)
        self.check_costmap_client = self.create_client(CheckGoal, '/check_goal')
        self.last_moved = None
        
        
        self.start_time = self.get_clock().now()
        self.sector = None
        self.previous_ball = [None, None]
        
        self.control_loop_rate = 1/10
        self.rotate_count = 0
        self.largest_diameter = -1
        self.previous_state = None
        self.collected_balls = []
        self.collision_direction = None
        self.balls_collected = 0
        self.rotation_direction = None
        self.load_up_time = 10
        self.random_walk_x = None
        self.random_walk_y = None
        self.items = None
        
        while not self.pick_up_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("Waiting for pick up server")
            
        while not self.rotate_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("Waiting for rotate server")
            
        while not self.move_client.wait_for_server(timeout_sec=1.0):
            self.logger.info("Waiting for move action server")
            
        self.create_timer(self.control_loop_rate, self.control_loop)
    
    
    def item_callback(self, msg):
        self.items = msg.data
    
    
    def 
    
    
    def control_loop(self):
    
        match self.State:
            
            case State.FINDING_TARGET:
                 if (self.get_clock().now() - self.start_time).nanoseconds / 10e9 < self.load_up_time:
                     return
                
                 self.set_to_busy(State.FINDING_TARGET)
                 data = msg.data
                 closest_x = math.inf
                
                 for i in range(len(data)):
                     colour = data[i].colour
                     diameter = data[i].diameter
                     chosen_diameter = -1
                     x = data[i].x
                    
                     self.logger.info(self.rotate_count)
                    
                     distance = self.calculate_distance(diameter)
                     calculated_x, calculated_y = self.calculate_position(self.x, self.y, distance)
                    
                     if self.last_moved:
                        if (self.get_clock().now() - self.last_moved).nanoseconds / 10e9 > 150:
                            self.state = State.RANDOM_WALK
                            return
                     elif abs(self.rotate_count) == 610:
                        rotate_count = 0
                        self.state = State.RANDOM_WALK
                        return
                     elif colour != self.colour or self.is_ball_collected(calculated_x, calculated_y):
                         continue
                    
                        
                     if abs(x) < abs(closest_x):
                         self.largest_diameter = diameter
                         chosen_diameter = diameter
                         closest_x = x
                
                 if closest_x == math.inf:
                     self.state = State.SPIN_CHECK
                     return

                 if closest_x:
                     if abs(closest_x) >= 12:
                         # Right is true, left is false
                         request = SetBool.Request()
                        
                         if closest_x < 0:
                            self.rotation_direction = "left"
                            request.data = False
                         else:
                            self.rotation_direction = "right"
                            request.data = True
                           
                         future = self.rotate_client.call_async(request)
                         future.add_done_callback(self.rotate_callback)
                     else:
                         self.state = State.ALIGNED_WITH_TARGET
        
            case State.ALIGNED_WITH_TARGET:
                pass
    
                
                
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

