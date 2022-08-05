#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import math 


def get_rotation (msg):
	# global roll, pitch, yaw
	global pub
	
	# orientation_q = msg.orientation
	# orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
	# (roll, pitch, yaw) = euler_from_quaternion(orientation_list)
	
	# Print angles in degrees
	# print(f"Roll: {math.degrees(roll)}, Pitch: {math.degrees(pitch)}, Yaw: {math.degrees(yaw)}")

	msg.header.frame_id = "base_link"
	msg.linear_acceleration.z += 9.8

	# Publish angles in degrees
	pub.publish(msg)

rospy.init_node('quaternion_to_euler')

sub = rospy.Subscriber ('/gps/imu', Imu, get_rotation)
pub = rospy.Publisher('imu_correct', Imu, queue_size=10)

r = rospy.Rate(1)
while not rospy.is_shutdown():
	r.sleep()