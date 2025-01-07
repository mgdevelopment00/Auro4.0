import sys
import time
import Math

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from auro_interface.srv import Sector

from std_msgs.msg import String

from enum import Enum

class State(Enum):
    NOT_SENT = 0
    SENT = 1

class RobotManager(Node):
    def __init__(self):
        super().__init__('robot_manager')
        
        self.available_sectors = ["cyan", "purple", "pink", "green"]
        self.sectors = {"cyan": [-3.5, 2.4], "pink": [2.5, 2.4], "purple": [-3.5, -2.4], "green": [2.5, -2.4]}
        
        self.sector_service = self.create_service(Sector, '/sector_service', self.service_sector)
    
    
    
    def service_sector(self, request, response):
        robot_id = request.data.robot_id
        current_x = request.data.x
        current_y = request.data.y
        closest_sector = None
        lowest_distance = 100000000
        
        self.logger.info("RUnning")
        
        for sector in sectors:
           sector_cords = self.available_sectors[sector]
           distance = math.sqrt((sector_cords[0]-current_x)**2 + (sector_cords[1]-current_y)**2)
           
           if distance < lowest_distance:
               lowest_distance = distance
               closest_sector = sector
        
        self.available_sectors.remove(closest_sector)
        chosen_sector = self.sectors[closest_sector]
        response.x = chosen_sector[0]
        response.y = chosen_sector[1]
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

