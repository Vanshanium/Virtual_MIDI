import mediapipe as mp
import cv2 as cv


# Runs the test to initialize all the variables.
test_image = cv.imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg")

test_image = cv.cvtColor(test_image,cv.COLOR_BGR2RGB)

mphands = mp.solutions.hands
hand_class = mphands.Hands()

results = hand_class.process(test_image)


finger_tip_indices = [4, 8, 12, 16, 20]

finger_tip_indices = [8]

output_array = []
cords = []



def get_hands(image):


    output_array = []
    cords = []

    results = hand_class.process(image)
    
    if results.multi_hand_landmarks:

        for landmarks in results.multi_hand_landmarks: 

            for idx in finger_tip_indices:
                cords.append(landmarks.landmark[idx].x)    
                cords.append(landmarks.landmark[idx].y)

                output_array.append(cords)

                cords = []

    return output_array