import mediapipe as mp

mphands = mp.solutions.hands
hand_class = mphands.Hands()
draw = mp.solutions.drawing_utils


def get_hands(image):
    
    results = hand_class.process(image)

    if results.multi_hand_landmarks:
        
        for marks in results.multi_hand_landmarks:
    
            print("Yesss!!")
            # draw.draw_landmarks(image,marks)




    


