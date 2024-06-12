#!/bin/python3
from PIL import Image
import sys

def conv_number(value):
    if (type(value) is list) or (type(value) is tuple):
        value = value[0]

    return (69 * value) // 255

image_src = sys.argv[1]
chars = list("""$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. """)
chars.reverse()

with Image.open(image_src) as img:
    img.convert('LA').load()
    h,w = img.size
    with open(image_src + '.txt','w') as fhand:
        for row in range(w):
            for col in range(h):
                pixel = img.getpixel((col,row))
                fhand.write(chars[conv_number(pixel)])
            fhand.write('\n')
