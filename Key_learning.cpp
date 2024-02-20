#include <SFML/Graphics.hpp>
#include<iostream>


using namespace sf;


int piano_x = 600, piano_y = 200;



int main()
{

    RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");

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

        // piano.draw(balls);

        piano.display();



    }
    
}