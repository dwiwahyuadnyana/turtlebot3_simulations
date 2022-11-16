#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "nav_msgs/Odometry.h"

class controller
{
 public:
  controller()
  {
   sub = n.subscribe("bluerov2/pose_gt", 1000, &controller::callback, this);
  }
  void callback(const nav_msgs::Odometry::ConstPtr& msg)
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Current positions => " << "x: " << msg->pose.pose.position.x << ", " << "y: " << msg->pose.pose.position.y << ", " << "z: " << msg->pose.pose.position.z << ", " << "yaw: " << msg->pose.pose.orientation.z;
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
  }
  private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
};

int main(int argc, char **argv)
{
 ros::init(argc, argv, "controller");
 controller ctrl;
 ros::spin();
}
