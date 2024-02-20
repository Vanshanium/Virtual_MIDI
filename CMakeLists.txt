
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
)


# This trys to find the required libraries 
find_package(OpenCV REQUIRED)
find_package(SFML COMPONENTS graphics window system audio REQUIRED)

# And them set their paths to this variable
include_directories(${OpenCV_INCLUDE_DIR})


add_executable(exec ${SOURCE_FILES})

# This links those librabies Linking is done after making the object file!!
target_link_libraries(exec ${OpenCV_LIBS})


add_executable(key Key_learning.cpp)

target_link_libraries(key 
sfml-graphics
sfml-window
sfml-system)
