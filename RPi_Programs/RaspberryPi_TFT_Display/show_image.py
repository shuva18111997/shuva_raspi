

#!/usr/bin/env python3
import sys
import time

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

import ST7789


MESSAGE = "Hello World! How are you today?"

disp=ST7789.ST7789(port=0,cs=0,rst=5,dc=6,width=320,height=240,rotation=180,spi_speed_hz=60000000)  
disp._spi.mode=3  
disp.reset()  
disp._init()  

WIDTH = disp.width
HEIGHT = disp.height

# Initialize display.
disp.begin()

# Load an image.
print('Loading image')
image = Image.open("image.jpg")

# Resize the image
image = image.resize((WIDTH, HEIGHT))
#########################
font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 30)
draw = ImageDraw.Draw(image)

draw.text((100, 100), "Shuva", font=font, fill=(174, 214, 241))
#########################
# Draw the image on the display hardware.
print('Drawing image')

disp.display(image)