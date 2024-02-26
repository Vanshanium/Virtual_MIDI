#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

#include"video_processing.h"
#include"keyboard_processing.h"


#include<Python.h>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>



#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>



using namespace std;
using namespace cv; 
using namespace sf;


int main()
{

    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");

    Key_class mykeys;

    Event my_event;


    PyObject* print_function = get_python();

    Mat input_image;
    VideoCapture cap = preprocess();

    Mat wrapper = region_of_interest_1(cap);


    while(true){


        input_image = video_processing(cap,wrapper);

        cvtColor(input_image,input_image,COLOR_BGR2RGB);

        get_fingers_landmark(print_function,input_image);

        cvtColor(input_image,input_image,COLOR_RGB2BGR);

        imshow("Drawn",input_image);


        while(piano.pollEvent(my_event)){

            if (my_event.type == Event::Closed)
            {
                piano.close();
            }


            if(my_event.type == Event::KeyPressed){
                
                mykeys.key_check(my_event);
                
                }

            if(my_event.type == Event::KeyReleased){
            
                mykeys.key_recheck(my_event);

            }    
            

            piano.clear();

            mykeys.draw_keys(piano);

            piano.display();

        }


        if(waitKey(20) == 'q'){
            break;
        }    

    }

}
