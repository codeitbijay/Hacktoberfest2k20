import os
import shutil
import cv2

pathOrigin = '/Users/alanvictor/Desktop/mulheres'
pathDestiny = '/Users/alanvictor/Desktop/FotosSeparadas-Mulheres'


files = []
# r=root, d=directories, f = files
for r, d, f in os.walk(pathOrigin):
    for file in f:
        if '.jpg' in file:
            files.append(os.path.join(r, file))

for f in files:
    image = cv2.imread(f)
    h, w, c = image.shape
    nameFolder = str(w) + ' x ' + str(h)
    dirName = os.path.join(pathDestiny, nameFolder)
    if not os.path.exists(dirName):
        os.mkdir(dirName)
        print("Directory ", dirName, " Created ")
        shutil.move(f, dirName)
    else:
        print("Directory ", dirName, " already exists")
        shutil.move(f, dirName)