#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;

void callbackfunc(const std_msgs::String::ConstPtr& message)
{
    ROS_INFO("Received message %s",message->data.c_str());
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"stringsubscriber");
    ros::NodeHandle n;
    ros::Subscriber wordsub = n.subscribe<std_msgs::String>("/words",10);
    ros::spin();
    

    return 0;
}