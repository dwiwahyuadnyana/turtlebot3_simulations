#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "nav_msgs/Odometry.h"
#include "uuv_gazebo_ros_plugins_msgs/FloatStamped.h"

class controller
{
 public:
  controller()
  {
   sub = n.subscribe("bluerov2/pose_gt", 1000, &controller::callback, this);
   pub_0 = n.advertise<uuv_gazebo_ros_plugins_msgs::FloatStamped>("bluerov2/thrusters/0/input", 1000);
   pub_1 = n.advertise<uuv_gazebo_ros_plugins_msgs::FloatStamped>("bluerov2/thrusters/1/input", 1000);
  }

  void forward()
  {
   uuv_gazebo_ros_plugins_msgs::FloatStamped pubMsg;
   pubMsg.data = 30;
   pub_0.publish(pubMsg);
   pub_1.publish(pubMsg);
  }

  void left()
  {
   uuv_gazebo_ros_plugins_msgs::FloatStamped pubMsg;
   pubMsg.data = 0;
   pub_1.publish(pubMsg);
  }

  void callback(const nav_msgs::Odometry::ConstPtr& msg)
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Square control is ON!";
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
   forward();
   if (msg->pose.pose.position.x >= 7)
   {
    left();
   }
   if (msg->pose.pose.orientation.z >= 0.690)
   {
    forward();
   }
   while (msg->pose.pose.position.y >= 7)
   {
     left();
     if (msg->pose.pose.orientation.z >= 0.999907)
     {
     break;
     }
   } 
  }
 private:
 ros::NodeHandle n;
 ros::Subscriber sub;
 ros::Publisher pub_0, pub_1;
};

int main(int argc, char **argv)
{
 ros::init(argc, argv, "square");
 controller ctrl;
 ros::spin();
}
