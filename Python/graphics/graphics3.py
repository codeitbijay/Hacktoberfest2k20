from turtle import *
speed(0)
bgcolor('black')
##r,g,b=255,0,0
r=[128,0,210,128,0,255]
g=[0,128,0,210,255,255]
b=[0,128,128,0,210,255]



for i in range(255*2):
 colormode(255)
 
 fd(50+i)
 rt(91)
 pencolor(r[i%6],g[i%6],b[i%6])

hideturtle()
turtle.done()