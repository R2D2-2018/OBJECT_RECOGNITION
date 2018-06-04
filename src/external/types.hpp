/**
 * @brief custom lucidy types file 
 * @details This file contains a some custom types that are used through out the module
 * @file image.hpp
 * @author Arsalan Anwari
 * @date 2018-05-19
 */

#ifndef TYPES_HPP
#define TYPES_HPP

namespace lucidy{

    /**
     * @brief Used to specify the window size
     */
    struct WindowSize{int width=0; int height=0;};
    
    /**
     * @brief Used to either specify a window position or to be used as a normale xy coordinate
     */
    struct Coordinate{int x=0; int y=0;};

    /**
     * @brief Enum list of cameras that can be used by the video controller
     */
    enum Cameras{MAIN_CAMERA, USB_CAMERA_1, USB_CAMERA_2, USB_CAMERA_3, USB_CAMERA_4};
}

#endif //TYPES_HPP

