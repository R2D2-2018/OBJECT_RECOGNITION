/**
 * @brief This file contains an implementation of the global Gui interface
 * @details The class made can be used to display an image on the display
 * @file image_viewer.hpp
 * @author Arsalan Anwari
 * @date 2018-05-19
 */

#ifndef IMAGE_VIEWER_HPP
#define IMAGE_VIEWER_HPP

#include "interface/gui.hpp"
#include "../image/image.hpp"
#include <functional>
#include <iostream>

namespace lucidy{

/**
 * @brief ImageViewer implementation
 * @details The window manager is made in the global Gui interface and the settings are changed throughout this class
 */
class ImageViewer: public Gui{

public:
    ImageViewer();
    ImageViewer(settings::WIN::GUI::data & settings);

    /**
     * @brief This function is used to dislay a image in a window once without delay
     * @warning Not using a delay when running this function might cause the image to not appear on the window. 
     * @param image : &Image
     */
    void show(Image & image);

    /**
     * @brief This function is used to display a image in a window constently in a loop
     * @param image 
     */
    void show(Image & image, bool loop);

    /**
     * @brief This function is used to display a a image in window constently whilist executing a task sequantual
     * 
     * @param image : &Image
     * @param task : &std::function<void()>
     * @param executeOnce : bool, decides wether task should execute alongside the loop or just once at the start
     */
    void showAndExecute(Image & image, std::function<void()> & task, bool executeOnce = false);
    
    /**
     * @brief This function is used to change the settings of the ImageViewer
     * @details in reality the settings are being passed trough and changed in the global gui interface
     * @param settings : settings::WIN:GUI:data&
     */
    void changeSettings(settings::WIN::GUI::data & settings);

};

}

#endif //IMAGE_VIEWER_HPP