#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

#include<unistd.h>
#include <libgen.h>



#include"keyboard_processing.h"

using namespace sf;
using namespace std;





                                 // SFML Piano Dimensions.

int piano_x = 1680, piano_y = 400;


                                 // SFML Key Dimensions

Vector2f white_key_dem(76,400);
Vector2f black_key_dem(50,250);

                                // Key Colors.(I know the spelling of color angry bird!)

Color key_white(245,255,255);
Color pressed_white(175,225,190);  

Color key_black(40,40,45);
Color pressed_black(85,95,130);




// Enum to Map the keys used in play_keys_from_cord()!
// It is not that initiutional to know the keys from 0 and 1 while debugging! 
// Why am I being so sarcastic to myself.

enum Note_enum {

    // Defining Whites First.(I am racist!)

    C4,D4,E4,F4,G4,A4,B4,
    C5,D5,E5,F5,G5,A5,B5,
    C6,D6,E6,F6,G6,A6,B6,

    // Black are minors!(Its the music theory that is racist!)

    DB4,EB4,GB4,AB4,BB4,
    DB5,EB5,GB5,AB5,BB5,
    DB6,EB6,GB6,AB6,BB6,

};



/**
    @brief This Code is created to get the Path of the Notes from the assets folder.
            so, People like Ayush don't kill themselfs after coping this code!


    @param : Pyobject* - It takes in the pointer to the python function obtain from the get_python()
    @param : Mat Image - It takes in the Mat image from opencv.

    @return : It return a array of array (2d array) of x,y cordinates of the fingers.
*/

string path_from_note(string note_name){

    char cwd[255];

    getcwd(cwd,sizeof(cwd));

    string parent_dir = dirname(cwd);

    return parent_dir + "/assets/Notes/" + note_name + ".wav";

}


void play_keys_from_cord(float x,float y,Key_class& key_obj){

    cout << "This is the y value!!!" << y << endl;

    // C4 Key.
    if(0 < x && x < 40 ){

        key_obj.key_list[C4].set_play();

    }
    else{

        key_obj.key_list[C4].set_default();
    }

    // DB4


    // if( x < 105 && 150 < y){

    //     key_obj.key_list[DB4].set_play();
    // }
    // else{

    //     key_obj.key_list[DB4].set_default();
    // }

    //D4 Key.
    if(40 < x && x < 80 ){

        key_obj.key_list[1].set_play();
    }
    else{

        key_obj.key_list[1].set_default();
    }

    // E4



}