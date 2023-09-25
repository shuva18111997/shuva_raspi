import turtle as t

wn = t.Screen()
wn.bgcolor("black")

t.width(2)
t.speed(0)

t.color("red")
for i in range(0,50):
  t.circle(i*3)
  t.left(10)

t.color("yellow")
for i in range(50,0,-1):
  t.circle(i*3)
  t.left(10)
t.reset()

count=0
wn = t.Screen()
wn.bgcolor("lightgreen")

t.color("blue")
t.width(2)
t.speed(0)

while (count<300):
  t.left(90)
  t.forward(count)
  count=count+2

t.hideturtle()