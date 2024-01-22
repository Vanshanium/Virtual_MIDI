#include<iostream>
#include<opencv4/opencv2/opencv.hpp>
#include"video_processing.h"
#include<cstring>

using namespace std;
using namespace cv;


char base[32] = "frame-";
char extension[32] = ".jpg";
char filename[100];
char number_str[100];

Mat frame,blured_frame,canny_frames;

VideoCapture preprocess()
{

    string Path = "https://192.168.29.122:8080/video";

    VideoCapture cap;

    cap.open(Path);
    
    return cap;

}

int i = 0;

void video_processing(VideoCapture input_cap)
{   

    memset(filename,0,sizeof(filename));

    strcat(filename,base);

    i += 1;

    sprintf(number_str,"%d",i);

    strcat(filename,number_str);

    strcat(filename,extension);

    input_cap.read(frame);


    // blur(frame,blured_frame,Size(15,15));
    // Canny(blured_frame,canny_frames,30,100);
    imshow("Capture",frame);

    waitKey(20);
    imwrite(filename,frame);


}


