#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseWithCovarianceStamped
from gps_common.msg import GPSFix

from squaternion import Quaternion
from message_filters import ApproximateTimeSynchronizer, Subscriber
import cv2
from sensor_msgs.msg import Image, PointCloud2
# import pcl  
import ros_numpy  
import sensor_msgs

from cv_bridge import CvBridge, CvBridgeError
# from semantic_mapper.msg import SemLabel
import numpy as np
from sys import exit
import os
from scipy.spatial.transform import Rotation as R
import open3d as o3d


def callPose(msg):
	px, py, pz = msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z
	qx, qy, qz, qw = msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,\
	msg.pose.pose.orientation.z, msg.pose.pose.orientation.w

	q = Quaternion(qw, qx, qy, qz)
	roll, pitch, yaw = quat2euler(*q, degrees=True)

	line = str(px) + " " + str(py) + " " + str(yaw) + "\n"
	fileP.write(line)
	# print(line)


def callPoseSE3(msg):
	px, py, pz = msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z
	qx, qy, qz, qw = msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,\
	msg.pose.pose.orientation.z, msg.pose.pose.orientation.w

	# q = Quaternion(qw, qx, qy, qz)

	# roll, pitch, yaw = quat2euler(*q, degrees=False)
	# rEuler = R.from_euler('zyx', [yaw, pitch, roll])
	# rQuat = R.from_quat([qx, qy, qz, qw])

	# print(rEuler.as_dcm()-rQuat.as_dcm())
	# print(rQuat.as_dcm())
	# exit(1)

	line = str(px) + " " + str(py) + " " + str(pz) + " " + str(qx)  +  " " + str(qy) + " " + str(qz) + " " + str(qw) + "\n"
	fileP.write(line)
	# print(line)


def callImg(msg):
	# global imgCnt
	# imgCnt = imgCnt + 1
	# if(imgCnt%8 != 0):
	# 	return

	bridge = CvBridge()

	try:
		cvImage = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")	
	except CvBridgeError as e:
		print(e)

	global imgId
	
	imgName = dircImg + "rgb{:06d}.jpg".format(imgId)
	imgId = imgId + 1
	cv2.imwrite(imgName, cvImage)

	# cv2.imshow("imageWindow", cvImage)
	# cv2.waitKey(1)


def callDepth(msg):
	bridge = CvBridge()

	try:
		cvImage = bridge.imgmsg_to_cv2(msg, "passthrough")
	except CvBridgeError as e:
		print(e)

	global depthId
	
	imgName = dircDepth + "depth{:06d}".format(depthId)
	depthId = depthId + 1

	if(msg.encoding == "16UC1"):
		cv2.imwrite(imgName + ".png", cvImage)
	
	elif(msg.encoding == "32FC1"):
		cvImage = (np.nan_to_num(cvImage)*1000).astype(np.int16)
		np.save(imgName + ".npy", cvImage)
		

	# cv2.imshow("imageWindow", cvImage)
	# cv2.waitKey(1)


def callPoseImg(poseMsg, imgMsg):
	global freq
	freq = freq + 1
	if(freq%2 != 0):
		return

	callPose(poseMsg)
	callImg(imgMsg)


def callPoseImgDepth(poseMsg, imgMsg, depthMsg):
	# global freq
	# freq = freq + 1
	# if(freq%2 != 0):
	# 	return

	callPose(poseMsg)
	callImg(imgMsg)
	callDepth(depthMsg)


def callPoseSE3ImgDepth(poseMsg, imgMsg, depthMsg):
	# global freq
	# freq = freq + 1
	# if(freq%2 != 0):
	# 	return
	
	callPoseSE3(poseMsg)
	callImg(imgMsg)
	callDepth(depthMsg)


def callImgDepth(imgMsg, depthMsg):
	# global freq
	# freq = freq + 1
	# if(freq%2 != 0):
	# 	return

	callImg(imgMsg)
	callDepth(depthMsg)


def callPoseLbl(msg, lblMsg):
	px, py, pz = msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z
	qx, qy, qz, qw = msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,\
	msg.pose.pose.orientation.z, msg.pose.pose.orientation.w

	q = Quaternion(qw, qx, qy, qz)
	roll, pitch, yaw = quat2euler(*q, degrees=True)

	line = str(px) + " " + str(py) + " " + str(yaw) + " " + str(lblMsg.lvl) + "\n"
	fileP.write(line)
	# print(line)


def convert_pc_msg_to_np(pc_msg):
	# Fix rosbag issues, see: https://github.com/eric-wieser/ros_numpy/issues/23
	pc_msg.__class__ = sensor_msgs.msg._PointCloud2.PointCloud2
	offset_sorted = {f.offset: f for f in pc_msg.fields}
	pc_msg.fields = [f for (_, f) in sorted(offset_sorted.items())]

	# Conversion from PointCloud2 msg to np array.
	pc_np = ros_numpy.point_cloud2.pointcloud2_to_xyz_array(pc_msg, remove_nans=True)
	pc_np2 = ros_numpy.point_cloud2.pointcloud2_to_array(pc_msg)
	# pc_pcl = pcl.PointCloud2(np.array(pc_np, dtype=np.float32))
	
	print("Shape: ", pc_np.shape, type(pc_np2[0]), len(pc_np2[0]), pc_msg.fields)
	return pc_np 


