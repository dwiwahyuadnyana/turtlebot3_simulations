#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "uuv_gazebo_ros_plugins_msgs/FloatStamped.h"

class controller
{
 public:
  controller()
  {
   sub_0 = n.subscribe("/bluerov2/thrusters/0/thrust", 1000, &controller::callback_0, this);
   sub_1 = n.subscribe("/bluerov2/thrusters/1/thrust", 1000, &controller::callback_1, this);
  }
  void callback_0(const uuv_gazebo_ros_plugins_msgs::FloatStamped::ConstPtr& msg)
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Current speed thrusters_0 => " << msg->data << " RPM";
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str();
  }
  void callback_1(const uuv_gazebo_ros_plugins_msgs::FloatStamped::ConstPtr& msg)
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << ", thrusters_1 => " << msg->data << " RPM";
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
  }
 private:
 ros::NodeHandle n;
 ros::Subscriber sub_0, sub_1;
 ros::Publisher pub;
};

int main(int argc, char **argv)
{
 ros::init(argc, argv, "thrustmonitor");
 controller ctrl;
 ros::spin();
}
