#include"video_processing.h"
#include"keyboard_processing.h"

int main()
{   

    PyObject* print_function = get_python();           // Initiates the Python Interpretor.

    VideoCapture cap = preprocess();                  // Go read about it in Video_processing.cpp

    Mat wrapper = region_of_interest_1(cap);          // Generates the matrix to crop and wrap the image.


    
    //  To define the The Virtual Keyboard
    
    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");
    Key_class mykeys;
    Event my_event;


    while(true){

        video_processing(cap,wrapper,print_function,mykeys);             // This does the magic

        while(piano.pollEvent(my_event)){

            if (my_event.type == Event::Closed)
            {
                piano.close();
                break;
            }

        }

        piano.clear();

        mykeys.draw_keys(piano);                                     // This draws the Virtual Piano

        piano.display();

        if(waitKey(20) == 'q'){
            break;
        }    

    }


}
