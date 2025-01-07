import sys
import rclpy
import math
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped, Quaternion, Twist
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from example_interfaces.srv import SetBool
from rclpy.action import ActionServer, GoalResponse
from auro_interfaces.action import Move
from enum import Enum
import logging
import os
import time
from builtin_interfaces.msg import Time

class State(Enum):
    SET_GOAL = 0
    NAVIGATING = 1
    AT_TARGET = 2
    BUSY = 3

class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        self.state = State.SET_GOAL
        self.navigator = BasicNavigator()
        self.declare_parameter('x', 0.0)
        self.declare_parameter('y', 0.0)
        self.declare_parameter('yaw', 0.0)  # Initial Yaw might be used later
        
        self.logger = logging.getLogger('controller') 
        self.logger.setLevel(logging.DEBUG)  
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'robot_controller.log') 
        handler = logging.FileHandler(log_file_path) 
        handler.setLevel(logging.DEBUG) 
        formatter = logging.Formatter('')  # Configure the formatter
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)  # Make sure to add the handler to the logger
        
        self.initial_x = self.get_parameter('x').get_parameter_value().double_value
        self.initial_y = self.get_parameter('y').get_parameter_value().double_value
        self.initial_yaw = self.get_parameter('yaw').get_parameter_value().double_value
        self.rotating = False

        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = self.initial_x
        initial_pose.pose.position.y = self.initial_y
        initial_pose.pose.orientation = self.calculate_quaternion(self.initial_yaw)

        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()
        self.rotation_time = 0.1  # Time to rotate (in seconds)
        self.angular_speed = 0.174/2 # Angular speed for rotation
        self.goal_reached = False

        self.create_subscription(String, 'route', self.route_detected, 10)
        self.twist_publisher = self.create_publisher(Twist, 'cmd_vel', 1)
        self.rotate_service = self.create_service(SetBool, 'robot1/rotate_robot', self.service_rotate)
        self.move_action_server = ActionServer(self, Move, 'robot1/move_robot', self.move_callback)
    
    def goal_callback(self, goal_request):
         if self.state != State.BUSY:
            return GoalResponse.ACCEPT
         else:
            return GoalResponse.REJECT
    
    
    def move_callback(self, goal_handle):
         if not self.state == State.BUSY:
            self.state = State.BUSY
            target_x = goal_handle.request.x
            target_y = goal_handle.request.y
            target_angle = goal_handle.request.angle
         
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = target_x
            goal_pose.pose.position.y = target_y
            goal_pose.pose.orientation = self.calculate_quaternion(target_angle)

            self.navigator.goToPose(goal_pose)
            self.state = State.NAVIGATING
            self.goal_handle = goal_handle
         
            result_msg = Move.Result()
            result_msg.status = "Executing"
            goal_reached = False
         
            self.move_timer = self.create_timer(2, self.get_updates)
         
            while not self.navigator.isTaskComplete():
                pass
         
            self.move_timer.cancel()
            result = self.navigator.getResult()
         
            if result == TaskResult.SUCCEEDED:
                result_msg.status = "Target Reached"
                self.goal_handle.succeed()
            else:
                result_msg.status = "Target not Reached"
                self.goal_handle.abort()
         
         
            return result_msg
         return -1
         

    def get_updates(self):
         feedback = self.navigator.getFeedback()
         feedback_msg = Move.Feedback()
         if feedback:
             current_position = feedback.current_pose.pose.position
             feedback_msg.progress = f'Current position: ({current_position.x}, {current_position.y}, {current_position.z})'
             self.goal_handle.publish_feedback(feedback_msg)
             self.logger.info(f'Feedback: {feedback_msg.progress}')
               
    
    def route_detected(self, msg):
        data = msg.data.split(",")
        try:
            if data[0][0] == "p":  # Move to point command
                self.x = float(data[1])
                self.y = float(data[2])
                self.w = float(data[3])
                self.a = float(data[4])
            elif data[0][0] == "f":  # Forward command
                pass
        except ValueError:
            self.get_logger().error(f"Invalid data received: {msg.data}")
            return
            
        if data[0] == "p":
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = self.x
            goal_pose.pose.position.y = self.y
            goal_pose.pose.orientation = self.calculate_quaternion(self.a)

            self.navigator.goToPose(goal_pose)
            self.state = State.NAVIGATING
            
 
                  
            
    def start_rotation_right(self):
         new_twist = Twist()
         new_twist.linear.x = 0.0
         new_twist.angular.z = self.angular_speed
         self.twist_publisher.publish(new_twist)    
    
         
    def start_rotation_left(self):
         self.logger.info("Rotating once")
         new_twist = Twist()
         new_twist.linear.x = 0.0
         new_twist.angular.z = -self.angular_speed
         self.twist_publisher.publish(new_twist)

    def stop_rotation(self):
        new_twist = Twist()
        new_twist.linear.x = 0.0
        new_twist.angular.z = 0.0
        self.twist_publisher.publish(new_twist)
        self.rotating = False
        self.rotation_timer.cancel()

    def service_rotate(self, request, response):
    
        if not self.rotating:
            self.rotating = True
            direction = request.data
            
            if direction == True:
               self.start_rotation_right()
            else:
               self.start_rotation_left()
            
            
            self.rotation_timer = self.create_timer(self.rotation_time, self.stop_rotation)

            response.success = True
        else:
            response.success = False
        return response

    def calculate_quaternion(self, angle_degrees):
        angle_radians = math.radians(angle_degrees)
        quaternion = Quaternion()
        quaternion.w = math.cos(angle_radians / 2)
        quaternion.x = 0.0
        quaternion.y = 0.0
        quaternion.z = math.sin(angle_radians / 2)
        return quaternion

    def destroy_node(self):
        self.get_logger().info(f"Shutting down")
        self.navigator.lifecycleShutdown()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = RobotController()

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


                




