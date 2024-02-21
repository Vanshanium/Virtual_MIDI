#include <SFML/Graphics.hpp>
#include<iostream>


using namespace sf;


int piano_x = 560, piano_y = 400;

// int draw_key()
// {
// }

Vector2f white_key_dem(76,400);

Vector2f black_key_dem(50,250);

Color key_white(245,255,255);
Color pressed_white(230,150,255);

Color key_black(40,40,45);



RectangleShape make_key(Vector2f dimensions,Color key_color,int x_pos,int y_pos = 0)
{
    RectangleShape key(dimensions); 

    key.move(x_pos,y_pos);
    key.setFillColor(key_color);

    return key;

}


int main()
{

    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");



    // Defining the White Keys.
    RectangleShape c4 = make_key(white_key_dem,key_white,2); 

    RectangleShape d4 = make_key(white_key_dem,key_white,82); 

    RectangleShape e4 = make_key(white_key_dem,key_white,162); 

    RectangleShape f4 = make_key(white_key_dem,key_white,242); 

    RectangleShape g4 = make_key(white_key_dem,key_white,322); 

    RectangleShape a4 = make_key(white_key_dem,key_white,402); 

    RectangleShape b4 = make_key(white_key_dem,key_white,482); 



    // Defing the Black Keys



    RectangleShape db = make_key(black_key_dem,key_black,55);

    RectangleShape eb = make_key(black_key_dem,key_black,135);

    RectangleShape gb = make_key(black_key_dem,key_black,295);

    RectangleShape ab = make_key(black_key_dem,key_black,375);

    RectangleShape bb = make_key(black_key_dem,key_black,455);




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