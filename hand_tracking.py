import mediapipe as mp
import cv2 as cv


# Runs the test to initialize all the variables.
test_image = cv.imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg")
test_image = cv.cvtColor(test_image,cv.COLOR_BGR2RGB)





mphands = mp.solutions.hands
hand_class = mphands.Hands()                                     #This is the Hand Object from the mediapipe Read its Documentation.

results = hand_class.process(test_image)                         # Test Run to define Result. Saves 1 Fps


finger_tip_indices = [4, 8, 12, 16, 20]

finger_tip_indices = [4] # Play with only one key!



output_array = []
cords = []




#This is the function that working in the cpp 
# This takes in a image<Numpy array> and 

# Returns - 2d array of [[x,y],[x,y].......]


def get_hands(image):


    output_array = []                        # clears the output.
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