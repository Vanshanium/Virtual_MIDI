import mediapipe as mp
import cv2 as cv 

hand_class = mp.solutions.hands.Hands()

Path = "https://192.168.29.122:8080/video"

cap = cv.VideoCapture()

cap.open(Path)

while(True):

    success, frame = cap.read()

    cv.imshow("window",frame)

    cv.waitKey(1)
