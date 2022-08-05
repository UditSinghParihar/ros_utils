#!/usr/bin/env python


import rospy
import rosbag
import sys
import datetime
import time

if sys.getdefaultencoding() != 'utf-8':
    # reload(sys)
    sys.setdefaultencoding('utf-8')
bag_name = 'filtered.bag' 
out_bag_name = 'filtered_correct.bag' 

with rosbag.Bag(out_bag_name, 'w') as outbag:
    
    for topic, msg, t in rosbag.Bag(bag_name).read_messages():
        if topic =='/gps/imu':
            stampFlag = msg.header.stamp
            outbag.write(topic, msg, msg.header.stamp)
        # elif topic =='/imu/data_raw':
        #     outbag.write(topic, msg, msg.header.stamp)
        elif topic == '/velodyne_points':
            msg.header.stamp = stampFlag
            outbag.write(topic, msg, msg.header.stamp)

print("finished")