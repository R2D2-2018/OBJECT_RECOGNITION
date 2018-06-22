/**
 * @file	  sample_image.cpp
 * @brief     SampleImage class that contains the sample library to extract features from.
 * @author    Roxanne van der Pol
 * @license   MIT
 */

#include "sample_image.hpp"

///< Constructors
SampleImage::SampleImage() : isValid(false) {
}
SampleImage::SampleImage(const char *path) : path(path) {
    image = cv::imread(path, -1);
    if (!image.data) {
        std::cout << "Invalid image path!\n";
        isValid = false;
    } else {
        isValid = true;
    }
}

///< Setters
void SampleImage::setPath(const char *newPath) {
    path = newPath;
    image = cv::imread(path, -1);
    if (!image.data) {
        std::cout << "Invalid image path!\n";
        isValid = false;
    }
}
void SampleImage::setPath(SampleImage &other) {
    if (other.getIsValid()) {
        path = other.getPath();
        image = cv::imread(path, -1);
    } else {
        std::cout << "Other SampleImage image path was invalid!\n";
    }
}

///< Getters
const char *SampleImage::getPath() {
    return path;
}
cv::Mat SampleImage::getImage() {
    return image;
}
bool SampleImage::getIsValid() {
    return isValid;
}