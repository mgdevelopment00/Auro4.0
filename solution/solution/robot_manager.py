import sys
import time

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from auro_interface.srv import Sector

from std_msgs.msg import String

from enum import Enum

class State(Enum):
    NOT_SENT = 0
    SENT = 1

class RouteManager(Node):
    def __init__(self):
        super().__init__('route_manager')
        
        self.available_sectors = ["blue"]
        self.sector_claim = {}
        
        self.sector_service = self.create_service(Sector, 'robot1/sector_service', self.service_sector)
    
    
    
    def service_sector(self, request, response):
        robot_id = request.data.robot_id
        sector = request.data.sector_name
        
        
def main(args=None):
    rclpy.init(args=args)

    node = RouteManager()

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

