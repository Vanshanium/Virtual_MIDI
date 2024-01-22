#include<iostream>

#include<opencv4/opencv2/opencv.hpp>
#include"video_processing.h"

using namespace std;
using namespace cv;


int main()
{

    VideoCapture cap = preprocess();

    while(true)
    {

        video_processing(cap);

        
    }


    

}

