#include<iostream>

#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{

                

    Mat image, bi_image , blur_image , box_image, frame;

    // image = imread("/home/vansha/Desktop/Project/Virtual_MIDI/test_image.jpg");

    // if(image.empty())   
    // {
    //     cout << "Image is not opened Properly.";
        
    // };
    
    // // Showing the normal Image!
    // imshow("dst",image);
    // waitKey();
    

    // // Bilateral FIlter to the input Image
    // bilateralFilter(image,bi_image,10,300,300);
    // imshow("bilateral",bi_image);
    // waitKey();
    
    // imwrite("Bilateral_cat.jpg",bi_image);


    // // Blur to the input Image!!!

    // blur(image,blur_image,Size(15,15));
    // imshow("Blur",blur_image);
    // waitKey();

    // imwrite("blure_cat.jpg",blur_image);

    // //Box filter

    // boxFilter(image,box_image,1,Size(15,15));
    // imshow("Boxed",box_image);

    // imwrite("Boxed_cat.jpg",box_image);

    // lets try video input output

    string path = "https://192.168.29.122:8080/video";

    VideoCapture cap;

    cap.open(0);

    while(true)
    {

        cap.read(frame);

        imshow("capture",frame);

        waitKey(10);

    }


    

}

