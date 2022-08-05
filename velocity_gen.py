#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry
import numpy as np


def callPose(msg):
	px, py, pz = msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z
	a = [px, py, pz]
	distance.append(a)


def main():
	rospy.Subscriber('aft_mapped_to_init', Odometry, callPose)


if __name__ == '__main__':
	distance = []
	rospy.init_node("main", anonymous=True)
	main()

	rospy.spin()

	array = np.array(distance)
	np.save("distance.npy", array)