#! /usr/bin/env python 

#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/scanenvironment.py

import rospy
import sys
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

nodeid = str(sys.argv[1])
nodename = 'robot_'+nodeid 

vel_msg = Twist()
vel_msg.linear.x = 0.5
vel_msg.linear.y = 0.0
vel_msg.linear.z = 0.0

vel_msg.angular.x = 0.0
vel_msg.angular.y = 0.0
vel_msg.angular.z = 0.0

def callback(msg):
    print('s1[0] : '+str(msg.ranges[0]) + 's1[90]: '+str(msg.ranges[90]) + 's1[135]: '+str(msg.ranges[135]))
    if(msg.ranges[135] > 0.5):
        vel_msg.linear.x = 0.5
        vel_msg.linear.y = 0.0    
    else:
        vel_msg.linear.x = 0.0
        vel_msg.linear.y = 0.0

    pub.publish(vel_msg)

rospy.init_node(nodename, anonymous= True)
pub = rospy.Publisher(nodename+'/cmd_vel', Twist, queue_size=10)
sub = rospy.Subscriber(nodename+'/base_scan',LaserScan,callback)

rospy.spin()
