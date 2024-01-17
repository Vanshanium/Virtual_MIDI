/*
This is commented code!!!!!(If you forget what it is called in future Vansh...)
*/

/*

#(Directive see the figma)
Some of them also called header guards.....

:: is called the scope resolution operator this is use to access the members 
of a class (attributes and methods) or a namespace.

>> and << this are bit shift left and right operator...You what they do!!
but in std namespace the << and >> is overloaded/overide to do something else...

if condition only checks if the variable is equalls to zero or not and if its not 
zero it considers it to be true!!!

*/


#include "anything.cpp"

#include <iostream> 

/*

iostream is a header file. header files are diffrent then normal files they 
contain only the decleration of functions and variables not the code.
The code is stored in precompiled files like .so files or sometimes
in moduler code(when you work in modules) in .cpp/.c files.

*/

class imaginary_number
{

public: 

    int real;
    int imaginary;

    imaginary_number(int a,int b)
    {
        real = a;
        imaginary = b;
    }

    void print()
    {
        std::cout << real << "+" << imaginary << "i" << std::endl;
    }    

};



int main()
{

    imaginary_number num(1,78);

    num.print();

}
