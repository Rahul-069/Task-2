import matplotlib.pyplot as plt
import numpy as np
from skimage import color, io

image_path = 'Rahul photo.jpg'  # Replace with the actual file path of the image
labrat = io.imread(image_path)

# Convert the image to LAB color space
lab_image = color.rgb2lab(labrat)

# Extract the L channel (brightness)
L_channel = lab_image[:, :, 0]

# Convert the brightness level to the range of L channel values
brightness_level = 128 * 100 / 255  # Convert from 0-255 to 0-100 scale

# Create a thresholded image
thresholded_image = np.where(L_channel > brightness_level, 255, 0)

# Display the black and white image
plt.imshow(thresholded_image, cmap='gray', vmin=0, vmax=255)
plt.show()
