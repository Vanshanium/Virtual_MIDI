#include <SFML/Graphics.hpp>
#include<iostream>


using namespace sf;


int piano_x = 560, piano_y = 400;

// int draw_key()
// {


// }

Vector2f white_key_dem(80,400);
Vector2f black_key_dem(50,250);



int main()
{

    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");



    // Defining the White Keys.
    RectangleShape c4(white_key_dem); 

    RectangleShape d4(white_key_dem); 
    d4.move(white_key_dem.x,0);

    RectangleShape e4(white_key_dem); 
    e4.move(2*white_key_dem.x,0);
    
    RectangleShape f4(white_key_dem); 
    f4.move(3*white_key_dem.x,0);

    RectangleShape g4(white_key_dem);
    g4.move(4*white_key_dem.x,0);

    RectangleShape a4(white_key_dem);
    a4.move(5*white_key_dem.x,0);

    RectangleShape b4(white_key_dem); 
    b4.move(6*white_key_dem.x,0);
    b4.setFillColor(Color(200,100,0));


    // Defing the Black Keys

    RectangleShape db(black_key_dem);
    RectangleShape eb(black_key_dem);
    RectangleShape gb(black_key_dem);
    RectangleShape ab(black_key_dem);
    RectangleShape bb(black_key_dem);







    Event my_event;


    // This is the main or game loop.
    while(piano.isOpen())
    {


        // Listens for all the events!!!
        while(piano.pollEvent(my_event)){

            if (my_event.type == Event::Closed)
            {
                piano.close();
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
        

        piano.display();



    }
    
}