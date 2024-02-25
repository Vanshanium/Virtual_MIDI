import cv2 as cv
import hand_track


# cap = cv.VideoCapture(0)


frame = cv.imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg")

print(type(frame))

# success,frame = cap.read()

# frame = cv.cvtColor(frame,cv.COLOR_BGR2RGB)

hand_track.get_hands(frame)

cv.imshow("MOYEEE",frame)

cv.waitKey()


# while(True):
    
#     success, frame = cap.read()

#     frame = cv.cvtColor(frame,cv.COLOR_BGR2RGB)
    
#     hand_track.get_hands(frame)

#     cv.imshow("FuCk",frame)
    
#     if cv.waitKey(1) & 0xFF == ord('q'):
#             break



