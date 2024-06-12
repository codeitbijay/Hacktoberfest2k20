import turtle 
t=turtle.Turtle()
s=turtle.Screen()
s.bgcolor("black")
t.pencolor("white")
t.speed(100)

def shape(size,sides):
  for i in range(sides):
    t.forward(size)
    t.left(360/sides)
t.right(180)
t.penup()
t.forward(240)
t.left(90)
t.pendown()
t.left(90)
for j in range(18):
    for i in range(4):
        for colors in ['violet','indigo','blue','green','yellow','orange','red']:
           t.color(colors)
           shape(8,12)
           t.forward(10)
    t.left(90)
    t.forward(10)
    
    for i in range(4):
        for colors in ['violet','indigo','blue','green','yellow','orange','red']:
           t.color(colors)
           shape(8,12)
           t.forward(10)
    t.right(90)
    t.penup()
    t.forward(20)
    t.right(100)
    t.pendown()
for i in range(4):
        for colors in ['violet','indigo','blue','green','yellow','orange','red']:
           t.color(colors)
           shape(8,12)
           t.forward(10)
t.hideturtle()
turtle.done()
    
    