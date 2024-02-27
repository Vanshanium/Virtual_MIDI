
# cmake refrence - https://stackoverflow.com/questions/13970377/configuring-an-c-opencv-project-with-cmake

cmake_minimum_required(VERSION 3.10)


# This the name of the project(Duhhhhhhhh)

project(virtual_midi)


# Set function sets the variable to the value you give
# Like it sets the CMAKE__SHIT to g++

set(CMAKE_CXX_COMPILER g++)



set(SOURCE_FILES 
    main.cpp
    video_processing.cpp
    keyboard_processing.cpp
)


# This trys to find the required libraries 
find_package(OpenCV REQUIRED)
find_package(Python REQUIRED)

# This finds the path to the header files.
include_directories(${OpenCV_INCLUDE_DIR}
${Python_INCLUDE_DIR})

link_libraries(${Python3_LIBRARIES})

add_executable(exec ${SOURCE_FILES})

# This links those librabies Linking is done after making the object file!!
# This gives the path to the .so files!


target_link_libraries(exec 
${OpenCV_LIBS}
python3.10 
sfml-graphics
sfml-window
sfml-system
sfml-audio
X11
Xtst)

# IT adds -l with the variable provided!

