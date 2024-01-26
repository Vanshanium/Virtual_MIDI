#include<iostream>

#include<opencv4/opencv2/opencv.hpp>
#include"video_processing.h"

using namespace std;
using namespace cv;


int main()
{

    Mat image,image_colour_mask,hsv,g_blur,black_image,binary,canny_image;

    // VideoCapture cap = preprocess();

    // Mat crop = region_of_interest_1(cap);
    
    image = imopen("/home/vansha/Desktop/Project/Virtual_MIDI/operational/I")


    vector<vector<Point>> contours_array;


    //Best Values for the hsv inrange.
    int hmax = 179 ,smax = 60,vmax = 180;
    int hmin = 120,smin = 10,vmin = 120;

    // Best values for the rgb inrange.
    int a1 = 194, a2 = 196 ,  a3 = 233;
    int b1 = 126, b2 =  140, b3 = 161;

    Rect anime; 

    Mat kernel = getStructuringElement(MORPH_RECT, Size(6, 6));

    //Toggles for anyting You wanna do!.
    namedWindow("Anything");
    createTrackbar("a1", "Anything", &a1, 255);
    createTrackbar("a2", "Anything", &a2, 255);
    createTrackbar("a3", "Anything", &a3, 255);
    createTrackbar("b1", "Anything", &b1, 255);
    createTrackbar("b2", "Anything", &b2, 255);
    createTrackbar("b3", "Anything", &b3, 255);

    Scalar upper_bound(hmax,smax,vmax),lower_bound(hmin,smin,vmin);
    
    while(true){    

        Scalar upper(a1,a2,a3),lower(b1,b2,b3);

        cap.read(image);

        if(!image.empty()){ 


            warpPerspective(image,image,crop,Point(600,200));

            //Normal Image
            imshow("normal_image",image);
            waitKey(1);
            
            // cvtColor(image,image,COLOR_BGR2RGB);
            // imshow("rgb",image);
            // waitKey(1);


            // //Nails Detector.
            // cvtColor(image,hsv,COLOR_BGR2HSV);
            // imshow("HSV Image",hsv);
            // waitKey(1);

            inRange(image,lower,upper,black_image);

            // morphologyEx(black_image,black_image, MORPH_CLOSE, kernel);
            imshow("mask",black_image);   
            waitKey(1);


            // findContours(black_image,contours_array,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

            // for(auto contour: contours_array){ 
            //     if(contour.size() > area){
            //     anime = boundingRect(contour);
            //     rectangle(image,anime,Scalar(100,0,255),2);    
            //     }
            // }

            // imshow("Tracker",image);
            // waitKey(1);
            imwrite("Frame_1.jpg",image);


            if(waitKey(1) == 'q'){
                break;
            }

        }
    
    
    }

    destroyAllWindows();

    //VideoCapture cap = preprocess();

    // cap.read()

    // Mat crop_cord = region_of_interest(cap);

    // while(true)
    // {

    //     video_processing(cap,crop_cord);
        
    // }

}

