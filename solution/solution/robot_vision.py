import sys
import time
import os
import rclpy
import math
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from assessment_interfaces.msg import ItemList
from auro_interfaces.srv import ItemRequest, Sector, Collision
from auro_interfaces.action import Move
import logging
from rclpy.action import ActionClient
from example_interfaces.srv import SetBool
from std_msgs.msg import String
from enum import Enum
from functools import partial


# Rotate count gets too high

class State(Enum):
    FINDING_TARGET = 1
    ALIGNED_WITH_TARGET = 2
    PICKING_UP_BALL = 3
    DROPPING_OFF_BALL = 4
    GOING_TO_ZONE = 5
    BUSY = 6
    FINDING_SECTOR = 7
    HEADING_TO_PREVIOUS = 8
    SPIN_CHECK = 9
    COLLISION_AVOIDANCE = 10
    BACKING_UP = 11

class RobotVision(Node):
    def __init__(self):
        super().__init__('robot_vision')
        
        self.declare_parameter("robot_name", "default")
        self.robot_name = self.get_parameter("robot_name").get_parameter_value().string_value

        self.logger = logging.getLogger('vision ' + self.robot_name)
        self.logger.setLevel(logging.DEBUG)
        current_directory = os.getcwd()
        log_file_path = os.path.join(current_directory, 'robot_vision' + self.robot_name + '.log')
        handler = logging.FileHandler(log_file_path)
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
        handler.setFormatter(formatter)
        self.logger.addHandler(handler)
        
        self.colour = None
        
        if self.robot_name == "robot1":
           self.colour = "BLUE"
        elif self.robot_name == "robot2":
           self.colour = "RED"
        elif self.robot_name == "robot3":
           self.colour = "GREEN"
        
        self.declare_parameter('x', 0.0)
        self.declare_parameter('y', 0.0)
        self.x = self.get_parameter('x').get_parameter_value().double_value
        self.y = self.get_parameter('y').get_parameter_value().double_value

        self.state = State.FINDING_TARGET
        self.ball_diameter = 0.075 * 2
        self.item_subscription = self.create_subscription(ItemList, 'items', self.control_loop, 1)
        self.robot_controller_publisher = self.create_publisher(String, "route", 10)
        self.rotate_client = self.create_client(SetBool, '/rotate_robot')
        self.pick_up_client = self.create_client(ItemRequest, '/pick_up_item')
        self.drop_off_client = self.create_client(ItemRequest, '/offload_item')
        self.move_client = ActionClient(self, Move, self.robot_name + '/move_robot')
        self.sector_client = self.create_client(Sector, '/sector_service')
        self.collision_client = self.create_client(Collision, '/collision_avoidance')
        
        self.start_time = self.get_clock().now()
        self.sector = None
        self.previous_ball = [None, None]
        
        self.rotate_count = 0
        self.largest_diameter = -1
        self.previous_state = None
        self.collected_balls = []
        self.collision_direction = None
        self.balls_collected = 0
        self.rotation_direction = None
        self.load_up_time = 10
        
        while not self.pick_up_client.wait_for_service(timeout_sec=1.0):
            #self.logger.info("Waiting for server")
            pass
            
        while not self.rotate_client.wait_for_service(timeout_sec=1.0):
            pass
            
        while not self.move_client.wait_for_server(timeout_sec=1.0):
            pass
        
        
    def rotate_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
                if self.rotation_direction == "left":
                   self.logger.info("rotate count: " + str(self.rotate_count))
                   self.rotate_count -= 1
                elif self.rotation_direction == "right":
                   self.logger.info("rotate count: " + str(self.rotate_count))
                   self.rotate_count += 1
                
                self.rotation_direction = None
                
        except Exception as e:
            self.logger.info(e)
            pass
        finally:
            if self.state == State.PICKING_UP_BALL:
               self.state = State.FINDING_SECTOR
            elif self.previous_state == State.SPIN_CHECK:
               self.state = State.FINDING_TARGET
            else:
               self.state = State.FINDING_TARGET
            
        
            
    def pick_up_callback(self, future):
        try:
            response = future.result()
            
            if response.success:
               if self.previous_state == State.PICKING_UP_BALL:
                    self.balls_collected += 1
                    self.state = State.COLLISION_AVOIDANCE
            else:
               self.state = State.FINDING_TARGET
               
        except Exception as e:
            self.logger.info(e)

    
    def calculate_position(self, s_x, s_y, angle, distance):
        new_x = s_x + distance * math.cos(angle)
        new_y = s_y + distance * math.sin(angle)
        
        return new_x, new_y
        
    
    def calculate_distance(self, perceived_diameter):
        return (self.ball_diameter * 530.4)/perceived_diameter + 0.25
    
        
    def is_ball_collected(self, x, y):
        for item in self.collected_balls:
            collected_x = item[0]
            collected_y = item[1]
            
            if abs(collected_x - x)  <= 0.25 and abs(collected_y - y) <= 0.25:
                return True
        return False
        
        
            
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
            self.state = State.HEADING_TO_PREVIOUS

    def goal_response_callback(self, future): 
        goal_handle = future.result() 
        if not goal_handle.accepted: 
            self.logger.info('Goal rejected') 
            return 
            
        self.get_logger().info('Goal accepted') 
        self._get_result_future = goal_handle.get_result_async() 
        self._get_result_future.add_done_callback(self.get_result_callback)
        
    def feedback_callback(self, feedback_msg): 
        self.logger.info(f'Feedback: {feedback_msg.feedback.progress}')
        
    def get_result_callback(self, future): 
        result = future.result().result 
        self.logger.info(f'Result: {result.status}')
        
        self.logger.info(self.state.name)
        
        if self.previous_state == State.ALIGNED_WITH_TARGET:
           self.state = State.PICKING_UP_BALL
        elif self.previous_state == State.GOING_TO_ZONE:
           self.state = State.DROPPING_OFF_BALL
        elif self.previous_state == State.DROPPING_OFF_BALL:
           self.state = State.HEADING_TO_PREVIOUS
        elif self.previous_state == State.HEADING_TO_PREVIOUS:
           self.state = State.FINDING_TARGET
        elif self.previous_state == State.BACKING_UP:
           self.state = State.GOING_TO_ZONE
    
    
    def collision_callback(self, future):
        result = future.result()

        if result.success:
           self.collision_direction = result.direction
           self.state = State.BACKING_UP
        else:
           self.previous_ball[0] = self.x
           self.previous_ball[1] = self.y
           self.state = State.GOING_TO_ZONE
          
           
    def sector_service_callback(self, future):
        result = future.result()
        goal = [result.x, result.y]
        self.sector = goal
        self.state = State.GOING_TO_ZONE
    
    def set_to_busy(self, previous_state):
        self.state = State.BUSY
        self.previous_state = previous_state
        
    def control_loop(self, msg):
        data = msg.data
        self.logger.info(data)
        
        match self.state:
        
            case State.FINDING_TARGET:
                if (self.get_clock().now() - self.start_time).nanoseconds / 10e9 < self.load_up_time:
                     return
                
                self.set_to_busy(State.FINDING_TARGET)
                data = msg.data
                largest_diameter = -1
                closest_x = None
                
                for i in range(len(data)):
                    colour = data[i].colour
                    diameter = data[i].diameter
                    x = data[i].x
                    
                    
                    distance = self.calculate_distance(diameter)
                    theta = math.radians(self.rotate_count/2)
                    calculated_x, calculated_y = self.calculate_position(self.x, self.y, theta, distance)
                    
                    if colour != self.colour or self.is_ball_collected(calculated_x, calculated_y):
                        self.logger.info("Same ball")
                        continue
                        
                    if diameter > largest_diameter:
                        largest_diameter = diameter
                        closest_x = x
                
                self.largest_diameter = largest_diameter
                
                if largest_diameter == -1:
                    self.state = State.SPIN_CHECK

                if closest_x:
                    if abs(closest_x) >= 12:
                        # Right is true, left is false
                        request = SetBool.Request()
                        
                        if closest_x < 0:
                           self.rotation_direction = "left"
                           request.data = False
                        else:
                           self.rotation_direction = "right"
                           request.data = True
                           
                        future = self.rotate_client.call_async(request)
                        future.add_done_callback(self.rotate_callback)
                    else:
                        self.state = State.ALIGNED_WITH_TARGET
                    
                    
                
                
            case State.ALIGNED_WITH_TARGET:
                self.set_to_busy(State.ALIGNED_WITH_TARGET)
                distance = self.calculate_distance(self.largest_diameter)
                angle = math.radians(self.rotate_count/2)
                self.rotate_count = 0
                
                new_x, new_y = self.calculate_position(self.x, self.y, angle, distance)
                self.x = new_x
                self.y = new_y
                
                self.logger.info(new_x)
                self.logger.info(new_y)
                
                msg = Move.Goal()
                msg.x = new_x
                msg.y = new_y
                msg.angle = 0.0
                self._send_goal_future = self.move_client.send_goal_async(msg, feedback_callback=self.feedback_callback)
                self._send_goal_future.add_done_callback(self.goal_response_callback)

               
            case State.PICKING_UP_BALL:
                self.set_to_busy(State.PICKING_UP_BALL)
                request = ItemRequest.Request()
                request.robot_id = self.robot_name
                self.collected_balls.append([self.x, self.y])
                future = self.pick_up_client.call_async(request)
                future.add_done_callback(partial(self.pick_up_callback))
            
            case State.COLLISION_AVOIDANCE:
                self.set_to_busy(State.COLLISION_AVOIDANCE)
                request = Collision.Request()
                
                future = self.collision_client.call_async(request)
                future.add_done_callback(self.collision_callback)
                
            case State.BACKING_UP:
                self.set_to_busy(State.BACKING_UP)
                angle = None
                
                if self.collision_direction == "FRONT":
                    angle = 180
                elif self.collision_direction == "BACK":
                    angle = 0
                elif self.collision_direction == "LEFT":
                    angle = 90
                elif self.collision_direction == "RIGHT":
                    angle = -90
                
                new_x, new_y = self.calculate_position(self.x, self.y, angle, 1)
                self.x = new_x
                self.y = new_y
                msg = Move.Goal()
                msg.angle = 0.0
                msg.x = new_x
                msg.y = new_y
                
                self.collision_direction = None
                self._send_goal_future = self.move_client.send_goal_async(msg, feedback_callback=self.feedback_callback)
                self._send_goal_future.add_done_callback(self.goal_response_callback)
  
                            
            case State.GOING_TO_ZONE:
                self.set_to_busy(State.GOING_TO_ZONE)
                if self.sector == None:
                   request = Sector.Request()
                   request.x = self.x
                   request.y = self.y
                   future = self.sector_client.call_async(request)
                   future.add_done_callback(self.sector_service_callback)
                else:
                   self.x = self.sector[0]
                   self.y = self.sector[1]
                
                   msg = Move.Goal()
                   msg.x = self.sector[0]
                   msg.y = self.sector[1]
                   msg.angle = 0.0
                   self._send_goal_future = self.move_client.send_goal_async(msg, feedback_callback=self.feedback_callback)
                   self._send_goal_future.add_done_callback(self.goal_response_callback)
                
                
            case State.DROPPING_OFF_BALL:
                self.set_to_busy(State.DROPPING_OFF_BALL)
                request = ItemRequest.Request()
                request.robot_id = self.robot_name
                future = self.drop_off_client.call_async(request)
                future.add_done_callback(partial(self.drop_off_callback))
                
                
            case State.HEADING_TO_PREVIOUS:
                self.set_to_busy(State.HEADING_TO_PREVIOUS)
                self.x = self.previous_ball[0]
                self.y = self.previous_ball[1]
                
                msg = Move.Goal()
                
                msg.x = float(self.x)
                msg.y = float(self.y)
                msg.angle = 0.0
                self._send_goal_future = self.move_client.send_goal_async(msg, feedback_callback=self.feedback_callback)
                self._send_goal_future.add_done_callback(self.goal_response_callback)
     
            case State.SPIN_CHECK:
                self.set_to_busy(State.SPIN_CHECK)
                request = SetBool.Request()
                self.rotation_direction = "right"
                request.data = True
                
                future = self.rotate_client.call_async(request)
                future.add_done_callback(self.rotate_callback)
                
                
                
                
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

