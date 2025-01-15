In this project there are a total of 5 simulation  scenarios. Once you have cd-ed into your 
ros2 project you can open a terminal to build and install.

Scenario 1
----------

This is the pre-defined scenario with 3 robots. To run this type the following line into the command line:

ros2 launch solution solution_nav2_launch.py num_robots:=3

with the num_robots:=3 setting the number of robots in the simulation to 3


Scenario 2
----------

This scenario runs 1 robot which picks up all of the colours unlike the 3 robot scenario where
each robot picks up one colour ball. To run this type the following line into the command line:

ros2 launch solution solution_nav2_launch.py num_robots:=1

with the num_robots:=1 setting the number of robots in the simulation to 1


Scenario 3
---------

This scenario adds sensor noise to the 3 robot simulation. To run this you will need to go into the
launch file "solution_nav2_launch.py" which will be in the "launch" folder. From there you will need
to scroll down to line 124 where it says "sensor_noise" : "false" and you will have to change this to:

"sensor_noise": "true"

After doing so, you will have to re-build and re-install the solution in the terminal and then run:

ros2 launch solution solution_nav2_launch.py num_robots:=3


Scenario 4
---------

This scenario removes obstacles in the robot simulation. To run this you will need to into the launch file 
"solution_nav2_launch.py" which will be in the "launch" folder. From there you will need to scroll down to line 
128 where it says "obstacles": "true" and you will have to change this to:

"obstacles": "false"

After doing so, you will have to re-build and re-install the solution in the terminal and then run:

ros2 launch solution solution_nav2_launch.py num_robots:=3


Scenario 5
--------

This scenario generates a random  seed for the distribution of the balls within the map. To run this type the following line into the command line:

ros2 launch solution solution_nav2_launch.py num_robots:=3 random_seed:=x (where x is an integer of your choosing)




