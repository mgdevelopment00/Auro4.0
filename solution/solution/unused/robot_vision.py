import sys
import time
import os

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import logging
import math

from std_msgs.msg import String
from sensor_msgs.msg import CameraInfo
from assessment_interfaces.msg import ItemList
from geometry_msgs.msg import Quaternion

from enum import Enum

class State(Enum):
    NO_COLOUR = 0
    PICKING_COLOUR = 1

class RobotVision(Node):
    def __init__(self):
        super().__init__('robot_vision')
        self.declare_parameter("robot_name", "default")
        self.name = self.get_parameter("robot_name").get_parameter_value().string_value
        
        """
        sensor_msgs.msg.CameraInfo(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=19, nanosec=172000000), frame_id='camera_rgb_optical_frame'), height=480, width=640, distortion_model='plumb_bob', d=[0.0, 0.0, 0.0, 0.0, 0.0], k=array([530.46694066, 0. , 320.5 , 0. , 530.46694066, 240.5 , 0. , 0. , 1. ]), r=array([1., 0., 0., 0., 1., 0., 0., 0., 1.]), p=array([530.46694066, 0. , 320.5 , -0. , 0. , 530.46694066, 240.5 , 0. , 0. , 0. , 1. , 0. ]), binning_x=0, binning_y=0, roi=sensor_msgs.msg.RegionOfInterest(x_offset=0, y_offset=0, height=0, width=0, do_rectify=False))
        """
        
        # Intrinsic camera properties obtain through 
        self.image_height = 480
        self.image_width = 640
        self.camera_fx = 530.44694066
        self.camera_fy = 530.4469066
        self.camera_cx = 320.5
        self.camera_cy = 240.5
        
        self.logger = logging.getLogger('vision'+self.name) 
        self.logger.setLevel(logging.DEBUG)  
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'robot_vision' + self.name + '.log') 
        handler = logging.FileHandler(log_file_path) 
        handler.setLevel(logging.DEBUG) 
        formatter = logging.Formatter('')  
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)
        self.state = State.NO_COLOUR
        
        self.item_subscription = self.create_subscription(ItemList, 'items', self.no_colour, 10)
    
    def no_colour(self, msg):
        match self.state:
            case State.NO_COLOUR:
               if len(msg.data) != 0:
                   self.state = State.PICKING_COLOUR
                   self.picking_colour(msg)
      
                              
    def picking_colour(self, imsg):
        colours = [0, 0, 0]
        
        for i in range(len(imsg.data)):
            colour = imsg.data[i].colour
            self.logger.info(str(self.calculate_angle(imsg.data[i].x, imsg.data[i].y, imsg.data[i].diameter, imsg.data)))
            
            if colour == "RED":
                colours[0] += 1
            elif colour == "BLUE":
                colours[1] += 1
            else:
                colours[2] += 1
                
        
           
           
    def calculate_angle(self, x, y, diameter, imsg):
        hfov_degrees = 62.2 
        delta_x = x
        angle_per_pixel = hfov_degrees / self.image_width 
        rotation_angle_degrees = delta_x * angle_per_pixel 
        rotation_angle_radians = math.radians(rotation_angle_degrees)
        self.logger.info(imsg)
        self.logger.info(str(math.degrees(rotation_angle_radians)) + ", " + str(rotation_angle_radians))
        return rotation_angle_radians
                
        
                          
                          

    

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

