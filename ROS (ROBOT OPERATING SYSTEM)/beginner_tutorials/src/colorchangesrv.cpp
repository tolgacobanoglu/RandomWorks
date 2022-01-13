#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "setcolor");
	ros::NodeHandle n;
	
	//int color_r = 255, color_b = 25, color_g = 20;
	int color_r, color_b, color_g;	

	n.getParam("r", color_r);
	n.getParam("g", color_g);
	n.getParam("b", color_b);

	ros::service::waitForService("clear");

	ros::param::set("background_r", color_r);
	ros::param::set("background_g", color_g);
	ros::param::set("background_b", color_b);

	ros::ServiceClient clearclient = n.serviceClient<std_srvs::Empty>("clear");
	std_srvs::Empty srv;

	clearclient.call(srv);
	
	ros::ServiceClient sclient = n.serviceClient<turtlesim::Spawn>("spawn");

	turtlesim::Spawn::Request req;
	turtlesim::Spawn::Response resp;

	req.x = 2;
	req.y = 2;
	req.theta = 0.5;
	req.name = "turtle2";

	bool success = sclient.call(req, resp);
}