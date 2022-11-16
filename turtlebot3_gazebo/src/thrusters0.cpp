#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "nav_msgs/Odometry.h" //tipe data topic: /odom
#include "uuv_gazebo_ros_plugins_msgs/FloatStamped.h" //kecepatan input

class controller //
{
 public:
  controller() //
  {
   sub = n.subscribe("bluerov2/pose_gt", 1000, &controller::callback, this); //
   pub = n.advertise<uuv_gazebo_ros_plugins_msgs::FloatStamped>("bluerov2/thrusters/0/input", 1000);
  }
  void callback(const nav_msgs::Odometry::ConstPtr& msg)
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Thrusters 0 is on!";
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
   uuv_gazebo_ros_plugins_msgs::FloatStamped pubMsg;
   pubMsg.data = 25;
   pub.publish(pubMsg);
  }
  private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
};

int main(int argc, char **argv)
{
 ros::init(argc, argv, "controller0"); //
 controller ctrl; //
 ros::spin();
}
