#!/bin/bash

# Installing the Packages

#This is only for linux....so


sudo apt install -y libopencv-dev

sudo apt install -y g++

sudo apt install -y cmake 

sudo apt install -y libsfml-dev

sudo apt install python3-pip

pip install opencv-python

pip install mediapipe 

pip install numpy

export PYTHONPATH=$(pwd)
export CPLUS_INCLUDE_PATH=/usr/include/python3.10/

mkdir build/
cd ./build/
cmake ..
make 
./exec

