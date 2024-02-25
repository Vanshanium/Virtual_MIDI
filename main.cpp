#include<iostream>
#include<opencv4/opencv2/opencv.hpp>
#include<opencv4/opencv2/tracking.hpp>
#include"video_processing.h"
#include<Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>

using namespace std;
using namespace cv; 


int main()
{

    Mat input_image = imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg");

    cvtColor(input_image,input_image,COLOR_BGR2RGB);

    PyObject* print_function = get_python();

    get_fingers_landmark(print_function,input_image);

    imshow("Drawn",input_image);
    waitKey();
    

    Py_Finalize();

    
}