def callPosePointCloud(msg, pcMsg):
	global freq

	if (freq%2 != 0):
		freq = freq + 1
		return

	px, py, pz = msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z
	qx, qy, qz, qw = msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,\
	msg.pose.pose.orientation.z, msg.pose.pose.orientation.w

	q = Quaternion(qw, qx, qy, qz)
	# print(q.to_euler(degrees=True))
	rot_matrix = np.array(q.to_rot())
	T = np.eye(3, 4)
	T[:3, :3] = rot_matrix
	T[:3, 3] = [px, py, pz]
	T = T.reshape(12, )

	pc_np = convert_pc_msg_to_np(pcMsg)
	# Saving pointcloud
	pcd = o3d.geometry.PointCloud()
	pcd.points = o3d.utility.Vector3dVector(pc_np)
	o3d.io.write_point_cloud(os.path.join(dirPointCloud, f"{freq//2}.pcd"), pcd)
	
	# o3d.visualization.draw_geometries([pcd])
	# print(pc_np.shape, type(pc_np))

	# Saving poses
	line = str(freq//2) + " " + str(T[0]) + " " + str(T[1]) + " " + str(T[2]) + " " + str(T[3]) + " " + str(T[4]) + " " + str(T[5]) + " " + str(T[6]) + " " + str(T[7]) + " " + str(T[8]) + " " + str(T[9]) + " " + str(T[10]) + " " + str(T[11]) + "\n"
	filePose.write(line)

	freq = freq + 1


def main1():
	rospy.Subscriber('odom', Odometry, callPose)


def main2():
	rospy.Subscriber('camera/rgb/image_raw', Image, callImg)


def main3():
	poseSub = Subscriber('RosAria/pose', Odometry)
	imgSub = Subscriber('camera/color/image_raw', Image)

	ats = ApproximateTimeSynchronizer([poseSub, imgSub], queue_size=1, slop=0.2)
	ats.registerCallback(callPoseImg)


def main4():
	poseSub = Subscriber('rtabmap/odom', Odometry)
	imgSub = Subscriber('camera/color/image_raw', Image)
	depthSub = Subscriber('camera/aligned_depth_to_color/image_raw', Image)

	ats = ApproximateTimeSynchronizer([poseSub, imgSub, depthSub], queue_size=1, slop=0.2)
	ats.registerCallback(callPoseImgDepth)


def main5():
	poseSub = Subscriber('raw_odom', Odometry)
	lblSub = Subscriber('semantic_label', SemLabel)

	ats = ApproximateTimeSynchronizer([poseSub, lblSub], queue_size=1, slop=0.2)
	ats.registerCallback(callPoseLbl)


def main6():
	imgSub = Subscriber('camera/color/image_raw', Image)
	depthSub = Subscriber('camera/aligned_depth_to_color/image_raw', Image)

	ats = ApproximateTimeSynchronizer([imgSub, depthSub], queue_size=1, slop=0.2)
	ats.registerCallback(callImgDepth)


def main7():
	poseSub = Subscriber('rtabmap/odom', Odometry)
	imgSub = Subscriber('camera/color/image_raw', Image)
	depthSub = Subscriber('camera/aligned_depth_to_color/image_raw', Image)

	ats = ApproximateTimeSynchronizer([poseSub, imgSub, depthSub], queue_size=1, slop=0.2)
	ats.registerCallback(callPoseSE3ImgDepth)


def main8():
	posewithcov = Subscriber('/gps_pose', PoseWithCovarianceStamped)
	pointcloud = Subscriber('/velodyne_points', PointCloud2)

	ats = ApproximateTimeSynchronizer([posewithcov, pointcloud], queue_size=1, slop=0.2)
	ats.registerCallback(callPosePointCloud)

if __name__ == '__main__':
	rospy.init_node("main", anonymous=True)

	# fileP = open('/home/cair/backup/d2-net/dataVO/data11/poses.txt', 'w')
	# dircImg = "/home/cair/backup/d2-net/dataVO/data11/rgb/"
	# dircDepth = "/home/cair/backup/d2-net/dataVO/data11/depth/"
	# dircPose = "/home/cair/backup/d2-net/dataPose/data5/pose/"
	path = "/home/usp/data/li_imu_ola/calib_data2/"
	dirPointCloud = os.path.join(path, "pointclouds")
	os.makedirs(dirPointCloud, exist_ok=True)
	filePose = open(os.path.join(path, 'pose.txt'), 'w')

	imgId = 0
	imgCnt = 0
	freq = 0
	depthId = 0

	# main1()
	# main2()
	# main3()
	# main4()
	# main5()
	# main6()
	# main7()
	main8()

	rospy.spin()

	# fileP.close()
	filePose.close()
