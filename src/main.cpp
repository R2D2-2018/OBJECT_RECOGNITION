/**
 * @file	  main.cpp
 * @brief     The main function. Currently holds demo code to display an image in a window.
 * @author    Roxanne van der Pol
 * @license   See LICENSE
 */

#include "open_cv.hpp"
#include <iostream>

int main() {
    cv::Mat image;

    ///< Specify path of image to be loaded
    char imageName[] = "default.jpg";
    std::cout << "Specify image path: " << std::endl;
    std::cin >> imageName;

    ///< Read image from file
    image = cv::imread(imageName, -1);

    ///< Check if image could be loaded
    if (!image.data) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    ///< Create window and display image
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);

    ///< Wait for key stroke
    cv::waitKey(0);
    return 0;
}