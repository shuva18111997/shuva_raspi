import turtle as t
import random

wn = t.Screen()
wn.bgcolor("lightgreen")

t.color("blue")
t.width(2)
t.speed(10)
t.shape("turtle")
t.penup()

t.left(90)
t.forward(50)
t.right(90)

while True:
  if(random.choice([0,1])==0):
    t.right(90)
  else:
    t.left(90)
  t.forward(100)