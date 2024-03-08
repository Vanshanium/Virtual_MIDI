cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER g++)


set(SOURCE_FILES 
    main.cpp
    video_processing.cpp
    keyboard_processing.cpp
)

# This trys to find the required libraries 
find_package(OpenCV REQUIRED)
find_package(Python REQUIRED)


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
)

# IT adds -l with the variable provided!

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}) # Sends the output executable to the build file. where cmake is ran!

