#include<iostream>
#include<opencv4/opencv2/opencv.hpp>
#include"video_processing.h"
#include<cstring>

using namespace std;
using namespace cv;


Mat frame,blured_frame,canny_frames,binary_mask;

VideoCapture preprocess()
{

    string Path = "https://192.168.29.122:8080/video";

    VideoCapture cap;

    cap.open(Path);
    
    return cap;

}

void region_of_interest(VideoCapture input_cap)
{
    
    int hmin = 170, smin = 87, vmin = 0;
    int hmax = 255,smax = 255,vmax = 255; 
    Scalar upper_bound(hmax,smax,vmax),lower_bound(hmin,smin,vmin);
    vector<vector<Point>> contours;
    
    cout << "This is done" << endl;

    while(true)
    {

    input_cap.read(frame);

    inRange(frame,lower_bound,upper_bound,binary_mask);

        
    findContours(binary_mask,contours,RETR_EXTERNAL,CHAIN_APPROX_NONE);

    for (const auto& contour : contours) {
        // Ignore small contours
        if (contourArea(contour) < 100)
            continue;

        Rect box = boundingRect(contour);

        rectangle(frame,box,Scalar(100,250,0),10,-1);
        
    }
    
    imshow("Detected Object",frame);
    waitKey(10);
    
    }
}



void video_processing(VideoCapture input_cap)
{   

    input_cap.read(frame);

    // Crop the image here.

    // blur(frame,blured_frame,Size(15,15));
    // Canny(blured_frame,canny_frames,30,100);
    imshow("Capture",frame);


    waitKey(20);

}



