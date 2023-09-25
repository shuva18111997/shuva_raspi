import cv2
import numpy as np

def detect_lanes(frame):
    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Apply Gaussian blur to reduce noise
    blur = cv2.GaussianBlur(gray, (5, 5), 0)

    # Apply Canny edge detection to detect edges
    edges = cv2.Canny(blur, 50, 150)

    # Define the region of interest (ROI)
    mask = np.zeros_like(edges)
    height, width = edges.shape
    vertices = np.array([[(0, height), (width/2, height/2), (width, height)]], dtype=np.int32)
    cv2.fillPoly(mask, vertices, 255)
    masked_edges = cv2.bitwise_and(edges, mask)

    # Apply Hough Transform to detect lines
    lines = cv2.HoughLinesP(masked_edges, 1, np.pi/180, 15, np.array([]), minLineLength=4, maxLineGap=20)

    # Draw the detected lines on a blank image
    line_image = np.zeros((height, width, 3), dtype=np.uint8)
    for line in lines:
        x1, y1, x2, y2 = line[0]
        cv2.line(line_image, (x1, y1), (x2, y2), (0, 255, 0), 5)

    # Combine the line image with the original frame
    combo_image = cv2.addWeighted(frame, 0.8, line_image, 1, 0)

    return combo_image

cap = cv2.VideoCapture('input_video.mp4')


while cap.isOpened():
    ret, frame = cap.read()
    if ret:
        result = detect_lanes(frame)
        cv2.imshow('Lane Detection', result)
        if cv2.waitKey(1) == ord('q'):
            break
    else:
        break

cap.release()
cv2.destroyAllWindows()
