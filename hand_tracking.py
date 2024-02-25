import mediapipe as mp


mphands = mp.solutions.hands
hand_class = mphands.Hands()
draw = mp.solutions.drawing_utils

def get_hands(image):

    results = hand_class.process(image)
    
    i = 0

    for marks in results.multi_hand_landmarks:
        for landmarks in marks:
            print("benkelode")




    


