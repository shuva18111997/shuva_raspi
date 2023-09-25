import ST7789  
from PIL import Image  
from time import sleep

display=ST7789.ST7789(port=0,cs=0,rst=5,dc=6,width=320,height=240,rotation=180,spi_speed_hz=60000000)  
display._spi.mode=3  
display.reset()  
display._init()
 
image=Image.new('RGB',(display.width, display.height),(255,0,0))  #('RGB',(240,240),(r,g,b))
display.display(image)  
sleep(2)  
image=Image.open("image.jpg")  
image=image.resize((display.width, display.height),resample=Image.LANCZOS)  
display.display(image)  
