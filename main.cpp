#include<iostream>

#include<opencv4/opencv2/opencv.hpp>
#include<opencv4/opencv2/tracking.hpp>
#include"video_processing.h"

using namespace std;
using namespace cv;


int main()
{

    VideoCapture raw_cap;
    raw_cap.open("/home/vansha/Desktop/Code/Virtual_MIDI/operational/test.mp4");

    Mat crop_matrix = region_of_interest_1(raw_cap); 


    Mat frame_1 = video_processing(raw_cap,crop_matrix);  

    imshow("frame-1",frame_1);

    Rect box_trac = selectROI("frame-1",frame_1);

    Ptr<Tracker> tracker_obj = TrackerCSRT::create();

    tracker_obj->init(frame_1,box_trac);


    while(true){

        frame_1 = video_processing(raw_cap,crop_matrix);
        tracker_obj->update(frame_1,box_trac);

        rectangle(frame_1,box_trac,Scalar(255,0,0));

        imshow("Tracking",frame_1);
        
        waitKey(30);
 
    }




}


    // //Best Values for the hsv inrange.
    // int hmax = 179 ,smax = 60,vmax = 180;
    // int hmin = 120,smin = 10,vmin = 120;

    // // Best values for the rgb inrange.
    // int a1 = 194, a2 = 196 ,  a3 = 233;
    // int b1 = 126, b2 =  140, b3 = 161;