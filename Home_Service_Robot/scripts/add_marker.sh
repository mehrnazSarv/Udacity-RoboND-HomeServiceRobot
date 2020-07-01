#!/bin/sh
catkin_ws="/home/workspace/catkin_ws"


xterm -e "cd ${catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 5

xterm -e "cd ${catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${catkin_ws}/src/map/map.yaml" &

sleep 5

xterm -e "cd ${catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 5


xterm -e "cd ${catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers" 
