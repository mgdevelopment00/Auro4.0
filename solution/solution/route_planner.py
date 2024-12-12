import sys
import time

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException

from std_msgs.msg import String

from enum import Enum

class State(Enum):
    NOT_SENT = 0
    SENT = 1

class RoutePlanner(Node):
    def __init__(self):
        super().__init__('route_planner')

        # Create Publisher
        self.state = State.NOT_SENT
        self.publisher = self.create_publisher(String, "route", 10)

        while self.publisher.get_subscription_count() == 0:
            self.get_logger().info(f"waiting")
            time.sleep(1)

        self.timer = self.create_timer(1.0, self.timer_loop)

    def timer_loop(self):
        match self.state:
            case State.NOT_SENT:
                self.get_logger().info(f"sending stuff")
                msg = String()
                msg.data = "3.0, 2.0, 1.0"  # in (x, y, w) form
                self.publisher.publish(msg)
                self.state = State.SENT
            case _:
                pass

def main(args=None):
    rclpy.init(args=args)

    node = RoutePlanner()

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

