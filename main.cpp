#include<iostream>

#include<opencv4/opencv2/opencv.hpp>
#include<opencv4/opencv2/tracking.hpp>
#include"video_processing.h"
#include<Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>

using namespace std;
using namespace cv; 



PyObject* ConvertImageToNumpy(const Mat& image) {

    import_array();

    npy_intp dimensions[3] = {image.rows, image.cols, image.channels()};

    PyObject* array = PyArray_SimpleNewFromData(3, dimensions, NPY_UINT8, image.data);
    
    return array;
}



int main()
{


    cout << "AAAAAAAAAAAAAAAAAAAAA" << endl;

    Mat input_image = imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg");


    cvtColor(input_image,input_image,COLOR_BGR2RGB);

    Py_Initialize();

    
    PyObject* python_code = PyImport_ImportModule("hand_track");

    PyObject* cvt_img = ConvertImageToNumpy(input_image);

    // If you write .py then this next if statement won't gonna work!

    if(python_code != NULL){

        cout << "The module is found!!!!" << endl;

        PyObject* print_function = PyObject_GetAttrString(python_code,"get_hands");

        PyObject* result = PyObject_CallFunctionObjArgs(print_function,cvt_img,NULL);
        
    }

    Py_Finalize();

    
}
