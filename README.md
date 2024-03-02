<h1 align="center">Virtual Midi</h1>

<p align="center">This is the coolest thing I have ever worked on! The First Module is complete now, I can play the paper Piano from the fingers.Now for the next module I am planning to train a <strong>neural network</strong> that give me precise <strong>location</strong> of the finger and a <strong>bool</strong> that it is touching the surface or not!</p>

I Used **C++** merely because of the **speed** as **Python** is known for it **snail** like pace, But this could have been a piece of cake if I had done in Python.Yet whats the fun with the easy approach.

I had to complete the project to demostrate **ASAP** so I just used the Mediapipe Library in Python and Embedded it in the **C++**(This was the worst part of the Project) Instead of manually building it for **c++** using **Bazel**.


## How to run it.

    Note - I used all the cross-platform libraries(I neglected a linux library and took the harder approuch) but i know how to build and run it in linux so.........


 

### - Run directly 

- First Install **IP webcam** app in your mobile device available in - 

        /assets/ipwebcam.apk

- To run it directly in the linux, Just run this command in the cloned directory.

        source ./preinstall.sh

- To build it from the source code - first install 


                            Linux Commands

        - OpenCV            sudo apt install libopencv-dev 
        - cmake             sudo apt install cmake
        - G++               sudo apt install g++
        - Python3           sudo apt install python3 
        - Pip               sudo install python3-pip
        - Mediapipe         pip install mediapipe
        - SFML              sudo apt install libsfml-dev
        - Numpy             pip install numpy
        - Opencv Python     pip install opencv-python


    - Now You can configure the CMakeLists to link the required libraries if not linked correctly

    - Make a new Directory **"build"** in the cloned directory

            cd ./build
            cmake ..
            make

            Run the ipweb in the mobile and start the server then

            run the ./exec file.


    - If Python.h is not located then export the Path variables like this(Paste this line of code in yout home/.bashrc)

            
            export PYTHONPATH=$(CWD) 
            export CPLUS_INCLUDE_PATH=/usr/include/python3.10/

    - Some linux install pip installations seprately, If you can't locate Numpyarray.h (I used it to convert C++ opencv Mat to Python Numpy array (I Hate myself) )

            export CPLUS_INCLUDE_PATH= path/to/required/header/file/

