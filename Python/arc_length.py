#Python program to find the arc length of the angle.

##import math package 
import math

#function to calculate the arc length.
def arclength():
    # take inputs
    d= float(input("Enter the diameter of circle: "))
    a = float(input("Enter the angle value: "))
    # check the angle value 
    if a >= 360:
        print("Invalid angle")
        return
    #calculate the arc length
    arc_length = (math.pi*d) * (a/360)
    print("Arc Length : %.2f" %arc_length)

arclength()
