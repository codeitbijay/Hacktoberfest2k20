import numpy as np

def convolution(img, kernel):
    # Image size
    img_N, img_M = img.shape
    # Kernel size
    flt_n, flt_m = kernel.shape
    
    # Padding
    pad_n = np.trunc(flt_n/2).astype(int)
    pad_m = np.trunc(flt_m/2).astype(int)
    
    # Matrix initialization
    conv_img = np.zeros(img.shape)
    for j in range(pad_n, img_N-pad_n):
        for i in range(pad_m, img_M-pad_m):
            conv_img[i, j] = np.sum(np.multiply(img[i-pad_n:i+pad_n+1,j-pad_m:j+pad_m+1], kernel))

    return conv_img

