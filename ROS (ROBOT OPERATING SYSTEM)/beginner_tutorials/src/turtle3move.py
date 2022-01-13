#! /usr/bin/env python 
#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/turtle3move.py

import turtle
import random 
import math
import rospy
import sys
from geometry_msgs.msg import Twist
from rospy.timer import Rate

rospy.init_node('movenode',anonymous=True)
pub=rospy.Publisher('turtle1/cmd_vel',Twist,queue_size=10)
vel_msg=Twist()
rate=rospy.Rate(10)

# @brief it returns integer number between 0 and 1 using random library
# @return 0 or 1 
def randomNumberGenerator():
    return random.randint(0, 1)

# @brief it create a string array in function and using randomNumberGenerator function and return the array elements which index 0 or 1 
# @return elements of array as "head" or "tail"
def coinTossesGenerator():
    choice = ["head", "tail"]
    return choice[randomNumberGenerator()]

#@brief it rotate a turtle to spesific target
#@param speed speed of rotate
#@param angle rotate's angle
#@param clockwise which direction turtle rotate
#@param lspeed linear speed
def rotateTurtle(speed, angle, clockwise, lspeed= 0):
     
        angularspeed = speed * (math.pi/ 180)
        relativeangle = angle * (math.pi/ 180)

        vel_msg.linear.x = lspeed
        vel_msg.angular.z = clockwise * angularspeed

        t0 = rospy.Time.now().to_sec()
        current_angle = 0

	while(current_angle < relativeangle):
                pub.publish(vel_msg)
		t1 = rospy.Time.now().to_sec()
		current_angle =angularspeed * (t1-t0)
		rate.sleep()

	vel_msg.linear.x = 0.0
	vel_msg.angular.z= 0.0
	pub.publish(vel_msg)    

#@brief turtle move with shape
def runTurtle():

    tosses = coinTossesGenerator()    

    if tosses=="head":
        rotateTurtle(10,180,-1,0.08)
        tosses = coinTossesGenerator()
        if tosses =="head":
            rotateTurtle(10,180,-1)
            rotateTurtle(10,180,-1,0.16)
        else:
            rotateTurtle(10,180,1,0.16)
    else:
        rotateTurtle(10,180,-1)
        rotateTurtle(10,180,1,0.08)
        tosses = coinTossesGenerator()
        if tosses=="tail":
            rotateTurtle(10,180,-1)
            rotateTurtle(10,180,1,0.16)
        else:
            rotateTurtle(10,180,-1,0.16)



if __name__=="__main__":
    runTurtle()