import sys
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
from enum import Enum

class State(Enum):
    SET_GOAL = 0
    NAVIGATING = 1


class RobotController(Node):

    def __init__(self):
        super().__init__('robot_controller')

        self.state = State.SET_GOAL
        self.navigator = BasicNavigator()
        self.declare_parameter('x', 0.0)
        self.declare_parameter('y', 0.0)
        # Might use later on
        self.declare_parameter('yaw', 0.0)
        self.initial_x = self.get_parameter('x').get_parameter_value().double_value
        self.initial_y = self.get_parameter('y').get_parameter_value().double_value
        self.initial_yaw = self.get_parameter('yaw').get_parameter_value().double_value

        initial_pose = PoseStamped()
        initial_pose.header.frame_id = 'map'
        initial_pose.header.stamp = self.get_clock().now().to_msg()
        initial_pose.pose.position.x = self.initial_x
        initial_pose.pose.position.y = self.initial_y
        initial_pose.pose.orientation.z = 0.0
        initial_pose.pose.orientation.w = 1.0

        self.navigator.setInitialPose(initial_pose)
        self.navigator.waitUntilNav2Active()

        self.subscription = self.create_subscription(String, 'route', self.route_detected, 10)

    def route_detected(self, msg):
        data = msg.data.split(",")
        try:
            x = float(data[0])  # Convert to float
            y = float(data[1])  # Convert to float
            w = float(data[2])  # Assuming 'w' is the scalar part of a quaternion
        except ValueError:
            self.get_logger().error(f"Invalid data received: {msg.data}")
            return

        # Log the goal pose to make sure values are correct
        self.get_logger().info(f"Received goal: x={x}, y={y}, w={w}")

        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = self.get_clock().now().to_msg()
        goal_pose.pose.position.x = x
        goal_pose.pose.position.y = y
        goal_pose.pose.orientation.w = w  # Only using 'w' for the orientation scalar

        self.navigator.goToPose(goal_pose)
        self.state = State.NAVIGATING

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

