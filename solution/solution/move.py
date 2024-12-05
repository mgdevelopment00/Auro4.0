import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import logging
import os

class MoveRobot(Node):
    def __init__(self, speed=0.5):  # Speed is now a parameter
        super().__init__('move')
        
        # Set up logger to write to a file in the same directory
        log_dir = os.path.dirname(os.path.abspath(__file__))  # Get the current directory
        log_file = os.path.join(log_dir, 'data_logger.log')
        
        logging.basicConfig(
            filename=log_file,
            level=logging.INFO,
            format='%(asctime)s - %(message)s'
        )
        self.logger = logging.getLogger()

        # Create the publisher and timer
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.move_forward)  # Publish at 10 Hz
        
        # Command to move forward
        self.cmd = Twist()
        self.speed = speed  # Set the speed of the robot
        self.cmd.linear.x = self.speed  # Set the speed for forward movement
        self.cmd.angular.z = 0.0  # No rotation
        
        # Log that the robot is ready to move
        self.logger.info(f'Robot initialized and moving forward continuously at speed {self.speed} m/s.')

    def move_forward(self):
        # Publish the movement command to move forward at the set speed
        self.publisher.publish(self.cmd)
        self.logger.info(f'Moving forward at {self.speed} m/s.')

def main(args=None):
    rclpy.init(args=args)

    # You can modify the speed here when instantiating the node
    speed = 0.2  # Example: setting the speed to 0.2 m/s
    move = MoveRobot(speed=speed)

    try:
        # Keep the robot moving continuously
        rclpy.spin(move)
    except KeyboardInterrupt:
        pass

    move.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

