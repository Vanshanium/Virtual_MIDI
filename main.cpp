#include<iostream>

#include<opencv4/opencv2/opencv.hpp>
#include"video_processing.h"

using namespace std;
using namespace cv;


int main()
{


    int hmax = 179 ,smax = 60,vmax = 180;
    int hmin = 120,smin = 10,vmin = 115;

    Mat image,image_colour_mask,hsv,g_blur,black_image,binary,dilate_image;

    VideoCapture cap = preprocess();
    
    Mat crop = region_of_interest_1(cap);

    // image = imread("/home/vansha/Desktop/Project/Virtual_MIDI/operational/frame.jpg");

    // cvtColor(image,hsv,COLOR_BGR2HSV);

    // imshow("Hsv",hsv);
    // waitKey();


    int t1 = 70,t2 = 90;
    

    // namedWindow("track");
    // createTrackbar("hmax","track",&hmax,255);
    // createTrackbar("hmin","track",&hmin,255);
    // createTrackbar("smax","track",&smax,255);
    // createTrackbar("smin","track",&smin,255);
    // createTrackbar("vmax","track",&vmax,255);
    // createTrackbar("vmin","track",&vmin,255);

    int g = 3;

    float sigma_x = 0.6;    
    float sigma_y = 0.2;
    int m = 1; 

    namedWindow("track");
    createTrackbar("dilate","track",&m,10);
    // createTrackbar("t1","track",&t1,200);
    // createTrackbar("t2","track",&t1,200);
    // createTrackbar("x","track",&x,10);
    // createTrackbar("y","track",&y,10);

    Mat kernal = getStructuringElement(0,Size(m,m));

    Scalar upper_bound(hmax,smax,vmax),lower_bound(hmin,smin,vmin);
    
    while(true){    

        kernal = getStructuringElement(0,Size(2,2));

        cap.read(image);

        if(!image.empty()){ 


            warpPerspective(image,image,crop,Point(600,200));

            //Normal Image
            imshow("normal_image",image);
            waitKey(1);
            

            // Gaussian Blur.
            // GaussianBlur(image,g_blur,Size(g,g),sigma_x,sigma_y);
            // imshow("gBlur",g_blur);
            // waitKey(1);


            // This gives the mask of the fingersss.
            Canny(image,image_colour_mask,t1,t2); 

            dilate(image_colour_mask,dilate_image,kernal);
            imshow("Canny",dilate_image);
            waitKey(1);



            //Nails Detector.
            cvtColor(image,hsv,COLOR_BGR2HSV);

            // imshow("HSV",hsv);
            // waitKey(1);

            inRange(hsv,lower_bound,upper_bound,black_image);

            imshow("mask",black_image);   


            bitwise_and(dilate_image,black_image,binary);

            imshow("Addition",binary);
            waitKey(1);

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

