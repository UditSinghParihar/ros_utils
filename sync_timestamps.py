#!/usr/bin/env python2

import rospy
import rosbag
import sys
import datetime
import time

if sys.getdefaultencoding() != 'utf-8':
    reload(sys)
    sys.setdefaultencoding('utf-8')
bag_name = 'merge20_june_evening.bag' 
out_bag_name = 'correct.bag' 
dst_dir = '/home/usp/data/li_imu_ola/'
stampFlag = None


with rosbag.Bag(dst_dir+out_bag_name, 'w') as outbag:
    for topic, msg, t in rosbag.Bag(dst_dir+bag_name).read_messages():
        if topic =='/gps/imu':
            stampFlag = msg.header.stamp
            outbag.write(topic, msg, msg.header.stamp)
        elif topic =='/imu/data_raw':
            outbag.write(topic, msg, msg.header.stamp)
        elif topic == '/velodyne_points' and stampFlag is not None:
            msg.header.stamp = stampFlag
            outbag.write(topic, msg, msg.header.stamp)

print("finished")
