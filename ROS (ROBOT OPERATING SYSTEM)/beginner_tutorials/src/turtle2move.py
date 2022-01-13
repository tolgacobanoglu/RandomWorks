#! /usr/bin/env python 
#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/r2.py

import turtle
import random 
import math
import rospy
import sys
from geometry_msgs.msg import Twist
from rospy.timer import Rate

rospy.init_node('movenode',anonymous=True)
pub=rospy.Publisher('turtle2/cmd_vel',Twist,queue_size=10)
vel_msg=Twist()
rate=rospy.Rate(10)

#@brief turtle is moving vertical on x-axis 
#@param distance how many unit turtle does move
#@param rightOrLeft which way turtle is going
def moveVertical(distance,rigthOrLeft):
    speed=1
    if rigthOrLeft == "right":
        vel_msg.linear.x=speed
    else:
        vel_msg.linear.x=-speed
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

#@brief it rotate a turtle to spesific target
#@param angle rotate's angle
#@param clockwise which direction turtle rotate
def rotateTurtle(angle,clockwise):
    speed=1
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

#@brief it returns integer number between 0 and 1 using random library
#@return 0 or 1 
def randomNumberGenerator():
    return random.randint(0, 1)

#@brief it create a string array in function and using randomNumberGenerator function and return the array elements which index 0 or 1 
#@return elements of array as "head" or "tail"
def coinTossesGenerator():
    choice = ["head", "tail"]
    return choice[randomNumberGenerator()]

#@brief first move of the turtle to start round
#@param tosses "head" or "tail" it will be equal to coinTossesGenerator
#@param distance how many unit move of turtle
def firstMove(tosses,distance):

    previousDirection=tosses

    if tosses=="head":
        moveVertical(distance,"right")
        rotateTurtle(90,-1)
        moveVertical(0.3,"left")
        rotateTurtle(90,-1)
        moveVertical(distance,"left")
        rotateTurtle(90,1)
        moveVertical(0.3,"left")
    else:
        rotateTurtle(180,1)
        moveVertical(distance,"left")
        rotateTurtle(90,1)
        moveVertical(0.3,"right")
        rotateTurtle(90,1)
        moveVertical(distance,"right")
        rotateTurtle(90,-1)
        moveVertical(0.3,"right")

#@brief other move of the turtle to start round
#@param tosses "head" or "tail" it will be equal to coinTossesGenerator  
#@param distance how many unit move of turtle
def moveTurtle(tosses,distance):
    print(tosses)
    if tosses == "head":
        rotateTurtle(90,1)
        moveVertical(distance,"right")
        rotateTurtle(90,-1)
        moveVertical(0.3,"left")
        rotateTurtle(90,-1)
        moveVertical(distance,"left")
        rotateTurtle(90,1)
        moveVertical(0.3,"left")
    elif tosses == "tail":
        rotateTurtle(90,-1)
        moveVertical(distance,"right")
        rotateTurtle(90,1)
        moveVertical(0.3,"left")
        rotateTurtle(90,1)
        moveVertical(distance,"left")
        rotateTurtle(90,-1)
        moveVertical(0.3,"left")
                
#@brief turtle move with shape
def runTurtle():
    tosses=coinTossesGenerator()
    distance=1
    previousDirection=tosses
    firstMove(tosses,distance)
    tosses=coinTossesGenerator()
    if previousDirection==tosses:
        distance+=1
    else:
        distance*=2
    previousDirection=tosses
    moveTurtle(tosses,distance)
    tosses=coinTossesGenerator()
    if previousDirection==tosses:
        distance+=1
    else:
        distance*=2
    moveTurtle(tosses,distance)


if __name__=="__main__":
    runTurtle()