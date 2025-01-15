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
        self.declare_parameter("num_robots", 1)
        
        
        self.x = self.get_parameter('x').get_parameter_value().double_value
        self.y = self.get_parameter('y').get_parameter_value().double_value
        self.yaw = self.get_parameter('yaw').get_parameter_value().double_value
        self.robot_name = self.get_parameter("robot_name").get_parameter_value().string_value
        self.num_robots = self.get_parameter("num_robots").get_parameter_value().integer_value
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        # Setting colours that robots are meant to collect
        if self.num_robots == 1:
           self.colour = "any"
        else:
           if self.robot_name == "robot1":
             self.colour = "BLUE"
           elif self.robot_name == "robot2":
             self.colour = "RED"
           elif self.robot_name == "robot3":
             self.colour = "GREEN"
        
        
        self.control_loop_rate = 1/10
        # Assigned zone that robot is to drop ball in
        self.zone = None
        self.previous_state = None
        self.state = State.IDLE
        # X component of point that robot will move to in random walk
        self.random_walk_x = None
        # Y component of random walk
        self.random_walk_y = None
        # Diameter of ball that 
        self.diameter = None
        self.ball_diameter = 0.075*2
        self.collected_balls = []
        self.balls_collected = 0
        self.previous_ball = [None, None]
        self.current_ball_colour = None

        # Client to access robot controller
        self.move_client = ActionClient(self, Move, self.robot_name + '/move_robot')
        self.odom_subscriber = self.create_subscription(Odometry, '/' + self.robot_name + '/odom', self.odom_callback, 10)
        # Service to check costmap in 
        self.check_costmap_client = self.create_client(CheckGoal, '/check_goal')
        # Service to access navigation
        self.task_service = self.create_service(Task, '/request_service', self.service_task)
        self.pick_up_client = self.create_client(ItemRequest, '/pick_up_item')
        self.drop_off_client = self.create_client(ItemRequest, '/offload_item')
        # Service to access robot_vision
        self.navigation_service = self.create_service(Task, '/'+ self.robot_name + '/navigate', self.service_task)
        # Client to access robot_vision
        self.vision_client = self.create_client(FindTarget, '/'+ self.robot_name +'/find_target')
        # Client to check for collision
        self.collision_client = self.create_client(Collision, '/collision_avoidance')
        # Request zone to drop off ball
        self.zone_client = self.create_client(ZoneRequest, '/zone_service')
        
        
        self.create_timer(self.control_loop_rate, self.control_loop)
    
    
    def set_to_busy(self, state):
       self.state = State.BUSY
       self.previous_state = state
    
    # Kick navigation into motion from robot_vision request
    def service_task(self, request, response):
        move_to_target = request.move_to_target
        diameter = request.diameter
        self.current_ball_colour = request.colour
        
        if self.state == State.IDLE:
           if move_to_target:
              self.diameter = diameter
              self.state = State.GO_TO_TARGET
           else:
              self.state = State.REQUEST_RANDOM_WALK
              
           response.success = True
        else:
           response.success = False
        
        #self.logger.info("Starting: " + self.state.name)
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
        #self.logger.info("goal")
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
           #self.logger.info('Goal rejected') 
           return 
            
        self.get_logger().info('Goal accepted') 
        self._get_result_future = goal_handle.get_result_async() 
        self._get_result_future.add_done_callback(self.move_result_callback)
       
    def find_target_callback(self, future):
        result = future.result()
        
        if result.success:
           #self.logger.info("Started finding target")
           pass
        else:
           #self.logger.info("There was an error finding target")
           pass
        
       
    # Callback from movement request
    def move_result_callback(self, future):
       result = future.result().result
       #self.logger.info('Result:  ' + result.status)
    
       if result.status == "Target Reached":
           if self.previous_state == State.GO_TO_TARGET:
               self.state = State.PICK_UP_BALL
           elif self.previous_state == State.GO_TO_ZONE:
               #self.logger.info("Here")
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
       
       # check for collision
       if result.success:
           # avoid collision
           self.collision_direction = result.direction
           self.state = State.AVOID_COLLISION
       else:
           self.previous_ball[0] = self.x
           self.previous_ball[1] = self.y
           self.state = State.GO_TO_ZONE
           
           
    def move_feedback_callback(self, feedback_msg): 
           #self.logger.info('Feedback: ' + feedback_msg.feedback.progress)
           pass
           
           
    def send_movement_goal(self, x, y):
         msg = Move.Goal()
         msg.x = x
         msg.y = y
         msg.angle = 0.0
         self._send_goal_future = self.move_client.send_goal_async(msg, feedback_callback=self.move_feedback_callback)
         self._send_goal_future.add_done_callback(self.move_response_callback)
    
    # Send request to robot_vision
    def send_find_target_request(self):
        request = FindTarget.Request()
        future = self.vision_client.call_async(request)
        future.add_done_callback(self.find_target_callback)
        
    
    def calculate_position(self, distance, angle):
         new_x = self.x + distance * math.cos(angle)
         new_y = self.y + distance * math.sin(angle)
         return new_x, new_y
         
    def calculate_distance(self, perceived_diameter):
        #self.logger.info((self.ball_diameter * 530.4)/perceived_diameter + 0.25)
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
            #self.logger.info(e)
            pass
    
    
    def drop_off_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
               #self.logger.info("dropped off")
               pass
            else:
               #self.logger.info("Didn't drop off")
               pass
        except Exception as e:
            #self.logger.info(e)
            pass
        finally:
            self.state = State.HEAD_TO_PREVIOUS_BALL
            

    def control_loop(self):
    
        try: # Updating x, y position
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
                #self.logger.info("going to zone")
                self.set_to_busy(State.GO_TO_ZONE)
                if self.zone == None:
                   request = ZoneRequest.Request()
                   request.x = self.x
                   request.y = self.y
                   request.colour = self.current_ball_colour
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
           
           # Detects where robot is closest to obstacle and 
           # moves in opposite direction
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
                
           # Move to random point which is not an obstacle in the cost map 
           case State.REQUEST_RANDOM_WALK:
                self.set_to_busy(State.REQUEST_RANDOM_WALK)
                
                if self.colour == "any":
                   rand_x = random.uniform(-2, 2)
                   rand_y = random.uniform(-2.2, 2)  
                elif self.colour == "GREEN":
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
                if self.num_robots == 1:
                   self.zone = None
                
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

