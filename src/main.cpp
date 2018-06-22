/**
 * @file	  main.cpp
 * @brief     The main function. Currently holds demo code to display an image in a window.
 * @author    Roxanne van der Pol
 * @license   MIT
 */

#include "sample_image.hpp"
#include <iostream>

int main() {
    ///< Specify path of image to be loaded
    char path[] = "default.jpg";
    std::cout << "Specify image path: \n";
    std::cin >> path;

    ///< Create SampleImage object and place path inside of it
    SampleImage sampleImage(path);

    ///< Check if image could be loaded
    if (!sampleImage.getIsValid()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    ///< Create window and display image
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", sampleImage.getImage());

    ///< Wait for key stroke
    cv::waitKey(0);
    return 0;
}