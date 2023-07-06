import open3d as o3d
import numpy as np

# Define camera parameters
tilt_angle = 30  # in degrees about y axis
baseline = 0.05  # in meters

# Define camera positions and orientations
R_left = o3d.geometry.get_rotation_matrix_from_axis_angle(np.array([0, 1, 0]) * np.pi / 6)
R_right = o3d.geometry.get_rotation_matrix_from_axis_angle(np.array([0, 1, 0]) * -np.pi / 6)

t_left = [0, 0, 0]
t_right = [baseline, 0, 0]


# Create coordinate frame geometries for the cameras
left_axis = o3d.geometry.TriangleMesh.create_coordinate_frame(size=0.15, origin=[0, 0, 0])
left_axis.rotate(R_left)
left_axis.translate(t_left)
right_axis = o3d.geometry.TriangleMesh.create_coordinate_frame(size=0.15, origin=[0, 0, 0])
right_axis.rotate(R_right)
right_axis.translate(t_right)



# Create visualizer and add geometries
vis = o3d.visualization.Visualizer()
vis.create_window()
vis.add_geometry(left_axis)
vis.add_geometry(right_axis)

# Run visualizer
vis.run()
vis.destroy_window()
