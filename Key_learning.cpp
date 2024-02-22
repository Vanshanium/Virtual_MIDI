#include <SFML/Graphics.hpp>
#include<iostream>


using namespace sf;
using namespace std;



int piano_x = 560, piano_y = 400;


Vector2f white_key_dem(76,400);

Vector2f black_key_dem(50,250);

Color key_white(245,255,255);
Color pressed_white(230,150,255);

Color key_black(40,40,45);


class Key_class{

private:

RectangleShape make_key(Vector2f dimensions,Color key_color,int x_pos,int y_pos = 0)
{
    RectangleShape key(dimensions); 

    key.move(x_pos,y_pos);
    key.setFillColor(key_color);

    return key;

}

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
    string type;

    note(string type,string sound,int position)
    {
        if (type == "white")
        {
            shape.setSize(white_key_dem);
            shape.setPosition(position,0);

        }
        
    }

};



public:
    
    vector<RectangleShape> key_list;

    vector<RectangleShape> white_keys;

    vector<RectangleShape> black_keys;


    // I Don't Know but this objects are not being defined outside of this functions!

    Key_class()
    {

        //Defines all the white keys.
        // Whites are defined first.
        // Because they are in majority!!!!???

        RectangleShape c4 = make_key(white_key_dem,key_white,2); 
        key_list.push_back(c4);
        white_keys.push_back(c4);

        RectangleShape d4 = make_key(white_key_dem,key_white,82); 
        key_list.push_back(d4);
        white_keys.push_back(c4);

        RectangleShape e4 = make_key(white_key_dem,key_white,162); 
        key_list.push_back(e4);
        white_keys.push_back(c4);

        RectangleShape f4 = make_key(white_key_dem,key_white,242); 
        key_list.push_back(f4);
        white_keys.push_back(c4);

        RectangleShape g4 = make_key(white_key_dem,key_white,322); 
        key_list.push_back(g4);
        white_keys.push_back(c4);

        RectangleShape a4 = make_key(white_key_dem,key_white,402); 
        key_list.push_back(a4);
        white_keys.push_back(c4);

        RectangleShape b4 = make_key(white_key_dem,key_white,482); 
        key_list.push_back(b4);
        white_keys.push_back(c4);

        // Defining the Black Keys after whites
        // Because they are in minority!

        RectangleShape db = make_key(black_key_dem,key_black,55);
        key_list.push_back(db);
        black_keys.push_back(db);


        RectangleShape eb = make_key(black_key_dem,key_black,135);
        key_list.push_back(eb);
        black_keys.push_back(eb);
        
        RectangleShape gb = make_key(black_key_dem,key_black,295);
        key_list.push_back(gb);
        black_keys.push_back(gb);

        RectangleShape ab = make_key(black_key_dem,key_black,375);
        key_list.push_back(ab);
        black_keys.push_back(ab);

        RectangleShape bb = make_key(black_key_dem,key_black,455);
        key_list.push_back(bb);
        black_keys.push_back(bb);
    
    }  



    // Write what does this do!
    void draw_keys(RenderWindow& window){

        for(RectangleShape& note : key_list){

            window.draw(note);
        }
    

    }

    void key_check(Event& event){

        int i = 0;
        for(Keyboard::Key& key_id : Keymapping){
            if(event.key.code == key_id){

                key_list[i].setFillColor(pressed_white);
            }
            i += 1;
        }
    }
    
    void key_recheck(Event& event){

        int i = 0;
        for(Keyboard::Key& key_id : Keymapping){
            if(event.key.code == key_id){

                key_list[i].setFillColor(key_white);
            }
            i += 1;
        }         
    }
    

};




int main()
{

    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");

    Key_class mykeys;

    Event my_event;


    // This is the main or game loop.
    while(piano.isOpen())
    {


        // Listens for all the events!!! Lets fucking call it Event Loop!
        // Works until there are events in the array
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


    }
    
}