#! /usr/bin/env python

#Make a python node executable
#chmod u+x ~/catkin_ws/src/beginner_tutorials/src/r4.py

#for random generate number
import random 
import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from math import pow, atan2, sqrt

# @brief it returns integer number between 0 and 1 using random library
# @return 0 or 1 
def randomNumberGenerator():
	return random.randint(0, 1)

# @brief it create a string array in function and using randomNumberGenerator function and return the array elements which index 0 or 1 
# @return elements of array as "head" or "tail"
def coinTossesGenerator():
	choice = ["head", "tail"]
	return choice[randomNumberGenerator()]

class Turtlebot:

	#brief : default constructor
	def __init__(self):
		rospy.init_node('turtletogoal',anonymous=True)
		self.pub = rospy.Publisher('turtle1/cmd_vel',Twist,queue_size=10)
		self.sub = rospy.Publisher('turtle1/pose',Pose,self.update_pose)
		self.pose = Pose()
		self.rate = rospy.Rate(10)

	def update_pose(self, data):
		self.pose = data

	def euclidean_distance(self, goal_pose):
		return sqrt( pow((goal_pose.x - self.pose.x ) , 2) + pow((goal_pose.y - self.pose.y ) , 2) )

	def linear_vel(self, goal_pose, constant=1.5):
		return constant * self.euclidean_distance(goal_pose)

	def steering_angle(self, goal_pose):
		return	atan2 (goal_pose.y - self.pose.y , goal_pose.x - self.pose.x)

	def angular_vel(self, goal_pose, constant=6):
		return constant * (self.steering_angle(goal_pose) - self.pose.theta)

	#brief : move function,combine of all functions
	def move2goal(self,a,b,c):
		goal_pose = Pose()
		goal_pose.x = a #input("x: ") 
		goal_pose.y = b #input("y: ") 
		disttolerance = c #input("disttolerance: ") 
		vel_msg = Twist()

		while(self.euclidean_distance(goal_pose) >= disttolerance):
			vel_msg.linear.x = self.linear_vel(goal_pose)
			vel_msg.linear.y = 0.0
			vel_msg.linear.z = 0.0

			vel_msg.angular.x = 0.0
			vel_msg.angular.y = 0.0
			vel_msg.angular.z = self.angular_vel(goal_pose)
			self.pub.publish(vel_msg)
			self.rate.sleep(10)

			vel_msg.linear.x = 0.0
			vel_msg.angular.z = 0.0
			self.pub.publish(vel_msg)


	def runTurtle(self):
		tosses = coinTossesGenerator()
		move2goal(self,1,0.6,0.1)



 
if __name__ == "__main__":
	try:
		x = Turtlebot()
		x.runTurtle()

	except rospy.ROSInterruptException:
		pass







