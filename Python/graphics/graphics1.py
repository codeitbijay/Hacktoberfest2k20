import turtle

t=turtle.Turtle()
s=turtle.Screen()
s.bgcolor("black")
t.pencolor("white")
colors=['cyan','magenta','white','yellow']
t.speed(0.5)
c=0
d=0
while True:
 for x in range(4):
   t.pencolor(colors[x%4])
   t.forward(90)
   t.right(90)
 t.right(15)
 c+=1
 if c>=390/15: 
    t.forward(50)
    c=0
    d+=1
    if d>=12:
      break

t.hideturtle()
turtle.done()