# cmake Refrence For OpenCV
# https://stackoverflow.com/questions/13970377/configuring-an-c-opencv-project-with-cmake

cmake_minimum_required(VERSION 3.10)

# This the name of the project(Duhhhhhhhh)



# Set function sets the variable to the value you give
# Like it sets the CMAKE__SHIT to g++

set(CMAKE_CXX_COMPILER g++)

include_directories(headers)  #This only looks for the header files.

add_subdirectory(src) # wherease add_subdirectory() tries to find cmakelist in that directory.