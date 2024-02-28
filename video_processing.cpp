#include<iostream>
#include<opencv4/opencv2/opencv.hpp>

#include"video_processing.h"
#include"keyboard_processing.h"

#include<Python.h>                                    //To Call Python Functions in this code!!

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include<numpy/ndarrayobject.h>                       // To convert the Mat images into Numpy array.



using namespace std;
using namespace cv;


Mat frame,warp_mat,warped_image;

vector<Point2f> selected_points;


float height = 200, width = 840;


PyObject* numpy_array;     // Used in the ImageToNumpy()

PyObject* python_result;    //These are pointers i have to alloctate them!!!!!



//Used in get finger cordinate function.
int output_array_size;               
float x;
float y;


npy_intp dimensions[3] = {(int)height, (int)width, 3}; // This is used in Mat to Numpy conversion. 








/**
    @brief This Function Provides with the VideoCapture cap. 
    // Adjust the Ip to connect to your own network.

    TO DO : Write a adb script to install the ipsteam apk and open and start the stream!!! 

    @return : Returns the cap!.
*/

VideoCapture preprocess()
{

    string Path = "https://192.168.29.122:8080/video";

    VideoCapture cap;

    cap.open(Path);

    if(!cap.isOpened()){
        cout << "There is a problem getting the Video Data from the Source!!!" << endl;
    }
    
    return cap;

}

/**
    @brief This Function converts the Mat file into the Numpy Array to send in the python module function.
    // This Function should be called after the 

    // Python Uses numpy array as a image.

    @param : cv::Matimage - Takes in the Mat of c++
    @return : Returns the Numpy array for the python function argument.
*/

PyObject* ImageToNumpy(const Mat& image) {

    return PyArray_SimpleNewFromData(3, dimensions, NPY_UINT8, image.data);
}

/**
    @brief This is also a call back function called to obtain the Perspective warp Matrix.
    https://pavcreations.com/how-to-pass-rgb-image-data-from-opencv-c-to-python/ --- This is where i got this code from!

    // Do these two lines of code manually to reduce redundancy!

    @param : vector<Point2f> Takes in the Vector of the Points.
    @return : Perspective Matrix which is used with warpPerspective.
*/

Mat warpper(vector<Point2f> initial_points)
{
    Point2f target_points[4] = {{0.0f,0.0f},{width,0.0f},{0.0f,height},{width,height}};

    return warp_mat = getPerspectiveTransform(initial_points.data(),target_points);

}

/**
    @brief This is the Callback Function to be called with the setmousecallback() from opencv....

Here it takes the frame and lets the user draw points on the frame which then sent to the vector<Point2f> selected_points

    @param : int event  - Taken from the EVENT_LIST from the opencv
    @param : int x - x cordinate of the mouse.
    @param : int y - y cordinate of the mouse.
    @param : flags - I don't Even know what exactly is it !!!!.
    @param : void* Userdata - giving the refrence of the userdata for here it is the pointer to the Mat Image.

    @return : NULL
*/

void mouse_click(int event,int x,int y,int flags,void* userdata)
{
    if(event == EVENT_LBUTTONDOWN )
    {
        
        Mat& frame = *static_cast<Mat*>(userdata);

        selected_points.push_back(Point2f(x,y));
        circle(frame,Point2f(x,y),10,Scalar(100,0,255),-1);

        imshow("Point",frame);
    }
}

/**
    @brief This Function Lets you the tracker to the Paper Piano.

If the bounding Box don't aligns well with the Paper....Then adjust the camera 
So You can 

    @param : VideoCapture Class Object. This is the same for the next function.
It gives the opject to send the video data to the cv.Matrix.
    @return : It returns a warp matrix which is used to crops and warps the frame. 
*/

Mat region_of_interest(VideoCapture input_cap)
{

    char frame_confirmation;
    char confirmation;

    input_cap.read(frame); //Reads the First Frame of the Video Stream.


    imshow("Target_Window",frame);
    waitKey(); //This is not working Fix it.

    cout << "Is the frame set correctly!! Y/N" << endl;
    cin >>  frame_confirmation;

    destroyWindow("Target_Window");

    if(frame_confirmation == 'Y' | 'y'){

        imshow("Point",frame);

        //Send the Frame to the Mouse click Function.
        // It is a loop I guess, You can make n numbers of points.
        
        setMouseCallback("Point",mouse_click,&frame);
       
        cout << "Select in the following order....\n1st - Top Left   2nd - Top Right\n3rd - Bottom Left   4th - Bottom Right" << endl;
        cout << "Press q after you have selected the four Points!" << endl;
        
        //Destroys the Point Window with q
        if (waitKey() == 'q')
            destroyWindow("Point");
    
    }

    warp_mat = warpper(selected_points); //Define the selected Points inside of the function Scope.


    warpPerspective(frame,warped_image,warp_mat,Point(width,height)); //Warps the Image.

    imshow("Warped",warped_image); //Shows it Duhh...Why are you even Writing this.
    waitKey();
    
    cout << "Is the Image Croped and Warped Perfectly??" << endl;
    cin >> confirmation;

    if(confirmation == 'y'){

        cout << "Region  of Interest Set perfectly!!!" << endl;
        destroyAllWindows();

    }

    else{
        
        cout << "Try Again!" << endl; 
        selected_points.clear(); //Empties the seleted Point Vector
        region_of_interest(input_cap); //Recurtion Babyyyy.
    }

    return warp_mat;    
}


