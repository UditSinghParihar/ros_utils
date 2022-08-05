from cv_bridge import CvBridge, CvBridgeError
from message_filters import ApproximateTimeSynchronizer, Subscriber
import rospy
from sensor_msgs.msg import Image
from geometry_msgs.msg import PoseWithCovarianceStamped
from gps_common.msg import GPSFix
import cv2
import argparse
import os
import csv


parser = argparse.ArgumentParser(description='Extract data from rosbag files for NEAT inference')
parser.add_argument('--data_dir', type=str, default='/home/usp/data/ola_17june/raw_data', help='Image directory')
parser.add_argument('--pose_file', type=str, default='/home/usp/data/ola_17june/raw_data/poses.csv', help='Pose file')


def callImg(msg, directory, imgId):
	bridge = CvBridge()

	try:
		cvImage = bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")	
	except CvBridgeError as e:
		print(e)

	
	
	imgName = os.path.join(directory, "rgb{:06d}.jpg".format(imgId)) 
	cv2.imwrite(imgName, cvImage)
	# print("Saved image: {}".format(imgName))


def callPoseSpeed(msg, gps):
	px, py, pz = msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z
	qx, qy, qz, qw = msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,\
	msg.pose.pose.orientation.z, msg.pose.pose.orientation.w

	# print(px, py, pz, qx, qy, qz, qw)
	# print(gps.speed)
	data = [px, py, pz, qx, qy, qz, qw, gps.speed]
	csvWriter.writerow(data)


def callSyncData(imgFront, imgLeft, imgRight, posewithcov, gps):
	global imgId
	imgId = imgId + 1
	
	callImg(imgFront, frontDir, imgId)
	callImg(imgLeft, leftDir, imgId)
	callImg(imgRight, rightDir, imgId)
	callPoseSpeed(posewithcov, gps)


def main():
	imgSubFront = Subscriber('camera/front', Image)
	imgSubLeft = Subscriber('camera/front_left', Image)
	imgSubRight = Subscriber('camera/front_right', Image)
	posewithcov = Subscriber('/gps_pose', PoseWithCovarianceStamped)
	gps = Subscriber('/gps/gps', GPSFix)

	ats = ApproximateTimeSynchronizer([imgSubFront, imgSubLeft, imgSubRight, posewithcov, gps], queue_size=1, slop=0.2)
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

	if not os.path.isdir(frontDir):
		os.makedirs(frontDir)
	if not os.path.isdir(leftDir):
		os.makedirs(leftDir)
	if not os.path.isdir(rightDir):
		os.makedirs(rightDir)

	csvFile = open(args.pose_file, "w")
	csvWriter = csv.writer(csvFile)
	poseFields = ['x', 'y', 'z', 'qx', 'qy', 'qz', 'qw', 'speed']
	csvWriter.writerow(poseFields)

	main()

	rospy.spin()