"""
NEAT Data extraction for lidar poses and camera images
"""

from cv_bridge import CvBridge, CvBridgeError
from message_filters import ApproximateTimeSynchronizer, Subscriber
import rospy
from sensor_msgs.msg import Image
# from geometry_msgs.msg import PoseWithCovarianceStamped
# from gps_common.msg import GPSFix
import cv2
import argparse
import os
import csv
import tf
from squaternion import Quaternion


parser = argparse.ArgumentParser(description='Extract data from rosbag files for NEAT inference')
parser.add_argument('--data_dir', type=str, default='/home/usp/data/iiit_24aug/raw_data3', help='Image directory')
parser.add_argument('--pose_file', type=str, default='/home/usp/data/iiit_24aug/raw_data3/poses.csv', help='Pose file')


def callImg(msg, directory, imgId):
	bridge = CvBridge()

	try:
		cvImage = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")	
	except CvBridgeError as e:
		print(e)

	
	
	imgName = os.path.join(directory, "{:06d}.jpg".format(imgId)) 
	cv2.imwrite(imgName, cvImage)
	# print("Saved image: {}".format(imgName))


def callSyncData(imgFront, imgLeft, imgRight):
	global imgId, listener
	
	callImg(imgFront, frontDir, imgId)
	callImg(imgLeft, leftDir, imgId)
	callImg(imgRight, rightDir, imgId)

	imgId = imgId + 1
	
	"""
	aft_mapped wrt hd_map : LUF (== XYZ)
	trans: x, y, z (linear transformation of the child frame relative to the parent)
	rot: x, y, z, w  
	"""
	try:
		(trans,rot) = listener.lookupTransform('hd_map', 'aft_mapped', rospy.Time(0))
	except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
		pass
	
	"""
	euler angles from_euler(roll, pitch, yaw), default is radians, but set degrees true if giving degrees
	"""
	qx, qy, qz, qw = rot[0], rot[1], rot[2], rot[3]
	theta_ele = Quaternion(qw,qx,qy,qz).to_euler(degrees=True)[1]
	data = [trans[2], trans[0], theta_ele]
	csvWriter.writerow(data)


def main():
	imgSubFront = Subscriber('camera_front/image_raw', Image)
	imgSubLeft = Subscriber('camera_left_front/image_raw', Image)
	imgSubRight = Subscriber('camera_right_front/image_raw', Image)
	# posewithcov = Subscriber('/gps_pose', PoseWithCovarianceStamped)
	# gps = Subscriber('/gps/gps', GPSFix)

	ats = ApproximateTimeSynchronizer([imgSubFront, imgSubLeft, imgSubRight], queue_size=1, slop=0.2)
	ats.registerCallback(callSyncData)


if __name__ == '__main__':
	rospy.init_node('sync_extract_neat_data', anonymous=True)

	imgId = 0
	args = parser.parse_args()
	
	if not os.path.isdir(args.data_dir):
		os.makedirs(args.data_dir)

	frontDir = os.path.join(args.data_dir, "front")
	leftDir = os.path.join(args.data_dir, "left")
	rightDir = os.path.join(args.data_dir, "right")

	listener = tf.TransformListener()

	if not os.path.isdir(frontDir):
		os.makedirs(frontDir)
	if not os.path.isdir(leftDir):
		os.makedirs(leftDir)
	if not os.path.isdir(rightDir):
		os.makedirs(rightDir)

	csvFile = open(args.pose_file, "w")
	csvWriter = csv.writer(csvFile)
	poseFields = ['x', 'y', 'theta']
	csvWriter.writerow(poseFields)

	main()

	rospy.spin()