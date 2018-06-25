/**
 * @file	  main.cpp
 * @brief     The main function. Currently holds demo code to display an image in a window.
 * @author    Roxanne van der Pol
 * @license   MIT
 */

#include "sample_image.hpp"
#include <iostream>

int main() {
    char path[150];
    char answer = 'n';

    std::cout << "Want to specify a custom path? (y/n)\n";
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << "Please specify a path: ";
        std::cin >> path;
    } else {
        char path_[19] = "src/img/sample.jpg";
        for (int i = 0; i < 19; ++i) {
            path[i] = path_[i];
        }
    }

    ///< Create SampleImage object and place path inside of it
    SampleImage sampleImage(path);

    ///< Check if image could be loaded
    if (!sampleImage.getIsValid()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    ///< Create window
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    while (true) {
        ///< Display image
        cv::imshow("Display window", sampleImage.getImage());
        ///< Wait for keyboard interrupt
        if (cv::waitKey(30) >= 0) {
            break;
        }
    }

    return 0;
}