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

    Mat input_image = imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg");


    cvtColor(input_image,input_image,COLOR_BGR2RGB);

    Py_Initialize();

    PyObject* python_code = PyImport_ImportModule("hand_tracking");

    cout << "lets see if the code detecting the python file" << python_code << endl;

    PyObject* cvt_img = ConvertImageToNumpy(input_image);

    // If you write .py then this next if statement won't gonna work!

    if(python_code != NULL){

        cout << "The module is found!!!!" << endl;

        PyObject* print_function = PyObject_GetAttrString(python_code,"get_hands");

        PyObject* result = PyObject_CallFunctionObjArgs(print_function,cvt_img,NULL);
        
        if(PyList_Check(result)){


            int size = PyList_Size(result);

            for(int i = 0;i < size; ++i){




                PyObject* inner_cord = PyList_GetItem(result,i);

                float x = PyFloat_AS_DOUBLE(PyList_GetItem(inner_cord,0));
                float y = PyFloat_AS_DOUBLE(PyList_GetItem(inner_cord,1));


                cout << "These are the cordinates from the c code "<< x << "," << y << endl;
                circle(input_image,Point((int)(940*x),(int)(530*y)),5,Scalar(100,222,100),-1);

            
            
            
            }
        
        
        }
    
        imshow("Drawn",input_image);
        waitKey();
    }

    Py_Finalize();

    
}
