#!/usr/bin/env python


import rospy
from sensor_msgs.msg import Imu
from message_filters import ApproximateTimeSynchronizer, Subscriber
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import math 


def callIMUPose(imuMsg1, imuMsg2):
	orientation_q = imuMsg1.orientation
	orientation_list = [orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
	(roll, pitch, yaw) = euler_from_quaternion(orientation_list)
	
	# Print angles in degrees
	print(f"Roll: {math.degrees(roll)}, Pitch: {math.degrees(pitch)}, Yaw: {math.degrees(yaw)}")


def callIMUMerge(imuMsg1, imuMsg2):
	global pub

	imuMsg1.header.frame_id = "base_link"
	imuMsg1.linear_acceleration = imuMsg2.linear_acceleration
	imuMsg1.linear_acceleration_covariance = imuMsg2.linear_acceleration_covariance
	imuMsg1.angular_velocity = imuMsg2.angular_velocity
	imuMsg1.angular_velocity_covariance = imuMsg2.angular_velocity_covariance

	pub.publish(imuMsg1)


def main():
	imuSub1 = Subscriber('/gps/imu', Imu)
	imuSub2 = Subscriber('/imu/data_raw', Imu)

	ats = ApproximateTimeSynchronizer([imuSub1, imuSub2], queue_size=1, slop=0.2)
	ats.registerCallback(callIMUPose)
	# ats.registerCallback(callIMUMerge)


if __name__ == '__main__':
	rospy.init_node("imus_merge", anonymous=True)
	pub = rospy.Publisher('imu_correct', Imu, queue_size=10)

	main()

	rospy.spin()