#include<iostream>
#include<opencv4/opencv2/opencv.hpp>
#include<opencv4/opencv2/tracking.hpp>
#include"video_processing.h"
#include<Python.h>

#include<chrono>


#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>

using namespace std;
using namespace cv; 

using namespace chrono;

int main()
{

    // Mat input_image = imread("/home/vansha/Desktop/Code/Virtual_MIDI/assets/test_hand_image.jpg");
    
    PyObject* print_function = get_python();

    Mat input_image;
    VideoCapture cap(0);


    int frameCount = 0;
    auto startTime = high_resolution_clock::now();
    



    while(true){

        cap.read(input_image);

        cvtColor(input_image,input_image,COLOR_BGR2RGB);


        get_fingers_landmark(print_function,input_image);

        imshow("Drawn",input_image);

        frameCount ++;

        auto endTime = high_resolution_clock::now();

        auto elapsedTime = duration_cast<seconds>(endTime - startTime).count();

        if (elapsedTime >= 1) {
            double fps = frameCount / static_cast<double>(elapsedTime);
            cout << "Frame rate: " << fps << " fps" << endl;

            // Reset variables for next interval
            frameCount = 0;
            startTime = high_resolution_clock::now();
        }

        if(waitKey(20) == 'q'){
            break;
        }    

    }

}
