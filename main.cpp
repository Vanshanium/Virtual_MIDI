#include<iostream>

#include<opencv4/opencv2/opencv.hpp>
#include<opencv4/opencv2/tracking.hpp>
#include"video_processing.h"
#include<python3.10/Python.h>

using namespace std;
using namespace cv;


int main()
{
    Mat input_image = imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg");

    Py_Initialize();

    PyObject* python_code = PyImport_ImportModule("hand_track.py");

    if(python_code = NULL){

        cout<<"Not Open!!!"<<endl; 

    }    


}
