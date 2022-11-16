#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Vector3.h"

class disturbance
{
 public:
  disturbance()
  {
   sub = n.subscribe("bluerov2/pose_gt", 1000, &disturbance::callback, this);
   pub = n.advertise<geometry_msgs::Vector3>("bluerov2/current_velocity", 1000);
  }
  void callback(const nav_msgs::Odometry::ConstPtr& msg)
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Current position=> " << "x: " << msg->pose.pose.position.x << ", " << "y: " << msg->pose.pose.position.y << ", " << "z: " << msg->pose.pose.position.z << ", " << "yaw: " << msg->pose.pose.orientation.z;
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
   geometry_msgs::Vector3 pubMsg;
   pubMsg.x = 50;
   pub.publish(pubMsg);
  }
  private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
};

int main(int argc, char **argv)
{
 ros::init(argc, argv, "disturbance");
 disturbance ctrl;
 ros::spin();
}
