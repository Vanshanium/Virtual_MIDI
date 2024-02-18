import os
from time import sleep


# This imports and linkes the library directly!!!!
try:
    import cv2 as cv 
except ImportError:
    print("installing the Exteternall Dependency")
    os.system("pip install opencv-python")
    import cv2 as cv




Path = "https://192.168.29.122:8080/video"

cap = cv.VideoCapture()


cap.open(Path)

i = 1

sleep(5)

print("Recording Started!!!!")

while(True):

    success, frame = cap.read()
    
    cv.imshow("window",frame)
    cv.imwrite(f"frame-{i}.jpg",frame)
    cv.waitKey(20)
    i += 1