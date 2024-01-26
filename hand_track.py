import mediapipe as mp
import cv2 as cv 

hand_class = mp.solutions.hands.Hands()

Path = "https://192.168.29.122:8080/video"

cap = cv.VideoCapture()

mpDraw = mp.solutions.drawing_utils


cap.open(Path)

while(True):

    success, frame = cap.read()
    

    frame_rgb = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
    
    results = hand_class.process(frame_rgb)

    if(results.multi_hand_landmarks):
        for ass in results.multi_hand_landmarks:
            mpDraw.draw_landmarks(frame_rgb,ass)


    cv.imshow("window",frame_rgb)

    cv.waitKey(20)
