import matplotlib.pylab as plt
import cv2
import numpy as np

#input image
image = cv2.imread('road.jpg')


#converting to grayscale
gray_image = cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)
cv2.imwrite('grey.jpg',gray_image)

#gaussian blur
blur = cv2.GaussianBlur(gray_image,(5,5),0)
cv2.imwrite('blur.jpg',blur)

#canny edge detection
canny = cv2.Canny(blur, 220, 150)
cv2.imwrite('canny.jpg',canny)

#laplacian edge detection
laplacian = cv2.Laplacian(gray_image, -1)
cv2.imwrite('laplacian.jpg',laplacian)

#sobel edge detection
sobelx = cv2.Sobel(blur, -1,1,0)
sobely = cv2.Sobel(blur, -1,0,1)
sobelxy = cv2.addWeighted(sobelx, 0.5, sobely, 0.5, 0)
cv2.imwrite('sobel.jpg',sobelxy)

#Region Masking taking canny edge output

height=canny.shape[0]
width=canny.shape[1]

region_of_interest_vertices = [(0,height),(width/2,height/4),(width,height)]

def region_of_interest(img, vertices):
    mask = np.zeros_like(img)
    #channel_count = img.shape[2]
    match_mask_color = 255
    cv2.fillPoly(mask, vertices, match_mask_color)
    masked_image = cv2.bitwise_and(img, mask)
    return masked_image

cropped = region_of_interest(canny,np.array([region_of_interest_vertices],np.int32),)
cv2.imwrite('cropped.jpg',cropped)

#Hough Transform

def display_lines(img, lines):
 line_image= np.zeros_like(img)
 if lines is not None:
  for line in lines:
   for x1, y1, x2, y2 in line:
      cv2.line(line_image, (x1,y1), (x2,y2), (0, 255, 0), thickness=10)
 return line_image

lines= cv2.HoughLinesP(cropped,rho=6,theta=np.pi/180,threshold=80,lines=np.array([]),minLineLength=30,maxLineGap=30)
                                                                     
toRGB=cv2.cvtColor(cropped, cv2.COLOR_GRAY2BGR)
Hough = display_lines(toRGB,lines)
cv2.imwrite('Hough.jpg',Hough)

#combining with original image

source1 = cv2.imread('road.jpg')
source2 = cv2.imread('Hough.jpg')
combo_image= cv2.addWeighted(source1, 0.8, source2, 1, 1)
cv2.imwrite('final.jpg',combo_image)