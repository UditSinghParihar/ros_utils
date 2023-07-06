#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    background_r_launch_arg = DeclareLaunchArgument("background_r", default_value="0.0")
    background_g_launch_arg = DeclareLaunchArgument("background_g", default_value="255.0")
    background_b_launch_arg = DeclareLaunchArgument("background_b", default_value="0.0")

    turtlesim_node = Node(package="turtlesim", executable="turtlesim_node", name="sim")