#! /usr/bin/env python

#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials5/src/movedistance.py

import rospy
import sys
from geometry_msgs.msg import Twist

nodeid = str(sys.argv[1])
nodename = 'turtle'+nodeid

def movetask():

	#rospy.init_node('movenode', anonymous=True)
	#pub = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=10)
	
	rospy.init_node(nodename, anonymous=True)
	pub = rospy.Publisher(nodename+'/cmd_vel', Twist, queue_size=10)
	vel_msg = Twist()
	rate = rospy.Rate(10)
	rospy.loginfo("Moving...")

	speed = 5	#input("Speed: ")
	distance = 10	#input("Distance: ")
	isforward = 1	#input("Forward: ")

	if(isforward):
		vel_msg.linear.x = abs(speed)
	else:	
		vel_msg.linear.x = -abs(speed)
	
	vel_msg.linear.y = 0.0
	vel_msg.linear.z = 0.0
	vel_msg.angular.x = 0.0
	vel_msg.angular.y = 0.0
	vel_msg.angular.z = 0.0

	t0 = rospy.Time.now().to_sec()
	current_distance = 0

	while(current_distance < distance):
		pub.publish(vel_msg)
		t1 = rospy.Time.now().to_sec()
		current_distance = speed * (t1-t0)
		rate.sleep()

	vel_msg.linear.x = 0.0
	vel_msg.angular.z = 0.0
	pub.publish(vel_msg)

if __name__ == "__main__":
	try:
		movetask()
   	except rospy.ROSInterruptException:
		pass











