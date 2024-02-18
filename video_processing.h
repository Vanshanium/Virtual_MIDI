#ifndef VIDEO_PROCESSING_H
#define VIDEO_PROCESSING_H

#include<opencv4/opencv2/opencv.hpp>
using namespace cv;

VideoCapture preprocess();


Mat region_of_interest(VideoCapture input_cap);

Mat region_of_interest_1(VideoCapture input_cap);

Mat video_processing(VideoCapture input_cap,Mat warp_matrix);



#endif