#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "nav_msgs/Odometry.h" //tipe data topic: /odom
#include "geometry_msgs/Twist.h" //kecepatan input

class controller
{
 public:
  controller()
  {
   sub = n.subscribe("odom", 1000, &controller::callback, this); //nerima data dari odom
   pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000); //kirim data ke cmd_vel
  }
  void callback(const nav_msgs::Odometry::ConstPtr& msg) //ngambil data dari odom tipe data=nav_msgs/Odometry
  {
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Current position=> " << "x: " << msg->pose.pose.position.x << ", " << "y: " << msg->pose.pose.position.y << ", " << "yaw: " << msg->pose.pose.orientation.z;
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
   geometry_msgs::Twist pubMsg;
   pubMsg.linear.x = 0;
   pubMsg.angular.z = 0;
   pub.publish(pubMsg);
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
