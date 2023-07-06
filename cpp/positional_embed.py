"""
Nerf positional encoding
"""


import torch
# import numpy as np


if __name__ == "__main__":
	freq_dim = 10
	val_max = 256.0
	time_max = 5

	two_powers = torch.Tensor([2 ** i for i in range(freq_dim)])*torch.pi
	# print(two_powers.shape)

	values = torch.randn(1, 2, 2)

	sines_cosines_cols = []
	for i in range(values.shape[-1]):
		val = values[:,:,i].unsqueeze(2)
		
		# if i == 2:
		# 	sines_torch = torch.sin(two_powers*val/time_max)
		# 	cosines_torch = torch.cos(two_powers*val/time_max)
		# else:
		sines_torch = torch.sin(two_powers*val/val_max)
		cosines_torch = torch.cos(two_powers*val/val_max)

		sines_cosines = torch.stack((sines_torch, cosines_torch), dim=2).view(sines_torch.shape[0], sines_torch.shape[1], -1)
		sines_cosines_cols.append(sines_cosines)

		# print(val.shape, sines_torch.shape, cosines_torch.shape, sines_cosines.shape)
		# # print("sines:", sines_torch, '\ncosines:',cosines_torch, '\nsines_cosines:', sines_cosines)
		# print('\nsines_cosines:', sines_cosines)

	sines_cosines_cols = torch.stack(sines_cosines_cols, dim=2).view(sines_cosines.shape[0], sines_cosines.shape[1], -1)
	
	# print(sines_cosines_cols.shape, "\n--\n", sines_cosines_cols)