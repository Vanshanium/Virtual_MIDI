#ifndef KEYBOARD_PROCESSING_H
#define KEYBOARD_PROCESSING_H

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>


#include<unistd.h>
#include <libgen.h>


using namespace sf;
using namespace std;


extern int piano_x , piano_y ;       // Read the Defination from the key_processing.cpp.
extern Vector2f white_key_dem;       //I am not writing all that here as well.
extern Vector2f black_key_dem;
extern Color key_white;
extern Color pressed_white;  
extern Color key_black;
extern Color pressed_black;




/**
    @brief This Code is created to get the Path of the Notes from the assets folder.
            so, People like Ayush don't kill themselfs after coping this code!


    @param : String - It takes in string of the note!
    @return : It return path of the given note!.
*/

string path_from_note(string note_name);



/**
    @brief This is the first Class I have written and its damn cool.
    
    This Class made me love the OOPS

    @param : float x - The x-coordinate of the finger!
    @param : float y - The y-coordinate of the finger!

    @return : Dont go and see the structure of the function.....You will regret it.
*/



class Key_class{


private:


// remove this Keymapping too.


Keyboard::Key Keymapping[36] = {Keyboard::Num1,
Keyboard::Num2,
Keyboard::Num3,
Keyboard::Num4,
Keyboard::Num5,
Keyboard::Num6,
Keyboard::Num7,
Keyboard::Num8,
Keyboard::Num9,
Keyboard::Num0,
Keyboard::Q,
Keyboard::W,

};


// Classes inside of the class!!!!
// This is the power of Abstraction.
// This makes making a note a hell lot easier.



class note{

public:

    RectangleShape shape;
    string key_type;
    Music* music_obj;

    bool isplayed = false;


    // Note Class Constructor.

    note(string type,int position,vector<note>& key_array,string note_path)           // It takes in the vector and appends the note into it..
    {
        key_type = type;

        music_obj = new Music();

        music_obj->openFromFile(path_from_note(note_path));

        if (type == "white")
        {
            shape.setSize(white_key_dem);
            shape.setFillColor(key_white);

            shape.setPosition(position,0);


        }
        if(type == "black")
        {
            shape.setSize(black_key_dem);
            shape.setFillColor(key_black);

            shape.setPosition(position,0);

        }
        
        key_array.push_back(*this);
        // Now you get it now what this means in classes!

    }

    void set_default(){

        if (key_type == "white"){
            
            shape.setFillColor(key_white);                              // set the color to defualt
        
        }
        else{
            
            shape.setFillColor(key_black);

        }
        music_obj->stop();

        isplayed = false;
        
    }

    void set_play(){


        // This is the Logic right there!!!!!
        // If it is set to play then this lines won't gonna work
        // Hence the keys don't plays again and again and again........................................And it sounds horrifying


        if (!isplayed){

            if (key_type == "white"){
                
                shape.setFillColor(pressed_white);                       // Sets the color to played!!

            }
            else{
                
                shape.setFillColor(pressed_black);

            }

            music_obj->play();
            isplayed = true;                                                  // hash this line and know how!!!

        }

    }
        

};



public:
    
    vector<note> key_list;

    // I Don't Know but this objects are not being defined outside of this functions!

    Key_class()
    {

        // OOPS is Sexy!!!!!
        // why black keys are in minoriity ??????


        note c4 ("white",2,key_list,"c4");
        note d4 ("white",82,key_list,"d4");
        note e4 ("white",162,key_list,"e4");
        note f4 ("white",242,key_list,"f4");
        note g4 ("white",322,key_list,"g4");
        note a4 ("white",402,key_list,"a4");
        note b4 ("white",482,key_list,"b4");

        note c5 ("white",562,key_list,"c5");
        note d5 ("white",642,key_list,"d5");
        note e5 ("white",722,key_list,"e5");
        note f5 ("white",802,key_list,"f5");
        note g5 ("white",882,key_list,"g5");
        note a5 ("white",962,key_list,"a5");
        note b5 ("white",1042,key_list,"b5");

        note c6 ("white",1122,key_list,"c6");
        note d6 ("white",1202,key_list,"d6");
        note e6 ("white",1282,key_list,"e6");
        note f6 ("white",1362,key_list,"f6");
        note g6 ("white",1442,key_list,"g6");
        note a6 ("white",1522,key_list,"a6");
        note b6 ("white",1602,key_list,"b6");

        //Defining the black keys.
                                                // They are defined later as the white keys are underneath them
        note db4 ("black",55,key_list,"db4");
        note eb4 ("black",135,key_list,"eb4");
        note gb4 ("black",295,key_list,"gb4");
        note ab4 ("black",375,key_list,"ab4");
        note bb4 ("black",455,key_list,"bb4");

        note db5 ("black",615,key_list,"db5");
        note eb5 ("black",695,key_list,"eb5");
        note gb5 ("black",855,key_list,"gb5");
        note ab5 ("black",935,key_list,"ab5");
        note bb5 ("black",1015,key_list,"bb5");

        note db6 ("black",1175,key_list,"db6");
        note eb6 ("black",1255,key_list,"eb6");
        note gb6 ("black",1415,key_list,"gb6");
        note ab6 ("black",1495,key_list,"ab6");
        note bb6 ("black",1575,key_list,"bb6");
        

    }  
 


    // Write what does this do!
    void draw_keys(RenderWindow& window){
        
        // this is where I fell for OOPS 
        for(note& key : key_list){

            window.draw(key.shape);
        }
    

    }


    // remove these two functions

    void key_check(Event& event){

        int i = 0;
        for(Keyboard::Key& key_id : Keymapping){
            if(event.key.code == key_id){

                key_list[i].set_play();
                
            }
            i += 1;
        }
    }
    
    void key_recheck(Event& event){

        int i = 0;

        for(Keyboard::Key& key_id : Keymapping){
            if(event.key.code == key_id){

                key_list[i].set_default();
            }
            i += 1;
        }         
    }
    

};


/**
    @brief This is the algorithm that checks which key should be played!!!
    This is the worst way to do it(It have O(n)) But i had to give this code in 1 week so.....Who caresssss.
    I will make it cool with the OOPS and Binary search!

    @param : float x - The x-coordinate of the finger!
    @param : float y - The y-coordinate of the finger!

    @return : Dont go and see the structure of the function.....You will regret it.
*/

void play_keys_from_cord(float x,float y,Key_class &key_obj);



#endif