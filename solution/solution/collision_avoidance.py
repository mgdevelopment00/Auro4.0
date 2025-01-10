import sys
import time
import math

import os
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from auro_interfaces.srv import Sector, Collision, CheckGoal
from auro_interfaces.action import Move
from sensor_msgs.msg import LaserScan
from rclpy.qos import QoSPresetProfiles
from rclpy.action import ActionClient
from nav2_msgs.srv import GetCostmap
import logging

from std_msgs.msg import String

from enum import Enum


SCAN_THRESHOLD = 0.55
SCAN_FRONT = 0
SCAN_LEFT = 1
SCAN_BACK = 2
SCAN_RIGHT = 3


class State(Enum):
    IDLE = 0

class CollisionAvoidance(Node):
    def __init__(self):
        super().__init__('collision_avoidance')
        
        self.scan_subscriber = self.create_subscription(
            LaserScan,
            '/robot1/scan',
            self.scan_callback,
            QoSPresetProfiles.SENSOR_DATA.value)
            
        self.scan_triggered = [False] * 4
        
        self.declare_parameter("robot_name", "default")
        self.robot_name = self.get_parameter("robot_name").get_parameter_value().string_value
        self.costmap = None
        self.costmap_information = None
        
        self.logger = logging.getLogger('collision_avoidance ' + self.robot_name)
        self.logger.setLevel(logging.DEBUG)
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'collision_avoidance'  + self.robot_name + '.log')
        handler = logging.FileHandler(log_file_path)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)
        

        self.avoidance_server = self.create_service(Collision, '/collision_avoidance', self.service_collision)
        self.check_costmap_service = self.create_service(CheckGoal, '/check_goal', self.service_check_goal) # come back
        self.costmap_client = self.create_client(GetCostmap, '/' + self.robot_name + '/global_costmap/get_costmap')
        
        while not self.costmap_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("Waiting for server")
        
        self.create_timer(30.0, self.get_costmap)
            
    
    def service_check_goal(self, request, response):
       self.logger.info(self.costmap)
       if self.costmap == None:
          response.obstacle = True
          return response
    
       x = request.x
       y = request.y
       info = self.costmap_information
       point = int((y-info.origin.position.y)/info.resolution) * info.size_x + int((x-info.origin.position.x)/info.resolution)
       cost = self.costmap.data[point]
        
       #Not in obstacle
       if cost <= 110:
          response.obstacle = False
       else:
          response.obstacle = True
        
       return response
            
            
    def get_costmap(self):
        request = GetCostmap.Request()
        future = self.costmap_client.call_async(request)
        future.add_done_callback(self.get_costmap_callback)
    
    def get_costmap_callback(self, future):
        result = future.result()
        
        if result:
           self.costmap = result.map
           self.costmap_information = result.map.metadata
        else:
           self.logger.info("Error retrieving map")
     
        
        
    def scan_callback(self, msg):
        front_ranges = msg.ranges[331:359] + msg.ranges[0:30]
        left_ranges  = msg.ranges[31:90]
        back_ranges  = msg.ranges[91:270]
        right_ranges = msg.ranges[271:330]

        self.scan_triggered[SCAN_FRONT] = min(front_ranges) < SCAN_THRESHOLD 
        self.scan_triggered[SCAN_LEFT]  = min(left_ranges)  < SCAN_THRESHOLD
        self.scan_triggered[SCAN_BACK]  = min(back_ranges)  < SCAN_THRESHOLD
        self.scan_triggered[SCAN_RIGHT] = min(right_ranges) < SCAN_THRESHOLD
        

    
    def service_collision(self, request, response):
        response.success = False
        response.direction = ""
        
        for item in self.scan_triggered:
           self.logger.info(item)
        
        if self.scan_triggered[SCAN_FRONT]:
           response.success = True 
           response.direction = "FRONT"
        elif self.scan_triggered[SCAN_LEFT]:
           response.success = True 
           response.direction = "BACK"
           response.success = True 
        elif self.scan_triggered[SCAN_RIGHT]:
           response.direction = "RIGHT"
           response.success = True 
        elif self.scan_triggered[SCAN_BACK]:
           response.direction = "BACK"
           response.success = True 
        
        return response
    
 
        
def main(args=None):
    rclpy.init(args=args)

    node = CollisionAvoidance()

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

