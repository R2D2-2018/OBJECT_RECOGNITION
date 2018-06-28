/**
 * @file	  image_object.cpp
 * @brief     Contains the ImageObject class
 * @author    Roxanne van der Pol
 * @license   MIT
 */

#include "image_object.hpp"

ImageObject::ImageObject() {
}
ImageObject::ImageObject(SampleImage image, SampleImage sampleImage) : image(image) {
    sampleImages.emplace_back(sampleImage);
}

void ImageObject::addSample(SampleImage sampleImage) {
}
void ImageObject::addSamples(std::vector<SampleImage> sampleImages) {
}
void ImageObject::deleteSample() {
}
void ImageObject::deleteSamples() {
}

void ImageObject::setImage(SampleImage &image) {
}

void ImageObject::compare() {
}
