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


    @param : String - It takes in string of the note!
    @return : It return path of the given note!.
*/

string path_from_note(string note_name){

    char cwd[255];

    getcwd(cwd,sizeof(cwd));

    string parent_dir = dirname(cwd);

    return parent_dir + "/assets/Notes/" + note_name + ".wav";

}


/**
    @brief This is the algorithm that checks which key should be played!!!
    This is the worst way to do it(It have O(n)) But i had to give this code in 1 week so.....Who caresssss.
    I will make it cool with the OOPS and Binary search!

    @param : float x - The x-coordinate of the finger!
    @param : float y - The y-coordinate of the finger!

    @return : There is a void in from front of what can I return from the function huh!?
*/

void play_keys_from_cord(float x,float y,Key_class& key_obj){


    
    if(y < 125){                       // Checking for the black keys.
        
        // DB4
        if(27.5 < x && x < 52.5){

            key_obj.key_list[DB4].set_play();

        }
        else{

            key_obj.key_list[DB4].set_default();
        }

        // EB4
        if(67.5 < x && x < 92.5){

            key_obj.key_list[EB4].set_play();

        }
        else{

            key_obj.key_list[EB4].set_default();
        }

        // GB4
        if(147.5 < x && x < 172.5){

            key_obj.key_list[EB5].set_play();

        }
        else{

            key_obj.key_list[EB5].set_default();
        }

        //AB4
        if(187.5 < x && x < 212.5){

            key_obj.key_list[AB4].set_play();

        }
        else{

            key_obj.key_list[AB4].set_default();
        }

        //BB4
        if(227.5 < x && x < 252.5){

            key_obj.key_list[BB4].set_play();

        }
        else{

            key_obj.key_list[BB4].set_default();
        }
        
        //DB5
        if(307.5 < x && x < 332.5){

            key_obj.key_list[DB5].set_play();

        }
        else{

            key_obj.key_list[DB5].set_default();
        }
        
        //EB5
        if(347.5 < x && x < 372.5){

            key_obj.key_list[EB5].set_play();

        }
        else{

            key_obj.key_list[EB5].set_default();
        }

        //GB5
        if(427.5 < x && x < 452.5){

            key_obj.key_list[GB5].set_play();

        }
        else{

            key_obj.key_list[GB5].set_default();
        }

        //AB5
        if(467.5 < x && x < 492.5){

            key_obj.key_list[AB5].set_play();

        }
        else{

            key_obj.key_list[AB5].set_default();
        }

        //BB5
        if(507.5 < x && x < 532.5){

            key_obj.key_list[BB5].set_play();

        }
        else{

            key_obj.key_list[BB5].set_default();
        }

        //DB6
        if(587.5 < x && x < 612.5){

            key_obj.key_list[DB6].set_play();

        }
        else{

            key_obj.key_list[DB6].set_default();
        }

        //EB6
        if(627.5 < x && x < 652.5){

            key_obj.key_list[EB6].set_play();

        }
        else{

            key_obj.key_list[EB6].set_default();
        }

        //GB6
        if(707.5 < x && x < 732.5){

            key_obj.key_list[GB6].set_play();

        }
        else{

            key_obj.key_list[GB6].set_default();
        }

        //AB6
        if(747.5 < x && x < 772.5){

            key_obj.key_list[AB6].set_play();

        }
        else{

            key_obj.key_list[AB6].set_default();
        }

        //BB6 Atlast......Damn I will feel bad if some Mofo copied this code.
        if(787.5 < x && x < 812.5){

            key_obj.key_list[BB6].set_play();

        }
        else{

            key_obj.key_list[BB6].set_default();
        }

    }

    else{                             //Check for the white keys!

        // C4 Key.
        if(0 < x && x < 40 ){

            key_obj.key_list[C4].set_play();

        }
        else{

            key_obj.key_list[C4].set_default();
        }


        //D4 Key.
        if(40 < x && x < 80 ){

            key_obj.key_list[D4].set_play();
        }
        else{

            key_obj.key_list[D4].set_default();
        }

        // E4 Key
        if(80 < x && x < 120 ){

            key_obj.key_list[E4].set_play();
        }
        else{

            key_obj.key_list[E4].set_default();
        }

        // F4 Key
        if(120 < x && x < 160 ){

            key_obj.key_list[F4].set_play();
        }
        else{

            key_obj.key_list[F4].set_default();
        }

        // G4 Key
        if(160 < x && x < 200 ){

            key_obj.key_list[G4].set_play();
        }
        else{

            key_obj.key_list[G4].set_default();
        }

        // A4 Key
        if(200 < x && x < 240 ){

            key_obj.key_list[A4].set_play();
        }
        else{

            key_obj.key_list[A4].set_default();
        }

        // B4 Key
        if(240 < x && x < 280 ){

            key_obj.key_list[B4].set_play();
        }
        else{

            key_obj.key_list[B4].set_default();
        }

        // C5 Key
        if(280 < x && x < 320 ){

            key_obj.key_list[C5].set_play();
        }
        else{

            key_obj.key_list[C5].set_default();
        }

        // D5 Key
        if(320 < x && x < 360){

            key_obj.key_list[D5].set_play();
        }
        else{

            key_obj.key_list[D5].set_default();
        }

        // E5 Key
        if(360 < x && x < 400 ){

            key_obj.key_list[E5].set_play();
        }
        else{

            key_obj.key_list[E5].set_default();
        }

        // F5 Key
        if(400 < x && x < 440 ){

            key_obj.key_list[F5].set_play();
        }
        else{

            key_obj.key_list[F5].set_default();
        }

        // G5 Key
        if(440 < x && x < 480 ){

            key_obj.key_list[G5].set_play();
        }
        else{

            key_obj.key_list[G5].set_default();
        }

        // A5 Key
        if(480 < x && x < 520 ){

            key_obj.key_list[A5].set_play();
        }
        else{

            key_obj.key_list[A5].set_default();
        }

        // B5 Key
        if(520 < x && x < 560 ){

            key_obj.key_list[B5].set_play();
        }
        else{

            key_obj.key_list[B5].set_default();
        }

          // C6 Key
        if(560 < x && x < 600 ){

            key_obj.key_list[C6].set_play();
        }
        else{

            key_obj.key_list[C6].set_default();
        }

        // D6 Key
        if(600 < x && x < 640){

            key_obj.key_list[D6].set_play();
        }
        else{

            key_obj.key_list[D6].set_default();
        }

        // E6 Key
        if(640 < x && x < 680 ){

            key_obj.key_list[E6].set_play();
        }
        else{

            key_obj.key_list[E6].set_default();
        }

        // F6 Key
        if(680 < x && x < 720 ){

            key_obj.key_list[F6].set_play();
        }
        else{

            key_obj.key_list[F6].set_default();
        }

        // G6 Key
        if(720 < x && x < 760){

            key_obj.key_list[G6].set_play();
        }
        else{

            key_obj.key_list[G6].set_default();
        }

        // A6 Key
        if(760 < x && x < 800 ){

            key_obj.key_list[A6].set_play();
        }
        else{

            key_obj.key_list[A6].set_default();
        }

        // B6 Key
        if(800 < x && x < 840 ){

            key_obj.key_list[B6].set_play();
        }
        else{

            key_obj.key_list[B6].set_default();
        }
    }


// I wrote all this pal...

}