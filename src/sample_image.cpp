#include "sample_image.hpp"

///< Constructors
SampleImage::SampleImage() : isValid(false) {
}

SampleImage::SampleImage(const char *path) : path(path) {
    if (*path <= '9' && *path >= '0') {
        std::cout << "Selected camera at address " << path << std::endl;
        stream = *path - '0';
        stream.read(image);
    } else {
        std::cout << "Selected image at " << path << std::endl;
        image = cv::imread(path, -1);
    }
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
    if (*path <= '9' && *path >= '0') {
        std::cout << "Selected camera at address " << path << std::endl;
        stream = *path - '0';
        stream.read(image);
    } else {
        std::cout << "Selected image at " << path << std::endl;
        image = cv::imread(path, -1);
    }
    if (!image.data) {
        std::cout << "Invalid image path!\n";
        isValid = false;
    } else {
        isValid = true;
    }
}
void SampleImage::setPath(SampleImage &other) {
    if (other.getIsValid()) {
        path = other.getPath();
    } else {
        std::cout << "Other SampleImage image path was invalid!\n";
    }
}

///< Getters
const char *SampleImage::getPath() {
    return path;
}

cv::Mat SampleImage::getImage() {
    if (*path <= '9' && *path >= '0') {
        stream.read(image);
    }
    return image;
}
bool SampleImage::getIsValid() {
    return isValid;
}