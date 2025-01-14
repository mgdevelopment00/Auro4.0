import sys
import time
import math
import rclpy
import logging
import os
import random

from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from auro_interfaces.srv import ZoneRequest, Task, Collision, ItemRequest, Task, FindTarget, CheckGoal
from std_msgs.msg import String
from enum import Enum
from auro_interfaces.action import Move
from rclpy.action import ActionClient
from nav_msgs.msg import Odometry
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener



class State(Enum):
    IDLE = 1
    BUSY = 2
    GO_TO_TARGET =3
    GO_TO_ZONE = 4
    HEAD_TO_PREVIOUS_BALL = 5
    AVOID_COLLISION = 6
    REQUEST_RANDOM_WALK = 7
    ON_RANDOM_WALK = 8
    DETECT_COLLISION = 9
    PICK_UP_BALL = 10
    DROP_OFF_BALL = 11

class Navigation(Node):
    def __init__(self):
        super().__init__('navigation')
        self.declare_parameter('x', 0.0)
        self.declare_parameter('y', 0.0)
        self.declare_parameter('yaw', 0.0)
        self.declare_parameter("robot_name", "default")
        
        
        self.x = self.get_parameter('x').get_parameter_value().double_value
        self.y = self.get_parameter('y').get_parameter_value().double_value
        self.yaw = self.get_parameter('yaw').get_parameter_value().double_value
        self.robot_name = self.get_parameter("robot_name").get_parameter_value().string_value
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        if self.robot_name == "robot1":
           self.colour = "GREEN"
        elif self.robot_name == "robot2":
           self.colour = "RED"
        elif self.robot_name == "robot3":
           self.colour = "GREEN"
        
        self.control_loop_rate = 1/10
        self.zone = None
        self.previous_state = None
        self.state = State.IDLE
        self.random_walk_x = None
        self.random_walk_y = None
        self.diameter = None
        self.ball_diameter = 0.075*2
        self.collected_balls = []
        self.balls_collected = 0
        self.previous_ball = [None, None]

        self.logger = logging.getLogger('navigation ' + self.robot_name)
        self.logger.setLevel(logging.DEBUG)
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'navigation' + self.robot_name + '.log')
        handler = logging.FileHandler(log_file_path)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)

        self.move_client = ActionClient(self, Move, self.robot_name + '/move_robot')
        self.odom_subscriber = self.create_subscription(Odometry, '/' + self.robot_name + '/odom', self.odom_callback, 10)
        self.check_costmap_client = self.create_client(CheckGoal, '/check_goal')
        self.task_service = self.create_service(Task, '/request_service', self.service_task)
        self.manager_client = self.create_client(ZoneRequest, '/zone_service')
        self.pick_up_client = self.create_client(ItemRequest, '/pick_up_item')
        self.drop_off_client = self.create_client(ItemRequest, '/offload_item')
        self.navigation_service = self.create_service(Task, '/navigate', self.service_task)
        self.vision_client = self.create_client(FindTarget, '/find_target')
        self.collision_client = self.create_client(Collision, '/collision_avoidance')
        self.zone_client = self.create_client(ZoneRequest, '/zone_service')
        
        
        self.create_timer(self.control_loop_rate, self.control_loop)
    
    
    def set_to_busy(self, state):
       self.state = State.BUSY
       self.previous_state = state
    
    
    def service_task(self, request, response):
        move_to_target = request.move_to_target
        diameter = request.diameter
        
        if self.state == State.IDLE:
           if move_to_target:
              self.diameter = diameter
              self.state = State.GO_TO_TARGET
           else:
              self.state = State.REQUEST_RANDOM_WALK
              
           response.success = True
        else:
           response.success = False
        
        self.logger.info("Starting: " + self.state.name)
        return response
         
           
        
    def odom_callback(self, msg):
        self.pose = msg.pose.pose
        x = self.pose.orientation.x
        y = self.pose.orientation.y
        z = self.pose.orientation.z
        w = self.pose.orientation.w
        self.yaw = math.atan2(2*(y*x+w*z),w**2+x**2-y**2-z**2)

        
    def zone_service_callback(self, future):
        result = future.result()
        goal = [result.x, result.y]
        self.zone = goal
        self.state = State.GO_TO_ZONE   
        
    
    def random_walk_callback(self, future):
        result = future.result()
        
        if result.obstacle:
            # There is an obstacle in the way
            self.state = State.REQUEST_RANDOM_WALK
        else:
            self.state = State.ON_RANDOM_WALK
    
    
    def move_response_callback(self, future): 
        goal_handle = future.result() 
        
        if not goal_handle.accepted: 
           self.logger.info('Goal rejected') 
           return 
            
        self.get_logger().info('Goal accepted') 
        self._get_result_future = goal_handle.get_result_async() 
        self._get_result_future.add_done_callback(self.move_result_callback)
       
    def find_target_callback(self, future):
        result = future.result()
        
        if result.success:
           self.logger.info("Started finding target")
        else:
           self.logger.info("There was an error finding target")
        
       
       
    def move_result_callback(self, future):
       result = future.result().result
       self.logger.info(f'Result: {result.status}')
    
       if result.status == "Target Reached":
           if self.previous_state == State.GO_TO_TARGET:
               self.state = State.PICK_UP_BALL
           elif self.previous_state == State.GO_TO_ZONE:
               self.state = State.DROP_OFF_BALL
           elif self.previous_state == State.DROP_OFF_BALL:
               self.state = State.HEAD_TO_PREVIOUS_BALL
           elif self.previous_state == State.HEAD_TO_PREVIOUS_BALL:
               self.send_find_target_request()
               self.state = State.IDLE
           elif self.previous_state == State.AVOID_COLLISION:
               self.state = State.GO_TO_ZONE
           elif self.previous_state == State.ON_RANDOM_WALK:
               self.send_find_target_request()
               self.state = State.IDLE
       elif result.status == "Target Aborted":
           self.state = State.COLLISION_AVOIDANCE
           
      
    def collision_callback(self, future):
       result = future.result()
       if self.previous_ball[0] == None:
           self.previous_ball[0] = self.x
           self.previous_ball[1] = self.y

       if result.success:
           self.collision_direction = result.direction
           self.state = State.AVOID_COLLISION
       else:
           self.previous_ball[0] = self.x
           self.previous_ball[1] = self.y
           self.state = State.GO_TO_ZONE
           
           
    def move_feedback_callback(self, feedback_msg): 
           self.logger.info(f'Feedback: {feedback_msg.feedback.progress}')
           
           
    def send_movement_goal(self, x, y):
         msg = Move.Goal()
         msg.x = x
         msg.y = y
         msg.angle = 0.0
         self._send_goal_future = self.move_client.send_goal_async(msg, feedback_callback=self.move_feedback_callback)
         self._send_goal_future.add_done_callback(self.move_response_callback)
         
    def send_find_target_request(self):
        request = FindTarget.Request()
        future = self.vision_client.call_async(request)
        future.add_done_callback(self.find_target_callback)
        
    
    def calculate_position(self, distance, angle):
         new_x = self.x + distance * math.cos(angle)
         new_y = self.y + distance * math.sin(angle)
         return new_x, new_y
         
    def calculate_distance(self, perceived_diameter):
        self.logger.info((self.ball_diameter * 530.4)/perceived_diameter + 0.25)
        return (self.ball_diameter * 530.4)/perceived_diameter + 0.35
        
        
    def pick_up_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
               if self.previous_state == State.PICK_UP_BALL:
                    self.balls_collected += 1
                    self.state = State.DETECT_COLLISION
            else:
               self.send_find_target_request()
               self.state = State.IDLE
               
        except Exception as e:
            self.logger.info(e)
    
    
    def drop_off_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
               self.logger.info("dropped off")
            else:
               self.logger.info("Didn't drop off")
        except Exception as e:
            self.logger.info(e)
        finally:
            self.state = State.HEAD_TO_PREVIOUS_BALL
            

    def control_loop(self):
    
        try:
            t = self.tf_buffer.lookup_transform(
                'map',
                'base_footprint',
                rclpy.time.Time())
            
            self.x = t.transform.translation.x
            self.y = t.transform.translation.y
        except TransformException as e:
            self.get_logger().info(f"{e}")
        
        match self.state:
        
           case State.GO_TO_TARGET:
                self.set_to_busy(State.GO_TO_TARGET)
                distance = self.calculate_distance(self.diameter)
                new_x, new_y = self.calculate_position(distance, self.yaw)
                self.send_movement_goal(new_x, new_y)
           
           case State.GO_TO_ZONE:
                self.set_to_busy(State.GO_TO_ZONE)
                if self.zone == None:
                   request = ZoneRequest.Request()
                   request.x = self.x
                   request.y = self.y
                   future = self.zone_client.call_async(request)
                   future.add_done_callback(self.zone_service_callback)
                else:
                   self.send_movement_goal(self.zone[0], self.zone[1])
                   
                   
           case State.HEAD_TO_PREVIOUS_BALL:
                self.set_to_busy(State.HEAD_TO_PREVIOUS_BALL)
                self.send_movement_goal(self.previous_ball[0], self.previous_ball[1])
           
           
           case State.DETECT_COLLISION:
                self.set_to_busy(State.DETECT_COLLISION)
                request = Collision.Request()
                
                future = self.collision_client.call_async(request)
                future.add_done_callback(self.collision_callback)
           
           case State.AVOID_COLLISION:
                self.set_to_busy(State.AVOID_COLLISION)
                angle = None
                
                if self.collision_direction == "FRONT":
                    angle = 180
                elif self.collision_direction == "BACK":
                    angle = 0
                elif self.collision_direction == "LEFT":
                    angle = 90
                elif self.collision_direction == "RIGHT":
                    angle = -90
                
                new_x, new_y = self.calculate_position(0.75, angle)
                self.collision_direction = None
                self.send_movement_goal(new_x, new_y)
                
                
           case State.REQUEST_RANDOM_WALK:
                self.set_to_busy(State.REQUEST_RANDOM_WALK)
                
                if self.colour == "GREEN":
                   rand_x = random.uniform(0, 2.2)
                   rand_y = random.uniform(0, -2)
                elif self.colour == "RED":
                   rand_x = random.uniform(-2.2, 2)
                   rand_y = random.uniform(0, -3.2)

                elif self.colour == "BLUE":
                   rand_x = random.uniform(0, 2.2)
                   rand_y = random.uniform(0, 2)
                
                request = CheckGoal.Request()
                request.x = rand_x
                request.y = rand_y
                self.random_walk_x = rand_x
                self.random_walk_y = rand_y
                future = self.check_costmap_client.call_async(request)
                future.add_done_callback(self.random_walk_callback)
           
           
           case State.ON_RANDOM_WALK:
                self.set_to_busy(State.ON_RANDOM_WALK)
                self.send_movement_goal(self.random_walk_x, self.random_walk_y)
           
           
           case State.PICK_UP_BALL:
                self.set_to_busy(State.PICK_UP_BALL)
                request = ItemRequest.Request()
                request.robot_id = self.robot_name
                self.collected_balls.append([self.x, self.y])
                future = self.pick_up_client.call_async(request)
                future.add_done_callback(self.pick_up_callback)
                
           case State.DROP_OFF_BALL:
                self.set_to_busy(State.DROP_OFF_BALL)
                request = ItemRequest.Request()
                request.robot_id = self.robot_name
                future = self.drop_off_client.call_async(request)
                future.add_done_callback(self.drop_off_callback)
           

def main(args=None):
    rclpy.init(args=args)

    node = Navigation()

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

