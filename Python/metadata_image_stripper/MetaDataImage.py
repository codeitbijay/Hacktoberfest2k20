import logging
import os
from PIL import Image
from PIL.ExifTags import TAGS
from PIL.ExifTags import GPSTAGS
import pathlib
from pathlib import Path

VALID_FORMAT=(".jpg","jpeg")
def check_file_format(file):
    return  file.lower().endswith(VALID_FORMAT)

def is_directory(user_input):
    #return Path.is_dir(user_input)
    return os.path.isdir(user_input)

def filter_directory(user_input):
    for images_with_extension in ["*.jpg","*.jpeg"]:
        list_of_images = list(pathlib.Path(user_input).glob(images_with_extension))
        if(len(list_of_images)==0):
            print("There are no jpg or jpeg in the directory")
        for images in list_of_images:
            print_exif(images)
    pass 

def print_exif(image_file):
    imageobject = Image.open(image_file)
    exifdict = imageobject._getexif()
    logger = logging.getLogger('metadata_stripper.log')
    logger.setLevel(logging.INFO)
    fh = logging.FileHandler('metadata_stripper.log')
    fh.setLevel(logging.INFO)
    logger.addHandler(fh)
    logger.info(f"Looking at metadata in {image_file}")
    for name,data in exifdict.items():
        tagname=TAGS.get(name,"unknown-tag")
        logger.info(f"Tag:{name} ({tagname}) is assigned {data}")
        if(tagname.__contains__("GPSInfo")):
            logger.info(f"Tag:{name} ({tagname}) is assigned {data}")
            logger.info(f"GPS data on image: {coordinates(imageobject)}")

def coordinates (ImageObject):
    info = ImageObject._getexif()

    latDegrees = info[34853][2][0][0]/float(info[34853][2][0][1])
    latMinutes = info[34853][2][1][0]/float(info[34853][2][1][0])/60
    latSeconds = info[34853][2][2][0]/float(info[34853][2][2][1])/3600
    lonDegrees = info[34853][4][0][0]/float(info[34853][4][0][1])
    lonMinutes = info[34853][4][1][0]/float(info[34853][2][0][1])/60
    lonSeconds = info[34853][4][2][0]/float(info[34853][2][0][1])/3600

    latitude = latDegrees + latMinutes +latSeconds
    if info[34853][1] == 'S':
        latitude*= -1
    longitude = lonDegrees + lonMinutes + lonSeconds
    if info[34853][3] == 'W':
        longitude*=-1
    return longitude,latitude

if __name__ == "__main__":
    #Enter your Image here
    user_input = input("I'll strip metadata from a jpeg. Give me a filepath to a jpeg or a directory and I'll attempt to strip meta data from it")
    if is_directory(user_input):
        # This is a directory
        filter_directory(user_input)
        pass
    else:
        if(check_file_format(user_input)):
            print_exif(user_input)
        else:
            print(f"Unfortunately, the file given is not a jpeg image")