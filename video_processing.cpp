#include<iostream>
#include<opencv4/opencv2/opencv.hpp>
#include"video_processing.h"
#include<cstring>

using namespace std;
using namespace cv;


Mat frame,warp_mat,warped_image;

vector<Point2f> selected_points;

float height = 200, width = 600;


VideoCapture preprocess()
{

    string Path = "https://192.168.29.122:8080/video";

    VideoCapture cap;

    cap.open(Path);
    
    return cap;

}

/**
    @brief This is also a call back function called to obtain the Perspective warp Matrix.

    @param : vector<Point2f> Takes in the Vector of the Points.
    @return : Perspective Matrix which is used with warpPerspective.
*/

Mat warpper(vector<Point2f> initial_points)
{
    Point2f target_points[4] = {{0.0f,0.0f},{width,0.0f},{0.0f,height},{width,height}};

    return warp_mat = getPerspectiveTransform(selected_points.data(),target_points);

}

/**
    @brief This is the Callback Function to be called with the setmousecallback() from opencv....

Here it takes the frame and lets the user draw points on the frame which then sent to the vector<Point2f> selected_points

    @param : int event  - Taken from the EVENT_LIST from the opencv
    @param : int x - x cordinate of the mouse.
    @param : int y - y cordinate of the mouse.
    @param : flags - I don't Even know what exactly is it !!!!.
    @param : void* Userdata - giving the refrence of the userdata for here it is the pointer to the Mat Image.

    @return : NULL
*/

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

/**
    @brief This Function Lets you the tracker to the Paper Piano.

If the bounding Box don't aligns well with the Paper....Then adjust the camera 
So You can 

    @param : VideoCapture Class Object. This is the same for the next function.
It gives the opject to send the video data to the cv.Matrix.
    @return : It returns a warp matrix which is used to crops and warps the frame. 
*/

Mat region_of_interest(VideoCapture input_cap)
{

    char frame_confirmation;
    char confirmation;

    input_cap.read(frame); //Reads the First Frame of the Video Stream.


    imshow("Target_Window",frame);
    waitKey(); //This is not working Fix it.

    cout << "Is the frame set correctly!! Y/N" << endl;
    cin >>  frame_confirmation;

    destroyWindow("Target_Window");

    if(frame_confirmation == 'Y' | 'y'){

        imshow("Point",frame);

        //Send the Frame to the Mouse click Function.
        setMouseCallback("Point",mouse_click,&frame);
       
        cout << "Select in the following order....\n1st - Top Left   2nd - Top Right\n3rd - Bottom Left   4th - Bottom Right" << endl;
        cout << "Press q after you have selected the four Points!" << endl;
        
        //Destroys the Point Window with q
        if (waitKey() == 'q')
            destroyWindow("Point");
    
    }

    warp_mat = warpper(selected_points);

    warpPerspective(frame,warped_image,warp_mat,Point(width,height)); //Warps the Image.

    imshow("Warped",warped_image); //Shows it Duhh...Why are you even Writing this.
    waitKey();
    
    cout << "Is the Image Croped and Warped Perfectly??" << endl;
    cin >> confirmation;

    if(confirmation == 'y'){

        cout << "Region  of Interest Set perfectly!!!" << endl;
        destroyAllWindows();

    }

    else{
        
        cout << "Try Again!" << endl; 
        selected_points.clear(); //Empties the seleted Point Vector
        region_of_interest(input_cap); //Recurtion Babyyyy.
    }

    return warp_mat;    
}

/**
    @brief This is the core function!!

    @param : //TO WRITE
    @return : //TO WRITE 
*/

void video_processing(VideoCapture input_cap,Mat warp_matrix)
{   

    input_cap.read(frame);

    if(!frame.empty()){

    warpPerspective(frame,warped_image,warp_matrix,Point(width,height));

    imshow("Capture",warped_image);
    waitKey(1);

    }
    else{
        cout << "Skiped Frame!!!" << endl;
    }

    // Crop the image here.

    // blur(frame,blured_frame,Size(15,15));
    // Canny(blured_frame,canny_frames,30,100);

}



