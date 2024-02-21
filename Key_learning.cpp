#include <SFML/Graphics.hpp>
#include<iostream>


using namespace sf;
using namespace std;


int number_of_keys = 7;

int piano_x = 560, piano_y = 400;


Vector2f white_key_dem(76,400);

Vector2f black_key_dem(50,250);

Color key_white(245,255,255);
Color pressed_white(230,150,255);

Color key_black(40,40,45);


class key{
    

}


RectangleShape make_key(Vector2f dimensions,Color key_color,int x_pos,int y_pos = 0)
{
    RectangleShape key(dimensions); 

    key.move(x_pos,y_pos);
    key.setFillColor(key_color);

    return key;

}


void pressed_key_check()
{



}



int main()
{

    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");


    vector<RectangleShape> all_keys(number_of_keys);


    // Defining the White Keys.
    RectangleShape c4 = make_key(white_key_dem,key_white,2); 
    all_keys.push_back(c4);

    RectangleShape d4 = make_key(white_key_dem,key_white,82); 
    all_keys.push_back(d4);

    RectangleShape e4 = make_key(white_key_dem,key_white,162); 
    all_keys.push_back(e4);

    RectangleShape f4 = make_key(white_key_dem,key_white,242); 
    all_keys.push_back(f4);

    RectangleShape g4 = make_key(white_key_dem,key_white,322); 
    all_keys.push_back(g4);

    RectangleShape a4 = make_key(white_key_dem,key_white,402); 
    all_keys.push_back(a4);

    RectangleShape b4 = make_key(white_key_dem,key_white,482); 
    all_keys.push_back(b4);



    // Defing the Black Keys



    RectangleShape db = make_key(black_key_dem,key_black,55);
    all_keys.push_back(b4);


    RectangleShape eb = make_key(black_key_dem,key_black,135);

    RectangleShape gb = make_key(black_key_dem,key_black,295);

    RectangleShape ab = make_key(black_key_dem,key_black,375);

    RectangleShape bb = make_key(black_key_dem,key_black,455);


    Keyboard::Key Keymapping[number_of_keys];

    Keymapping[0] = Keyboard::Num1;
    Keymapping[1] = Keyboard::Num2;
    Keymapping[2] = Keyboard::Num3;
    Keymapping[3] = Keyboard::Num4;
    Keymapping[4] = Keyboard::Num5;
    Keymapping[5] = Keyboard::Num6;
    Keymapping[6] = Keyboard::Num7;








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
                
                if(my_event.key.code == Keyboard::Q){
                    
                    c4.setFillColor(pressed_white);
                    
                }
                if(my_event.key.code == Keyboard::W){
                    
                    d4.setFillColor(pressed_white);
                    
                }
            
            }

            if(my_event.type == Event::KeyReleased){
            
                if(my_event.key.code == Keyboard::Q){
                        
                        c4.setFillColor(key_white);
                        
                    }
                    if(my_event.key.code == Keyboard::W){
                        
                        d4.setFillColor(key_white);
                        
                    }
            
            }    
            



            piano.clear();

            piano.draw(c4);
            piano.draw(d4);
            piano.draw(e4);
            piano.draw(f4);
            piano.draw(g4);
            piano.draw(a4);
            piano.draw(b4);

            piano.draw(db);
            piano.draw(eb);
            piano.draw(gb);
            piano.draw(ab);
            piano.draw(bb);



            piano.display();


        }


    }
    
}