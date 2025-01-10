import sys
import time
import math

import os
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from auro_interfaces.srv import Sector, Collision
from auro_interfaces.action import Move
from sensor_msgs.msg import LaserScan
from rclpy.qos import QoSPresetProfiles
from rclpy.action import ActionClient
import logging

from std_msgs.msg import String

from enum import Enum


SCAN_THRESHOLD = 0.35
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
        
        
        self.logger = logging.getLogger('collision_avoidance')
        self.logger.setLevel(logging.DEBUG)
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'collision_avoidance.log')
        handler = logging.FileHandler(log_file_path)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)
        
        self.logger.info("firing up")
            
        self.avoidance_server = self.create_service(Collision, '/collision_avoidance', self.service_collision)
        self.moved = False
        
     
        
        
    def scan_callback(self, msg):
        front_ranges = msg.ranges[331:359] + msg.ranges[0:30]
        left_ranges  = msg.ranges[31:90]
        back_ranges  = msg.ranges[91:270]
        right_ranges = msg.ranges[271:330]

        self.scan_triggered[SCAN_FRONT] = min(front_ranges) < SCAN_THRESHOLD 
        self.scan_triggered[SCAN_LEFT]  = min(left_ranges)  < SCAN_THRESHOLD
        self.scan_triggered[SCAN_BACK]  = min(back_ranges)  < SCAN_THRESHOLD
        self.scan_triggered[SCAN_RIGHT] = min(right_ranges) < SCAN_THRESHOLD
        
        self.logger.info(min(front_ranges) < SCAN_THRESHOLD)
        self.logger.info(min(left_ranges)  < SCAN_THRESHOLD)
        self.logger.info(min(back_ranges)  < SCAN_THRESHOLD)
        self.logger.info(min(right_ranges) < SCAN_THRESHOLD)
        
    
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
        
        self.logger.info("Direction: " + str(response.direction))
        self.logger.info("Success: " + str(response.success))
        
        
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

