pip install imageio //to install imageio package

import imageio
import requests
import numpy as np
import matplotlib.pyplot as plt
import IPython.display as dp

//to read the image using imread()
img="flower.jpg"
source_img=imageio.imread(img)

//making the image black and white by applying greyscale
def grayscaleimg(rgb):
  return np.dot(rgb[...,:3],[0.299,0.587,0.114]) 
gryscl_img=grayscaleimg(source_img)

//inverting the image by subtracting it from 255
inv_img=(255-gryscl_img)
//plt.imshow(inv_img)  //to display thr inverted image

//blur the image using gaussian filter by vaying the sigma
import scipy.ndimage
blurred_img=scipy.ndimage.filters.gaussian_filter(inv_img,sigma=20)
//plt.imshow(blurred_img)  //to display the blurred image

//trying to dodge means blending the greyscale and blurred image to form a sketch
def dodging(blur_img,gryscl_img):
  resultant_dodge=blur_img*255/(255-gryscl_img)
  resultant_dodge[resultant_dodge>255]=255
  resultant_dodge[gryscl_img==255]=255
  return resultant_dodge.astype('uint8')
target_img= dodging(blurred_img,gryscl_img)  //target_img is the image formed by dodging the other images

//displaying the desired image
%matplotlib inline
import matplotlib.pyplot as plt
plt.imshow(target_img,cmap="gray")
//saving the image
plt.imsave('target_img.png',target_img,cmap='gray',vmin=0,vmax=255)