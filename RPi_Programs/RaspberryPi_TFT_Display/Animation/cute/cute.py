# GIF to JPG convertion link:- https://image.online-convert.com/convert/gif-to-jpg

import sys
import time

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

import ST7789

disp=ST7789.ST7789(port=0,cs=0,rst=5,dc=6,width=220,height=220,rotation=180,spi_speed_hz=60000000)  
disp._spi.mode=3  
disp.reset()  
disp._init()  

delay = 0.500

WIDTH = disp.width
HEIGHT = disp.height

# Initialize display.
disp.begin()

# Load an image.
print('Loading image')
image = []

for i in range(5):
    image.append(Image.open("cute/cute-%s.jpg" %i))
    # Resize the image
    image[i] = image[i].resize((WIDTH, HEIGHT))


print('Drawing image')

while(1):
    for i in range(5):
        disp.display(image[i])
        time.sleep(delay)
    
    
    
    
    
    
    
    
    
    
    
    
    
    