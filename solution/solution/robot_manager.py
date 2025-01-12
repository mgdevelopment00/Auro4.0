import sys
import time
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from auro_interfaces.srv import ZoneRequest

from std_msgs.msg import String

from enum import Enum


class RobotManager(Node):
    def __init__(self):
        super().__init__('robot_manager')
        
        self.available_zones = ["cyan", "purple", "pink", "green"]
        self.zones = {"cyan": [-3.5, 2.2], "pink": [2.5, 2.2], "purple": [-3.5, -2.2], "green": [2.5, -2.2]}
        
        self.zone_service = self.create_service(ZoneRequest, '/zone_service', self.service_request)
    
    
    
    def service_request(self, request, response):
        robot_id = request.robot_id
        current_x = request.x
        current_y = request.y
        closest_sector = None
        lowest_distance = 100000000
        
        for zone in self.available_zones:
           zone_cords = self.zones.get(zone, -1)
           distance = math.sqrt((zone_cords[0]-current_x)**2 + (zone_cords[1]-current_y)**2)
           
           if distance < lowest_distance:
               lowest_distance = distance
               closest_zone = zone
        
        self.available_zones.remove(closest_zone)
        chosen_zone = self.zones[closest_zone]
        response.x = chosen_zone[0]
        response.y = chosen_zone[1]
        return response
        
        
def main(args=None):
    rclpy.init(args=args)

    node = RobotManager()

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

