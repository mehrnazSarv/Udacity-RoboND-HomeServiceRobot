#include <math.h>
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>


double pickUp_x = 2.0;
double pickUp_y = 2.0;

double dropOff_x = -2.5;
double dropOff_y = 3.0;


ros::Publisher marker_pub;



void moveMarker(const nav_msgs::Odometry::ConstPtr& msg) {
  
  visualization_msgs::Marker marker;

  
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  
  marker.ns = "basic_shapes";
  marker.id = 0;

  
  marker.type = visualization_msgs::Marker::CUBE;

  
  marker.scale.x = 0.3;
  marker.scale.y = 0.3;
  marker.scale.z = 0.3;

 
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  
  double x_pos = msg->pose.pose.position.x;
  double y_pos = msg->pose.pose.position.y;
  double z_pos = msg->pose.pose.position.z;
 
  double pick_up_dis = sqrt(pow(x_pos + 2.4, 2) + pow(y_pos + 1.7, 2));
 double drop_off_dis = sqrt(pow(x_pos + 0.7, 2) + pow(y_pos - 2.5, 2));



  
  if (pick_up_dis < 0.15) {
    ROS_INFO("Picking up the item!");
    sleep(5);
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    
  } else if (drop_off_dis < 0.15) {
    ROS_INFO("Dropping off the item!");
    sleep(5);
    marker.pose.position.x = dropOff_x;
    marker.pose.position.y = dropOff_y;
    marker.pose.position.z = 0.0;
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
  }

 
  
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);

  
  ros::Subscriber sub = n.subscribe("odom", 10, moveMarker);

  
  marker_pub =
      n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::spin();
  return 0;
}
