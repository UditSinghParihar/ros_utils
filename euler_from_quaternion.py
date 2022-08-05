#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import math 


def get_rotation(msg):
	global roll, pitch, yaw
	orientation_q = msg.orientation
	orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
	(roll, pitch, yaw) = euler_from_quaternion(orientation_list)
	
	# Print angles in degrees
	print(f"Roll: {math.degrees(roll)}, Pitch: {math.degrees(pitch)}, Yaw: {math.degrees(yaw)}")

rospy.init_node('quaternion_to_euler')

sub = rospy.Subscriber ('/gps/imu', Imu, get_rotation)

r = rospy.Rate(1)
while not rospy.is_shutdown():
	r.sleep()