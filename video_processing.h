#ifndef VIDEO_PROCESSING_H
#define VIDEO_PROCESSING_H

#include<opencv4/opencv2/opencv.hpp>
using namespace cv;

#include<Python.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>

#include"keyboard_processing.h"


VideoCapture preprocess();

Mat region_of_interest(VideoCapture input_cap);

Mat region_of_interest_1(VideoCapture input_cap);

Mat video_processing(VideoCapture input_cap,Mat warp_matrix);

PyObject* ImageToNumpy(const Mat& image);

PyObject* get_python();

void get_fingers_landmark(PyObject* mediapipe_function,Mat input_image,Key_class key_obj);

#endif