# Home Service Robot Project
This is the final project of Robotics Software Nanodegree Program by Udacity.  

## Overview  
In this project, you will use everything you learned in the Nanodegree Program to build a Home Service Robot in ROS.  
### Mapping  
You will create a `test_slam.sh` script file and launch it to manually test SLAM.  
A functional map of the environment should be created which would be used for localization and navigation tasks.  
### Localization and Navigation  
You will create a `test_navigation.sh` script file to launch it for manual navigation test.  
Your robot should be able to navigate in the environment after a 2D Nav Goal command is issued.  
You will create a `pick_objects.sh` file that will send multiple goals for the robot to reach.  
The robot travels to the desired pickup zone, displays a message that it reached its destination, waits 5 seconds, travels to the desired drop off zone, and displays a message that it reached the drop off zone."  
### Home Service Functions  
You will create a `add_marker.sh` file that will publish a marker to rviz.  
The marker should initially be published at the pickup zone. After 5 seconds it should be hidden. Then after another 5 seconds it should appear at the drop off zone.
The student should write a home_service.sh file that will run all the nodes in this project.  
The student's home service robot should be simulated as follow:  
* Initially show the marker at the pickup zone.
* Hide the marker once your robot reach the pickup zone.
* Wait 5 seconds to simulate a pickup.
* Show the marker at the drop off zone once your robot reaches it.