Mat region_of_interest_1(VideoCapture input_cap)
{

    char frame_confirmation = 'y';
    char confirmation = 'y';

    input_cap.read(frame); //Reads the First Frame of the Video Stream.


    // imshow("Target_Window",frame);
    // waitKey(); //This is not working Fix it.

    // cout << "Is the frame set correctly!! Y/N" << endl;
    // cin >>  frame_confirmation;

    // destroyWindow("Target_Window");

    if(frame_confirmation == 'Y' | 'y'){

        imshow("Point",frame);

        //Send the Frame to the Mouse click Function.
        setMouseCallback("Point",mouse_click,&frame);
       
        cout << "Select in the following order....\n1st - Top Left   2nd - Top Right\n3rd - Bottom Left   4th - Bottom Right" << endl;
        cout << "Press q after you have selected the four Points!" << endl;
        
        //Destroys the Point Window with q
        if (waitKey() == 'q')
            destroyWindow("Point");
    
    }

    warp_mat = warpper(selected_points);

    warpPerspective(frame,warped_image,warp_mat,Point(width,height)); //Warps the Image.

    // imshow("Warped",warped_image); //Shows it Duhh...Why are you even Writing this.
    // waitKey();
    
    // cout << "Is the Image Croped and Warped Perfectly??" << endl;
    // cin >> confirmation;

    if(confirmation == 'y'){

        cout << "Region  of Interest Set perfectly!!!" << endl;
        destroyAllWindows();

    }

    else{
        
        cout << "Try Again!" << endl; 
        selected_points.clear(); //Empties the seleted Point Vector
        region_of_interest(input_cap); //Recurtion Babyyyy.
    }

    return warp_mat;    
}


/**
    @brief This function Inits the Python interpretor and finds the function inside of the python file.


    @param : NONE
    @return : PyObject* - returns the pointer to the interpreted python function. 
*/

PyObject* get_python(){

    Py_Initialize();                           //Inits python interpretor.
    import_array();                            //Inits Numpy.

    PyObject* python_code = PyImport_ImportModule("hand_tracking");     // opens hand_tracking.py 


    //imports only the python module, so you can't write .py
    // Make sure to include the current working directory to get this module.
    // run preinstall.sh as source.


    if(python_code != NULL){

        PyObject* get_hand_function = PyObject_GetAttrString(python_code,"get_hands");

        return get_hand_function;

    }
    else{

        cout << "ERROR OPENING PYTHON MODULE!!!" << endl;
        return NULL;

    }

}


/**
    @brief This is the core function!! This gets the finger cordinates using mediapipe from the python module


    @param : Pyobject* - It takes in the pointer to the python function obtain from the get_python()
    @param : Mat Image - It takes in the Mat image from opencv.

    @return : It return a array of array (2d array) of x,y cordinates of the fingers.
*/

void get_fingers_landmark(PyObject* mediapipe_function,Mat input_image,Key_class& key_obj){

    python_result = PyObject_CallFunctionObjArgs(mediapipe_function,ImageToNumpy(input_image),NULL);    

    output_array_size = PyList_Size(python_result);

    for(int i = 0;i < output_array_size; ++i){


        PyObject* inner_cord = PyList_GetItem(python_result,i);

        x = (PyFloat_AS_DOUBLE(PyList_GetItem(inner_cord,0)))*width;
        y = (PyFloat_AS_DOUBLE(PyList_GetItem(inner_cord,1)))*height;


        circle(input_image,Point((int)x,(int)y),10,Scalar(100,222,100),-1);

        play_keys_from_cord(x,y,key_obj);

    }

}



/**
    @brief This is the core function that does everything!!!

    @param : VideoCapture - Cap from where the Video input is coming from! Read the Documentation of Opencv WTF are u reading
    @param : Mat - Persepective Wrapper matrix.
    @param : PyObject* - Pointer to the Interpertated Python Mediapipe function.
    @param : Key_class - send in the key command to play them.

    @return : It returns superman! // Stop reading it!!!

*/


void video_processing(VideoCapture input_cap,Mat warp_matrix,PyObject* mediapipe_function,Key_class& key_obj)
{   

    input_cap.read(frame);

    if(!frame.empty()){

        warpPerspective(frame,frame,warp_matrix,Point(width,height));

        cvtColor(frame,frame,COLOR_BGR2RGB);                                           // Convert the image to RGB send to the Mediapipe.

        get_fingers_landmark(mediapipe_function,frame,key_obj);

        cvtColor(frame,frame,COLOR_RGB2BGR);

        imshow("Drawn",frame);


    }
    else{
        cout << "Skiped Frame!!!" << endl;
        destroyAllWindows();
    }

}



