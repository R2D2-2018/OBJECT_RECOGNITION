/**
 * @brief This file contains the video controller class
 * @details This video controller is used to display videos or record some from a camera
 * @file video_controller.hpp
 * @author Arsalan Anwari
 * @date 2018-05-24
 */

#ifndef VIDEO_VIEWER_HPP
#define VIDEO_VIEWER_HPP

#include "interface/gui.hpp"
#include "../image/image.hpp"
#include "../image/root_image.hpp"
#include <functional>
#include <string>

namespace lucidy{

/**
 * @brief This variable is used a static constant which decides if recorded video feed should be displayed inside a window
 */
const bool SHOW_VIDEO_FEED = true;

/**
 * @brief VideoController class
 */
class VideoController : public Gui{
private:
    RootImageList recordFeed; /// This variable contains all the recored footage as a list of root images
    cv::VideoCapture recorder; /// This variable contains the recorder object for the camera
    Cameras cameraNr; // This variable is used to specify which camera should be used

    /**
     * @brief This function is used as CLI interface that prompts the user to input a image path 
     * @details Feed back is givin on the currently inputed value. This value will be converted to a cv::String
     * @return cv::String 
     */
    cv::String requestPath();
    
    /**
     * @brief This function is used to display a frame inside a gui window
     * @details a frame is pulled from a video feed
     * @param cam : used to pull a frame from a video feed file
     * @param frame : the frame container 
     * @return true : the exitkey has been pressed
     * @return false : the exitkey has not been pressed
     */
    bool displayFrame(cv::VideoCapture & cam, cv::Mat & frame);
    
    /**
     * @brief This function is used to save a frame insde a image container
     * @details a frame is pulled from a video feed 
     * @param cam : used to pull a frame from a video feed file
     * @param frame : the frame container 
     * @return true : the exitkey has been pressed
     * @return false : the exitkey has not been pressed
     */
    bool saveFrame(cv::VideoCapture & cam, cv::Mat & frame);
    
    /**
     * @brief This function is used to save a frame insde a image container and display it inside a gui window
     * @details a frame is pulled from a video feed 
     * @param cam : used to pull a frame from a video feed file
     * @param frame : the frame container 
     * @return true : the exitkey has been pressed
     * @return false : the exitkey has not been pressed
     */
    bool displayAndSaveFrame(cv::VideoCapture & cam, cv::Mat & frame);

public:

    VideoController();
    VideoController(settings::WIN::GUI::VIW::data & settings);

    /**
     * @brief This function is used as a way to ask the user to input a video feed path. 
     * @details This video feed ptah can then be looked up and the video feed will display inside a gui window
     * The user will get continously prompted to insert an video feed path untill the image path is correct.
     */
    void show();

    /**
     * @brief This function is used to show an video feed from a specific file path. 
     * @details The function can check if an invalid path is given and show an error
     * @param path : char* const
     */
    void show(const char* path);

    /**
     * @brief This function is used to show a image list as a video feed inside the gui window. 
     * @details This video feed will be shown once
     * @param feed : &ImageList
     */
    void show(ImageList & feed);
    
    /**
     * @brief This function is used to show a image list as a video feed inside the gui window.
     * @details This video feed will be shown once or in a loop depending on user input
     * @param feed : &ImageList
     * @param repeat : loop video feed : yes ? no
     */
    void show(ImageList & feed, bool repeat);

    /**
     * @brief This function us used to show the latest recordFeed inside a GUI window
     */
    void showRecordFeed();

    /**
     * @brief This function is used to start recording from the inserted usb camera
     * @details frames will be saved inside container
     * @warning record feed will erased of previous recording
     */
    void startRecording();

    /**
     * @brief This function is used to start recording from the inserted usb camera
     * @details frames will be saved inside container and user can specify if the frames should be shown
     * inside a gui window
     * @warning record feed will erased of previous recording
     */
    void startRecording(bool showRecording);

    /**
     * @brief This function is used to start recording a single frame from the inserted usb camera
     * 
     * @param once : record one frame ? record all frames
     * @param showRecording 
     */
    void startRecording(bool once, bool showRecording);
    
    /**
     * @brief This function is used to disable the recorder which controls the usb camera
     * @param cam : which camera should be disabled
     */
    void stopRecording(cv::VideoCapture & cam);

    /**
     * @brief This function is used to start recording from the inserted usb camera whilist executing a specifed task
     * @details frames will be saved inside container and shown. user can specify wether to execute the task
     * inside a loop or just once
     * @param task : &std::function<void()> , function of what to do
     * @param executeOnce : decision to execute task once or along side the loop
     * @warning record feed will erased of previous recording
     */
    void recordAndExecute(const std::function<void()> & task, bool executeOnce);

    /**
     * @brief This function is used to start recording from the inserted usb camera whilist executing some tasks
     * @details Due to speed limitations, this function will not save it's recordings. 
     * @param apply : task used to change certain attributes about the recorder frame
     * @param startTask : task that runs at the beginning of the function and should be used as an initialization process
     * @param endTask : task that runs at the end of the function and should be used as a clean-up or closing process
     */
    void recordAndApply(const std::function<cv::Mat(RootImage&)> & apply, const std::function<void()> & startTask, const std::function<void()> & endTask);
    
    /**
     * @brief Function used to return the current record feed 
     * 
     * @return RootImageList 
     */
    RootImageList getRecordFeed();

    /**
     * @brief This function is used to change the settings of the Video Controller
     * @param settings
     */
    void changeSettings(settings::WIN::GUI::VIW::data & settings);

    
}; 

}


#endif //VIDEO_VIEWER_HPP
