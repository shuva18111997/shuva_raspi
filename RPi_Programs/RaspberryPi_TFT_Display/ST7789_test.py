import ST7789  
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
from time import sleep

display=ST7789.ST7789(port=0,cs=0,rst=5,dc=6,width=320,height=240,rotation=180,spi_speed_hz=60000000)  
display._spi.mode=3  
display.reset()  
display._init()

image=Image.new('RGB',(320,240),(0,0,0))  #('RGB',(240,240),(r,g,b))
font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 30)
draw = ImageDraw.Draw(image)

draw.text((0, 0), "Shuva", font=font, fill=(255, 255, 255))
draw.text((0, 50), "Saikat", font=font, fill=(255, 255, 255))
display.display(image)
sleep(2)