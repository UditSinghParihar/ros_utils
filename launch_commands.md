1. virtualenvwrapper:
	1. `workon`
	2. `workon env1`
	3. `lssitepackages`
	4. `mkvirtualenv [-r requirements_file] [virtualenv options] ENVNAME`
	5. `lsvirtualenv`
	6. `rmvirtualenv ENVNAME`

2. CUDA version:  
	1. `sudo apt install system76-cuda-latest`  
	2. `nvcc -V`
	 
3. CUDNN version:  
	1. `sudo apt install system76-cudnn-11.2`
	2. `sudo apt search cudnn | grep installed`
	3. `cat /usr/lib/cuda/include/cudnn_version.h | grep CUDNN_MAJOR -A 2`

4. Pytorch installation:
	1. On dell 3080:  
		1. cuda 11.2
		2. cudnn 8.1.1
		3. `pip install torch==1.10.2+cu111 torchvision==0.11.3+cu111 torchaudio==0.10.2 -f https://download.pytorch.org/whl/cu111/torch_stable.html`  
	2. On avlabs_red:  
		1. `pip install torch==1.10.2+cu113 torchvision==0.11.3+cu113 torchaudio==0.10.2+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html`    
	3. Checking pytorch installation:  
```python
import torch    
import sys  
print('A', sys.version)  
print('B', torch.__version__)  
print('C', torch.cuda.is_available())
print('D', torch.backends.cudnn.enabled)
device = torch.device('cuda')
print('E', torch.cuda.get_device_properties(device))
print('F', torch.tensor([1.0, 2.0]).cuda())
```

5. Pytorch for cuda 11.3:
	1. `pip install torch==1.12.1+cu113 torchvision==0.13.1+cu113 --extra-index-url https://download.pytorch.org/whl/cu113`

5. GIF creation:
	1. ffmpeg:  
		1. `ffmpeg -f image2 -framerate 4 -i img/%d.png -loop -1 img.gif`  
	2. Combining two gifs:  
		1. `https://ezgif.com/combine`  
	3. Video:  
		1. `ffmpeg -framerate 3 -pattern_type glob -i "bev/*.png" bev.mp4`  

6. Training on a particular gpu:  
	1. `CUDA_VISIBLE_DEVICES=0 python train.py`  

7. `roslaunch velodyne_pointcloud VLP16_points.launch` 
8. `rosbag record -O 24_aug_eve1 /velodyne_points /camera_right_front/image_raw  /camera_left_front/image_raw  /camera_front/image_raw`

9. ROS 1 bridge for ROS 2:
	1. `sudo apt install ros-foxy-ros1-bridge`
	2. ROS 1 terminals:  
		1. `source /opt/ros/noetic/setup.bash`
		2. `roscore`
		3. `rosbag play merge20_june_evening.bag --clock`  
	3. Bridge terminal:  
		1. `source /opt/ros/noetic/setup.bash`
		2. `source /opt/ros/foxy/setup.bash`
		3. `export ROS_MASTER_URI=http://localhost:11311`  
		3. `ros2 run ros1_bridge dynamic_bridge --bridge-all-topics`
	4. ROS 2 terminal:
		1. `ros2 topic hz /camera_front_driver/image_raw`  

10. `roscore` starting error:  
	1. `export ROS_HOSTNAME=localhost`  
	2. `export ROS_MASTER_URI=http://localhost:11311`  