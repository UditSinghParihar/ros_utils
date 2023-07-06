"""
Script to generate top view of roads using IPM for NuScenes
"""

import argparse
import cv2
import numpy as np
import os


parser = argparse.ArgumentParser(description='Generate top view of roads using IPM for NuScenes')
parser.add_argument('--input', type=str, help='Path to image')
parser.add_argument('--output', type=str, default='top_ipm.png', help='Path to output image')
parser.add_argument('--out_dir', type=str, default='results', help='Path to output folder')
parser.add_argument('--length', type=int, default=800, help='Length of rectangular region')
parser.add_argument('--width', type=int, default=300,help='Width of rectangular region')
parser.add_argument('--offset', type=int, default=700, help='Offset along width')


if __name__ == '__main__':
	args = parser.parse_args()

	if not os.path.isdir(args.out_dir):
		os.mkdir(args.out_dir)

	# Load image
	img_perspective = cv2.imread(args.input)
	cv2.imshow('Perspective Image', img_perspective)
	cv2.waitKey(0)
	# exit(1)

	# Points in anti-clockwise order starting from bottom left
	# pts_correct = np.array([[0, args.length], [args.width, args.length], [args.width, 0], [0, 0]])
	pts_correct = np.array([[args.offset, args.length], [args.width+args.offset, args.length], [args.width+args.offset, 0], [args.offset, 0]])
	pts_road = np.array([[145, 676], [1329, 724], [957, 532], [693, 526]])

	homographyMat, status = cv2.findHomography(pts_road, pts_correct)
	# img_top = cv2.warpPerspective(img_perspective, homographyMat, (args.width, args.length))
	img_top = cv2.warpPerspective(img_perspective, homographyMat, (1600, 900))

	# Save perspective and top view
	cv2.imwrite(args.out_dir + "/perspective.png", img_perspective)
	cv2.imwrite(os.path.join(args.out_dir, args.output), img_top)

	# cv2.namedWindow('Output Window', cv2.WINDOW_NORMAL)

	cv2.imshow('Perspective Image', img_perspective)
	cv2.imshow('Top Image', img_top)
	cv2.waitKey(0)