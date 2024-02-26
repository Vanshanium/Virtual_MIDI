#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>


using namespace sf;
using namespace std;



int piano_x = 560, piano_y = 400;


Vector2f white_key_dem(76,400);

Vector2f black_key_dem(50,250);

Color key_white(245,255,255);
Color pressed_white(175,225,190);  

Color key_black(40,40,45);
Color pressed_black(85,95,130);




// int main()
// {

//     RenderWindow piano(VideoMode(piano_x,piano_y),"Piano_window");

//     Key_class mykeys;

//     Event my_event;


//     // This is the main or game loop.
//     while(piano.isOpen())
//     {


//         // Listens for all the events!!! Lets fucking call it Event Loop!
//         // Works until there are events in the array
//         while(piano.pollEvent(my_event)){

//             if (my_event.type == Event::Closed)
//             {
//                 piano.close();
//             }


//             if(my_event.type == Event::KeyPressed){
                
//                 mykeys.key_check(my_event);
                
//                 }

//             if(my_event.type == Event::KeyReleased){
            
//                 mykeys.key_recheck(my_event);

//             }    
            

//             piano.clear();

//             mykeys.draw_keys(piano);

//             piano.display();


//         }


//     }
    
// }