import sys
import time
import os
import rclpy
import math
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from assessment_interfaces.msg import ItemList
import logging
from example_interfaces.srv import SetBool
from std_msgs.msg import String
from enum import Enum
from functools import partial

class State(Enum):
    FINDING_TARGET = 1
    MOVING_TO_TARGET = 2
    ALIGNED_WITH_TARGET = 3
    BUSY = 4

class RobotVision(Node):
    def __init__(self):
        super().__init__('robot_vision')

        self.logger = logging.getLogger('vision')
        self.logger.setLevel(logging.DEBUG)
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'robot_vision.log')
        handler = logging.FileHandler(log_file_path)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)

        self.state = State.FINDING_TARGET
        self.colour = "RED"
        self.ball_diameter = 0.075 * 2
        self.item_subscription = self.create_subscription(ItemList, 'items', self.control_loop, 1)
        self.robot_controller_publisher = self.create_publisher(String, "route", 10)
        self.rotate_client = self.create_client(SetBool, 'rotate_robot')

        self.rotate_count = 0
        self.previous_x = -1
        self.largest_diameter = -1
        
        
    def rotate_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
                self.rotate_count += 1
                self.logger.info(self.rotate_count)
        except Exception as e:
            self.logger.info(e)
            pass
        finally:
            self.state = State.FINDING_TARGET
        

    def control_loop(self, msg):
        data = msg.data
        
        match self.state:
            case State.FINDING_TARGET:
                self.state = State.BUSY
                data = msg.data
                largest_diameter = 1000000
                closest_x = None
                
                for i in range(len(data)):
                    item = data[i]
                    colour = item.colour
                    x = abs(item.x)
                    diameter = item.diameter
                    
                    if diameter < largest_diameter and colour == self.colour:
                        largest_diameter = diameter
                        self.largest_diameter = diameter
                        closest_x = x
                
                if closest_x >= 6:
                    request = SetBool.Request()
                    request.data = True

                    # Ensure service client is ready
                    while not self.rotate_client.wait_for_service(timeout_sec=1.0):
                        self.logger.info("Waiting for server")
                        
                    future = self.rotate_client.call_async(request)
                    future.add_done_callback(partial(self.rotate_callback))
                else:
                    self.state = State.ALIGNED_WITH_TARGET
                
                    
            case State.ALIGNED_WITH_TARGET:
                distance = (self.ball_diameter * 530.4) / self.largest_diameter
                self.logger.info(distance)
                current = [-3.5, 0]
                angle = math.radians(self.rotate_count)
                new_x = current[0] + distance * math.cos(angle)
                new_y = current[1] + distance * math.sin(angle)
                
                msg = String()
                msg.data = "p," + str(new_x) + "," + str(new_y) + ",0.0,0"
                self.robot_controller_publisher.publish(msg)
                self.state = State.BUSY

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


