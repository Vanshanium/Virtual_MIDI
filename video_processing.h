#ifndef VIDEO_PROCESSING_H
#define VIDEO_PROCESSING_H

#include<opencv4/opencv2/opencv.hpp>
using namespace cv;

#include<Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>

#include"keyboard_processing.h"





/**
    @brief This Function Provides with the VideoCapture cap. 
    // Adjust the Ip to connect to your own network.

    TO DO : Write a adb script to install the ipsteam apk and open and start the stream!!! 

    @return : Returns the cap!.
*/

VideoCapture preprocess();

/**
    @brief This Function Lets you the tracker to the Paper Piano.

If the bounding Box don't aligns well with the Paper....Then adjust the camera 
So You can 

    @param : VideoCapture Class Object. This is the same for the next function.
It gives the opject to send the video data to the cv.Matrix.
    @return : It returns a warp matrix which is used to crops and warps the frame. 
*/

Mat region_of_interest(VideoCapture input_cap);


// Its Above code but made to reduce the redundance in Debugging.

Mat region_of_interest_1(VideoCapture input_cap);


/**
    @brief This function Inits the Python interpretor and finds the function inside of the python file.


    @param : NONE
    @return : PyObject* - returns the pointer to the interpreted python function. 
*/
PyObject* get_python();



/**
    @brief This is the core function that does everything!!!

    @param : VideoCapture - Cap from where the Video input is coming from! Read the Documentation of Opencv WTF are u reading
    @param : Mat - Persepective Wrapper matrix.
    @param : PyObject* - Pointer to the Interpertated Python Mediapipe function.
    @param : Key_class - send in the key command to play them.

    @return : It returns superman! // Stop reading it!!!

*/
void video_processing(VideoCapture input_cap,Mat warp_matrix,PyObject* mediapipe_function,Key_class& key_obj);


#endif