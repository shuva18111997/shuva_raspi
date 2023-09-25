import turtle as t
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

for i in range(10,100):
  t.stamp()
  t.forward(i+10)
  t.right(20)