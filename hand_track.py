import mediapipe as mp
import cv2 as cv
import ctypes
import numpy as np


mphands = mp.solutions.hands
hand_class = mphands.Hands()
draw = mp.solutions.drawing_utils


def print_something():
    print("Hey this code is working!")



def get_hands(image):

    results = hand_class.process(image)
    
    i = 0

    for marks in results.multi_hand_landmarks:
        for landmarks in marks:
            print(landmarks['x']",",landmarks['y'])




    


