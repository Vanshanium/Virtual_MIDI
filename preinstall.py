import os

if (os.name == "posix"):
    os.system("sudo apt install libopencv-dev") #Open CV library
    os.system("sudo apt install g++") # G++ Compilier
    os.system("sudo apt install cmake")
    os.system("sudo apt install libsfml-dev")#Installs the SFML lib

if(os.name == "nt"):
    os.system("vcpkg install opencv")

