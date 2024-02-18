#include<iostream>

#include<opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(){

    dnn::Net tensor_net = dnn::readNetFromTensorflow("/home/vansha/Desktop/Code/Virtual_MIDI/neural_network/frozen_inference_graph.pb",
    "/home/vansha/Desktop/Code/Virtual_MIDI/neural_network/ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt");

    VideoCapture cap(0);

    Mat frame;


    while (true)
    {
        cap.read(frame);

        imshow("Video",frame);




        if(waitKey(20) == 'q'){
            destroyAllWindows();
            break;
        }

    }
    
    




}