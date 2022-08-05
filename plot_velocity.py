"""
Reading the 'distance.npy' file and plotting the data using matplotlib.
"""

import matplotlib.pyplot as plt
import numpy as np

array = np.load("distance.npy")

# plt.plot(array[:,0], np.arange(0, array.shape[0], 1), 'r')

ax = plt.axes(projection='3d')

ax.plot3D(array[:,0], array[:,1], array[:,2], 'r')
plt.show()