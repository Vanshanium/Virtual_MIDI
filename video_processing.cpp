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

vector<Point2f> selected_points;


void mouse_click(int event,int x,int y,int flags,void* userdata)
{
    if(event == EVENT_LBUTTONDOWN )
    {
        
        Mat& frame = *static_cast<Mat*>(userdata);

        selected_points.push_back(Point2f(x,y));
        circle(frame,Point2f(x,y),10,Scalar(100,0,255),-1);

        imshow("Point",frame);

        cout << selected_points << endl;
        
    }
}




void drawRectangle(Mat& image, const std::vector<Point2f>& points) {
    // Draw a rectangle using the selected points
    if (points.size() == 4) {
        for (int i = 0; i < 3; ++i)
            line(image, points[i], points[i + 1], Scalar(0, 255, 0), 2);
        line(image, points[3], points[0], Scalar(0, 255, 0), 2);
    }
}


// int warp(){

// }



/**
    @brief This Function Lets you the tracker to the Paper Piano.

If the bounding Box don't aligns well with the Paper....Then adjust the camera 
So You can 

    @param : VideoCapture Class Object. This is the same for the next function.
It gives the opject to send the video data to the cv.Matrix.
    @return : It return..//TO WRITE
*/



Rect region_of_interest(VideoCapture input_cap)
{
    //These defines the Color white which then makes the contour.
    int hmin = 170, smin = 87, vmin = 0;
    int hmax = 255,smax = 255,vmax = 255; 

    Scalar upper_bound(hmax,smax,vmax),lower_bound(hmin,smin,vmin);
    
    vector<vector<Point>> contours;

    cout << "Press q if you are the Paper is covered 100%" << endl;

    Rect output_rect;

    input_cap.read(frame);

    imshow("Point",frame);

    setMouseCallback("Point",mouse_click,&frame);
    
    waitKey();

    drawRectangle(frame,selected_points);

    imshow("See",frame);

    cout << "I am here!!! " << endl;

    // while(true)
    // {


    //     input_cap.read(frame); //Sends the frame data to the matrix

    //     inRange(frame,lower_bound,upper_bound,binary_mask); // Finds the color range and gives the binary image "binary_mask"


    //     //Finds Contours to the paper.
    //     findContours(binary_mask,contours,RETR_EXTERNAL,CHAIN_APPROX_NONE); 

    //     for (const auto& contour : contours) {
    //         // Ignore small contours
    //         if (contourArea(contour) < 100)
    //             continue;

    //         // Converts the contours to a rectangle.
    //         output_rect = boundingRect(contour);

    //         //Draws the Rectangle on the frame.
    //         rectangle(frame,output_rect,Scalar(100,250,0),10,-1);
            
    //     }
        
    //     imshow("ROI",frame);
    //     if(waitKey(20) == 'q'){
    //         break;            
    //     }
    
    // }
        
    //     string confirmation;
    //     cout << "Do you want to select the ROI manually!!" << endl;
    //     cin >>  confirmation;

    //     if(confirmation == "y"){
    //         output_rect = selectROI("ROI",frame);
    //     }

    cout << output_rect << endl;

    return output_rect;
}



void video_processing(VideoCapture input_cap)
{   

    input_cap.read(frame);

    // Crop the image here.

    // blur(frame,blured_frame,Size(15,15));
    // Canny(blured_frame,canny_frames,30,100);


    waitKey(1);

}



