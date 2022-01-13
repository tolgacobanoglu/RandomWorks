#! /usr/bin/env python 
#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/r.py

#for random generate number
import random 
#for rospy
import math
import rospy
import sys
from geometry_msgs.msg import Twist
from rospy.timer import Rate

rospy.init_node('movenode',anonymous=True)
pub=rospy.Publisher('turtle1/cmd_vel',Twist,queue_size=10)
vel_msg=Twist()
rate=rospy.Rate(10)
previousDirection="first"
headRotate="right"

def moveVertical(distance,isForward):
    speed=0.4
    vel_msg.linear.x=speed
    vel_msg.linear.y=0
    vel_msg.linear.z=0
    vel_msg.angular.x=0
    vel_msg.angular.y=0
    vel_msg.angular.z=0

    t0=rospy.Time.now().to_sec()
    currentDistance=0

    while(currentDistance < distance):
        pub.publish(vel_msg)
        t1=rospy.Time().now().to_sec()
        currentDistance=speed*(t1-t0)
        rate.sleep()
		
    vel_msg.linear.x=0.0
    vel_msg.angular.z=0.0
    pub.publish(vel_msg)

def rotateTurtle(angle,clockwise):
    speed=4
    distance=1

    angularSpeed=0.15
    relativeAnge=angle*(math.pi/180)

    vel_msg.linear.x=0
    vel_msg.angular.z=clockwise*angularSpeed
    t0=rospy.Time.now().to_sec()
    currentAngle=0

    while(currentAngle<relativeAnge):
        pub.publish(vel_msg)
        t1=rospy.Time.now().to_sec()
        currentAngle=angularSpeed*(t1-t0)
        rate.sleep
    vel_msg.linear.x=0.0
    vel_msg.angular.z=0.0
    pub.publish(vel_msg)

if __name__=="__main__":
    rotateTurtle(90,-1)