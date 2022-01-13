#! /usr/bin/env python 
#Make the node an executable node
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/rotatetolga.py

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

def moveVertical(distance,isForward):
    speed=0.4

    if isForward == "head":
        vel_msg.linear.x=speed
    else:
        vel_msg.linear.x=-speed

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

# @brief it returns integer number between 0 and 1 using random library
# @return 0 or 1 
def randomNumberGenerator():
    return random.randint(0, 1)

# @brief it create a string array in function and using randomNumberGenerator function and return the array elements which index 0 or 1 
# @return elements of array as "head" or "tail"
def coinTossesGenerator():
    choice = ["head", "tail"]
    return choice[randomNumberGenerator()]


def moveOfTurtles(tosses, distance):
    if tosses == "head":
        moveVertical(distance,tosses)
        
    elif tosses == "tail":
        moveVertical(distance,tosses)


def unitMoveOfTurtles(previousDirection, distance):
    tosses = coinTossesGenerator()
    print(tosses)
    if previousDirection == "first":
        #print("first move")
        moveOfTurtles(tosses, distance)
        rotateTurtle(90,-1)
        moveVertical(distance,tosses)
    else:
        if tosses == previousDirection:
            #print("previous same")
            moveOfTurtles(tosses, distance)
        else:
            #print("previous not same ")
            moveOfTurtles(tosses, distance)
    return tosses


def runTurtle():
    previousDirection = "first"
    distance = 1  # start distance unit
    tempDirection = unitMoveOfTurtles(previousDirection, distance)
    if tempDirection == previousDirection:
        distance += 1
    else:
        distance *= 2
    previousDirection = tempDirection

    tempDirection = unitMoveOfTurtles(previousDirection, distance)
    if tempDirection == previousDirection:
        distance += 1
    else:
        distance *= 2
    previousDirection = tempDirection

    unitMoveOfTurtles(previousDirection, distance)

if __name__=="__main__":
    runTurtle()