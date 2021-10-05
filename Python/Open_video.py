import numpy as np
import cv2 as cv
cap = cv.VideoCapture(0) # Doesn't open for any other value
if not cap.isOpened():
    print("Cannot open camera")
    exit()
while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # if frame is read correctly ret is True
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break

    # Display the resulting frame
    cv.imshow('frame', frame)
    k = cv.waitKey(1)   # Refresh rate
    # If waitKey == 0 then you get static image

    if k == ord('q'):    
        break

# When everything done, release the capture (close the webcam)
cap.release()
cv.destroyAllWindows()
