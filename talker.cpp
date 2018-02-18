#include "ros/ros.h"
#include "sensor_msgs/Temperature.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher temperature_pub = n.advertise<sensor_msgs::Temperature>("temperature", 1000);
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  {
    sensor_msgs::Temperature msg;
    msg.temperature = count;
    msg.variance = 0;
    msg.header.stamp = ros::Time::now();
    ROS_INFO("%f", msg.temperature);
    temperature_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}

