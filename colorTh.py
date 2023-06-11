import matplotlib.image as mpimg
import matplotlib.pyplot as plt 
import numpy as np
import math

image= 'file/path/image.jpg'

#RGB(3 streams) matrix representation of the image
labrat = mpimg.imread(image)
print(labrat)

'''
Write the script wrt the given instruction here.
'''

#Question - 6

# Create a mutable copy of the array
labrat_copy = np.array(labrat)

# Convert the image to typeA/typeB representation
threshold = (160, 160, 160)

typeA_count = 0
typeB_count = 0

for i in range(labrat_copy.shape[0]):
    for j in range(labrat_copy.shape[1]):
        pixel = labrat_copy[i, j]
        if np.all(pixel > threshold):
            labrat_copy[i, j] = [255, 0, 0]  # Mark as typeA (red)
            typeA_count += 1
        else:
            labrat_copy[i, j] = [0, 255, 0]  # Mark as typeB (green)
            typeB_count += 1

total_pixels = labrat_copy.shape[0] * labrat_copy.shape[1]
typeA_percentage = (typeA_count / total_pixels) * 100
typeB_percentage = (typeB_count / total_pixels) * 100

print(f"TypeA pixels: {typeA_percentage:.2f}%")
print(f"TypeB pixels: {typeB_percentage:.2f}%")

#Display The image
imgplot = plt.imshow(labrat)

plt.show()
