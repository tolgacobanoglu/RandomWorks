#! /usr/bin/env python

#Make a python node executable
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/odomexercise1.py

import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry 

#ROS nav_msgs/Odometry Message
#
#rosmsg show nav_msgs/Odometry
#The nav_msgs/Odometry message stores an estimate of the position and velocity of a robot.

def callback(msg):
	print msg.pose.pose

def movetask():	
	pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
	
	vel_msg = Twist()

	vel_msg.linear.x = 0.5
	vel_msg.linear.y = 0
	vel_msg.linear.z = 0
	vel_msg.angular.x = 0
	vel_msg.angular.y = 0
	vel_msg.angular.z = 0.2

	while not rospy.is_shutdown():
		pub.publish(vel_msg)

	vel_msg.linear.x = 0.0
	vel_msg.angular.z = 0.0
	pub.publish(vel_msg)

rospy.init_node('movenode', anonymous=True)
odom_sub = rospy.Subscriber('/odom', Odometry, callback)

movetask()

rospy.spin()