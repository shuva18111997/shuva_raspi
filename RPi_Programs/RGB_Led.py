import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

red = 3
green = 5
blue = 7

GPIO.setup(red, GPIO.OUT)
GPIO.setup(green, GPIO.OUT)
GPIO.setup(blue, GPIO.OUT)


while True:
	GPIO.output(red,False)
	GPIO.output(green,True)
	GPIO.output(blue,True)
	time.sleep(0.5)
	GPIO.output(red,True)
	GPIO.output(green,False)
	GPIO.output(blue,True)
	time.sleep(0.5)
	GPIO.output(red,True)
	GPIO.output(green,True)
	GPIO.output(blue,False)
	time.sleep(0.5)
