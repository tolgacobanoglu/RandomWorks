#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>
#include <geometry_msgs/Pose2D.h>
#include <math.h>

ros::Publisher pub;
geometry_msgs::Twist msg;
geometry_msgs::Pose2D current_pose;

void callback(const nav_msgs::Odometry::ConstPtr &msg)
{
	//ROS_INFO("%s", msg->header.frame_id.c_str());
	//ROS_INFO("%f", msg->twist.twist.linear.x);
	//ROS_INFO("%f", msg->pose.pose.position.x);

	current_pose.x = msg->pose.pose.position.x;
	current_pose.y = msg->pose.pose.position.y;

	//ROS uses quaternions (4 dimensional number system) to track and apply rotations. 
	//A quaternion has 4 components (x,y,z,w).
	//Good way for describing 3D orientation. 
	//Also, Euler angles for rotation.
	tf::Quaternion q(
		msg->pose.pose.orientation.x,
		msg->pose.pose.orientation.y,
		msg->pose.pose.orientation.z,
		msg->pose.pose.orientation.w);

	tf::Matrix3x3 m(q);
	double roll,pitch,yaw;
	m.getRPY(roll,pitch,yaw);
	current_pose.theta = yaw;
	ROS_INFO("%f",yaw);

}

void move(ros::NodeHandle n)
{
	pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	ros::Rate loop_rate(10);

	while (ros::ok()&&current_pose.x<2.0)
	{
		msg.linear.x = 0.2;
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}

	msg.linear.x = 0;
	msg.angular.z = 0;
	pub.publish(msg);
	
}

void rotate1(ros::NodeHandle n)
{
	pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	ros::Rate loop_rate(10);

	while(ros::ok() && current_pose.theta > -M_PI/2)
	{
		msg.linear.x = 0.0;
		msg.angular.z = -0.3;
		pub.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();
	}

	msg.linear.x = 0;
	msg.angular.z = 0;
	pub.publish(msg);
}

void rotate2(ros::NodeHandle n)
{
	pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	ros::Rate loop_rate(10);

	msg.linear.x = 0.0;
	msg.angular.z = 0.2;

	double targetdegree = 0;
	double targetrad;
	double c = 0.5; // kp: proportional gain
	while (ros::ok())
	{
		targetrad = targetdegree * M_PI/180.0;	
		msg.linear.x = 0.0;
		msg.angular.z = c * (targetrad - current_pose.theta);
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}

	msg.linear.x = 0;
	msg.angular.z = 0;
	pub.publish(msg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "odomnode");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("/odom", 1000, callback);

	move(n);
	rotate1(n);
	rotate2(n);
	printf("Done!");
	ros::service::waitForService("/gazebo/set_model_state");
	//ros::ServiceClient client = n.serviceClient<gazebo_msgs::SetModelState>("/gazebo/set_model_state");
	ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("/gazebo/reset_world");
	std_srvs::Empty srv;
	client.call(srv);
	ros::spin();

	return 0;
}