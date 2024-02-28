#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

#include"keyboard_processing.h"

#include<X11/Xlib.h>
#include<X11/keysym.h>
#include<X11/extensions/XTest.h>



#include<unistd.h>
#include <libgen.h>


using namespace sf;
using namespace std;



int piano_x = 560, piano_y = 400;


Vector2f white_key_dem(76,400);

Vector2f black_key_dem(50,250);

Color key_white(245,255,255);
Color pressed_white(175,225,190);  

Color key_black(40,40,45);
Color pressed_black(85,95,130);


string path_from_note(string note_name){

    char cwd[255];

    getcwd(cwd,sizeof(cwd));

    string parent_dir = dirname(cwd);

    return parent_dir + "/assets/Notes/" + note_name + ".wav";

}




void trigger_key(){

    Display* display = XOpenDisplay(NULL);

    XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_1), True, 0);
    XFlush(display);
    // XCloseDisplay(display);

}

void release_key(){

    Display* display = XOpenDisplay(NULL);

    XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_1), False, 0);
    XFlush(display);
    // XCloseDisplay(display);

}

