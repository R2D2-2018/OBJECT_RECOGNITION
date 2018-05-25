/**
 * @file image_viewer.hpp
 * 
 * @brief This file contains an implementation of the global Gui interface
 * 
 * @details The class made can be used to display an image on the display
 * 
 * @author Arsalan Anwari
 * 
 * @license See LICENSE
 * 
 * @date 2018-05-19
 */

#ifndef IMAGE_VIEWER_HPP
#define IMAGE_VIEWER_HPP

#include "interface/gui.hpp"
#include "../image/image.hpp"

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
     * @brief This function is used display a image on a display
     * @param image 
     */
    void show(Image & image);

    /**
     * @brief This function is used to change the settings of the ImageViewer
     * @details in reality the settings are being passed trough and changed in the global gui interface
     * @param settings : settings::WIN:GUI:data&
     */
    void changeSettings(settings::WIN::GUI::data & settings);

};

}

#endif //IMAGE_VIEWER_HPP