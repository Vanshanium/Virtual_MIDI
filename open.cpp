#include<iostream>

#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{


    Mat img = imread("/home/vansha/Desktop/Project/Virtual_MIDI/test_image.jpg");

    Mat image = imread("/home/vansha/Desktop/Project/Virtual_MIDI/test_image.jpg",IMREAD_GRAYSCALE);

    if(image.empty())   
    {
        cout << "Image is not opened Properly.";
        
    };
    
    imshow("Window",img);

    waitKey();

    imshow("dst",image);

    waitKey();

    // bool result = imwrite("cat.jpg",image,third_param_2);

    // cout << result <<endl;


    

}

