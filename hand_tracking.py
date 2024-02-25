import mediapipe as mp


mphands = mp.solutions.hands
hand_class = mphands.Hands()

def get_hands(image):

    finger_tip_indices = [4, 8, 12, 16, 20]
    output_array = []
    cords = []

    results = hand_class.process(image)
    
    i = 0

    for landmarks in results.multi_hand_landmarks: 

        for idx in finger_tip_indices:
            cords.append(landmarks.landmark[idx].x)    
            cords.append(landmarks.landmark[idx].y)

            output_array.append(cords)

            cords = []