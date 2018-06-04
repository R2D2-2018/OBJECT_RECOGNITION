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

#include "image/image.hpp"
#include "interface/gui.hpp"

namespace lucidy {

/**
 * @brief ImageViewer implementation
 *
 * The window manager is made in the global GUI
 * and the settings are changed throughout this class.
 */
class ImageViewer : public Gui {

  public:
    /**
     * @brief Default constructor, does not initialise GUI
     */
    ImageViewer();
    /**
     * @brief This constructor takes window settings as parameter and initilialises a GUI
     *
     * @param settings::WIN::GUI::data : settings&
     */
    ImageViewer(settings::WIN::GUI::data &settings);

    /**
     * @brief This function is used display an image on a display
     *
     * @param Image : image&
     */
    void show(Image &image);

    /**
     * @brief This function is used to change the settings of the ImageViewer
     *
     * The settings can be changed through the global GUI.
     *
     * @param settings : settings::WIN:GUI:data&
     */
    void changeSettings(settings::WIN::GUI::data &settings);
};

} // namespace lucidy

#endif // IMAGE_VIEWER_HPP