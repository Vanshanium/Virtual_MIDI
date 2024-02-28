#ifndef KEYBOARD_PROCESSING_H
#define KEYBOARD_PROCESSING_H

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>


#include<X11/Xlib.h>
#include<X11/keysym.h>
#include<X11/extensions/XTest.h>


#include<unistd.h>
#include <libgen.h>


using namespace sf;
using namespace std;


extern int piano_x , piano_y ;


extern Vector2f white_key_dem;

extern Vector2f black_key_dem;

extern Color key_white;
extern Color pressed_white;  

extern Color key_black;
extern Color pressed_black;


string path_from_note(string note_name);



class Key_class{


private:

Keyboard::Key Keymapping[12] = {Keyboard::Num1,
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

class note{

public:

    RectangleShape shape;
    string key_type;
    Music* music_obj;

    bool isplayed = false;

    note(string type,int position,vector<note>& key_array,string note_path)
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
            
            shape.setFillColor(key_white);
        
        }
        else{
            
            shape.setFillColor(key_black);

        }
        music_obj->stop();

        isplayed = false;
        
    }

    void set_play(){

        if (!isplayed){

            if (key_type == "white"){
                
                shape.setFillColor(pressed_white);
            
            }
            else{
                
                shape.setFillColor(pressed_black);

            }

            music_obj->play();
            isplayed = true;

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
 
        note db4 ("black",55,key_list,"db4");
        note eb4 ("black",135,key_list,"eb4");
        note gb4 ("black",295,key_list,"gb4");
        note ab4 ("black",375,key_list,"ab4");
        note bb4 ("black",455,key_list,"bb4");

    }  
 


    // Write what does this do!
    void draw_keys(RenderWindow& window){

        for(note& key : key_list){

            window.draw(key.shape);
        }
    

    }

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


void trigger_key();


void release_key();

#endif