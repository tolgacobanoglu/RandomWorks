#! /usr/bin/env python 


#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/move.py

import rospy
import sys
from geometry_msgs.msg import Twist

nodeid = str(sys.argv[1])
#nodename = 'turtle'+nodeid 
nodename = 'robot_'+nodeid 

def movetask():
	#rospy.init_node('movenode', anonymous= True)
	rospy.init_node(nodename, anonymous= True)
	#pub = rospy.Publisher('turtle2/cmd_vel', Twist, queue_size=10)
	pub = rospy.Publisher(nodename+'/cmd_vel', Twist, queue_size=10)
	#pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
	vel_msg = Twist()
	vel_msg.linear.x = 0.5
	vel_msg.linear.y = 0.0
	vel_msg.linear.z = 0.0

	vel_msg.angular.x = 0.0
	vel_msg.angular.y = 0.0
	vel_msg.angular.z = 0.0
		
	#rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		pub.publish(vel_msg)
		#rate.sleep()

if __name__== "__main__":
	try:
		movetask()
	except rospy.ROSINterruptException:
		pass