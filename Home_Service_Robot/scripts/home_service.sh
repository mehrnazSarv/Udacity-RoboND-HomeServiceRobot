#!/bin/sh

catkin_ws="/home/workspace/catkin_ws"

xterm -e "cd ${catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 5


xterm -e "cd ${catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=${catkin_ws}/src/map/map.yaml" &

sleep 5


xterm -e "cd ${catkin_ws} && source devel/setup.bash && roslaunch add_markers home_service.launch rviz_path:=${catkin_ws}/src/rvizConfig/rvizConfig.rviz" &

sleep 5


xterm -e "cd ${catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers" &


xterm -e "cd ${catkin_ws} && source devel/setup.bash && rosrun pick_objects pick_objects" 
