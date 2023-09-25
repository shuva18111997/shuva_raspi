import turtle as t

t.width(2)
t.speed(10)

for i in range(10):
  t.color("red")
  t.circle(100)
  t.right(90)
  t.color("yellow")
  t.circle(100)
  t.right(90)
  t.color("blue")
  t.circle(100)
  t.right(90)
  t.color("lime")
  t.circle(100)
  t.right(70)

t.hideturtle()