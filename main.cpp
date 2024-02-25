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

    cout << "The interpretor is imported"<< endl;

    PyObject* python_code = PyImport_ImportModule("hand_track");


    if(python_code = NULL){

        cout<<"Not Openned"<<endl; 
        // PyObject* print_function = PyObject_GetAttrString(python_code,"print_something");
        // if(print_function = NULL){

        //     cout << "Error Getting the Function!" << endl;
        // }

    }    


    // PyObject_CallObject(print_function,NULL);


}
