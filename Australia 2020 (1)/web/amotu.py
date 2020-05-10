import turtle
import time 
turtle.bgcolor("purple")
turtle.pensize(4)
turtle.speed(0)

def cur():
	for i in range(200):
		turtle.right(1)
		turtle.forward(1)

turtle.speed(0)
turtle.color("red","red")
turtle.begin_fill()
turtle.left(140)
turtle.forward(111.65)
cur()

turtle.left(120)
cur()
turtle.forward(111.65)
turtle.end_fill()
time.sleep(10)
turtle.hideturtule()
