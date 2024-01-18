
# cmake refrence - https://stackoverflow.com/questions/13970377/configuring-an-c-opencv-project-with-cmake

cmake_minimum_required(VERSION 3.10)

project(virtual_midi)

set(CMAKE_CXX_COMPILER g++)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR})


add_executable(executable open.cpp)

target_link_libraries(executable ${OpenCV_LIBS})