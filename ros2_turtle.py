#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	return LaunchDescription([
		Node(
			package='turtlesim',
			executable='turtlesim_node',
			name='sim'
		),
		# Node(
		# 	package='turtlesim',
		# 	executable='turtlesim_node',
		# 	name='sim2'
		# ),
		Node(
		    package='turtlesim',
		    executable='turtle_teleop_key',
		    name='teleop',
			output='screen',
		),
	])