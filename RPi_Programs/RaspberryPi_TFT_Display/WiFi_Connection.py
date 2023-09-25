import subprocess as sp
import sys
import time

import RPi.GPIO as GPIO

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

import ST7789

disp=ST7789.ST7789(port=0,cs=0,rst=5,dc=6,width=320,height=240,rotation=180,spi_speed_hz=60000000)  
disp._spi.mode=3  
disp.reset()  
disp._init()  

WIDTH = disp.width
HEIGHT = disp.height

image_location = "/home/pi/Documents/RPi_Programs/RaspberryPi_TFT_Display/image.jpg"

# Initialize display.
disp.begin()

font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 30)

WiFi_Name = ""
Host_name = ""

LCD_Switch = 26
Power_Switch = 7

GPIO.setup(LCD_Switch, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(Power_Switch, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    if((len(WiFi_Name) < 1) or (len(Host_name) < 1)):
        image = Image.open(image_location)
        image = image.resize((WIDTH, HEIGHT))
        draw = ImageDraw.Draw(image)
        draw.text((50, 100), "No Connection", font=font, fill=(255, 0, 0))
        disp.display(image)
        while((len(WiFi_Name) < 1) or (len(Host_name) < 1)):
            WiFi_Name = sp.getoutput("iw dev wlan0 link | grep SSID | awk '{print $2}'")
            Host_name = sp.getoutput("hostname -I").split(" ")[0]
            if GPIO.input(LCD_Switch) == GPIO.LOW:
                image = Image.open(image_location)
                image = image.resize((WIDTH, HEIGHT))
                draw = ImageDraw.Draw(image)
                draw.text((70, 60), "Good Bye ☺", font=font, fill=(255, 255, 0))
                draw.text((20, 100), "Turning LCD OFF", font=font, fill=(255, 0, 0))
                disp.display(image)
                time.sleep(3)
                image=Image.new('RGB',(320,240),(0,0,0))
                disp.display(image)
                sp.getoutput("sudo pkill -f WiFi_Connection.py")
                
            if GPIO.input(Power_Switch) == GPIO.LOW:
                image = Image.open(image_location)
                image = image.resize((WIDTH, HEIGHT))
                draw = ImageDraw.Draw(image)
                draw.text((70, 60), "Good Bye ☺", font=font, fill=(255, 255, 0))
                draw.text((40, 100), "RPi Shut Down", font=font, fill=(255, 0, 0))
                disp.display(image)
                sp.getoutput("sudo poweroff")

    if((len(WiFi_Name)) and (len(Host_name))):
        image = Image.open(image_location)
        image = image.resize((WIDTH, HEIGHT))
        draw = ImageDraw.Draw(image)
        draw.text((0, 40), "Connected with", font=font, fill=(255, 0, 0))
        draw.text((0, 80), "WiFi: ", font=font, fill=(0, 0, 255))
        draw.text((90, 80), WiFi_Name, font=font, fill=(174, 214, 241))
        draw.text((20, 120), Host_name, font=font, fill=(255, 255, 0))
        disp.display(image)
        while((WiFi_Name == sp.getoutput("iw dev wlan0 link | grep SSID | awk '{print $2}'")) and (Host_name == sp.getoutput("hostname -I").split(" ")[0])):
            if GPIO.input(LCD_Switch) == GPIO.LOW:
                image = Image.open(image_location)
                image = image.resize((WIDTH, HEIGHT))
                draw = ImageDraw.Draw(image)
                draw.text((70, 60), "Good Bye ☺", font=font, fill=(255, 255, 0))
                draw.text((20, 100), "Turning LCD OFF", font=font, fill=(255, 0, 0))
                disp.display(image)
                time.sleep(3)
                image=Image.new('RGB',(320,240),(0,0,0))
                disp.display(image)
                sp.getoutput("sudo pkill -f WiFi_Connection.py")
                
            if GPIO.input(Power_Switch) == GPIO.LOW:
                image = Image.open(image_location)
                image = image.resize((WIDTH, HEIGHT))
                draw = ImageDraw.Draw(image)
                draw.text((70, 60), "Good Bye ☺", font=font, fill=(255, 255, 0))
                draw.text((40, 100), "RPi Shut Down", font=font, fill=(255, 0, 0))
                disp.display(image)
                sp.getoutput("sudo poweroff")
                
        WiFi_Name = ""
        Host_name = ""

"""
import os

WiFi_Name = os.popen("iw dev wlan0 link | grep SSID | awk '{print $2}'").read()

if "debi" in WiFi_Name:
    print("exist")
else:
    print("not exist")
#####################################################################################
import subprocess as sp

WiFi_Name = sp.getoutput("iw dev wlan0 link | grep SSID | awk '{print $2}'")
"""
