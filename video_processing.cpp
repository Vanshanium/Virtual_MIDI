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
    }
}




void drawRectangle(Mat& image, const vector<Point2f>& points) {
    
    if (points.size() == 4) {
        for (int i = 0; i < 4; ++i)
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



void region_of_interest(VideoCapture input_cap)
{

    input_cap.read(frame);
    imshow("Target_Window",frame);
    waitKey();

    char frame_confirmation;

    char confirmation;

    cout << "Is the frame set correctly!! Y/N" << endl;
    cin >>  frame_confirmation;

    destroyWindow("Target_Window");

    if(frame_confirmation == 'Y' | 'y'){


        imshow("Point",frame);
        cout << "Press q after you have selected the four Points!" << endl;

        setMouseCallback("Point",mouse_click,&frame);
        
        if(waitKey() == 'q')
        {
            destroyWindow("Point");
            drawRectangle(frame,selected_points);
            imshow("See",frame);
            waitKey(10);

            cout << "Is this Retangle aligns with the Paper Piano!? Y/N" << endl;
            cin >> confirmation;

            if(confirmation == 'n'){
                
                cout << "Try Again!" << endl; 
                selected_points.clear();
                region_of_interest(input_cap);
            }
        
        }
    
    }
    else{
        region_of_interest(input_cap);
    }

    cout << "Region  of Interest Set perfectly!!!" << endl;
    destroyAllWindows();

}



void video_processing(VideoCapture input_cap)
{   

    input_cap.read(frame);

    // Crop the image here.

    // blur(frame,blured_frame,Size(15,15));
    // Canny(blured_frame,canny_frames,30,100);


    waitKey(1);

}



