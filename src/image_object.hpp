/**
 * @file	  image_object.hpp
 * @brief     Contains the ImageObject class
 * @author    Roxanne van der Pol
 * @license   MIT
 */

#ifndef IMAGE_OBJECT_HPP
#define IMAGE_OBJECT_HPP

#include <iostream>
#include <vector>

#include "open_cv.hpp"
#include "sample_image.hpp"

class ImageObject {
  private:
    std::vector<SampleImage> sampleImages; ///< A container for SampleImages
    SampleImage image;                     ///< Image to be detected
  public:
    /**
     * @brief ImageObject empty constructor
     *
     * Default empty constructor of ImageObject class. Must use setters to initialise image and provide (at least) 1 SampleImage
     */
    ImageObject();
    /**
     * @brief ImageObject overloaded constructor
     *
     * Constructor of ImageObject class which initialises image and adds a SampleImage to the SampleImage container sampleImages.
     *
     * @param[in]     SampleImage image    The ImageObject image.
     * @param[in]     SampleImage sampleImage    A SampleImage
     */
    ImageObject(SampleImage image, SampleImage sampleImage);

    /**
     * @brief Add a SampleImage
     *
     * Add a SampleImage object to the SampleImages container sampleImages.
     *
     * @param[in]     SampleImage sampleImage    A SampleImage to be appended to sampleImages
     */
    void addSample(SampleImage sampleImage);
    /**
     * @brief Add SampleImages
     *
     * Add one or more SampleImage object to the SampleImages container sampleImages.
     *
     * @param[in]     std::vector<SampleImage> sampleImages    SampleImages to be appended to sampleImages
     */
    void addSamples(std::vector<SampleImage> sampleImages);
    /**
     * @brief Delete a SampleImage
     *
     * Delete a SampleImage from the SampleImage container sampleImages.
     *
     */
    void deleteSample();
    /**
     * @brief Delete SampleImages
     *
     * Delete one or more SampleImages from the SampleImage container sampleImages.
     *
     */
    void deleteSamples();
    /**
     * @brief Set the ImageObject image
     *
     * Sets the ImageObject SampleImage image.
     *
     * @param[in]     SampleImage & image    (New) image.
     */
    void setImage(SampleImage &image);
    /**
     * @brief Compare image with sampleImages
     *
     * Compare the ImageObject image with the SampleImages in sampleImages to see whether the objects in sampleImages can be
     * detected in image. Image can be a picture or a video feed.
     */
    void compare();
};

#endif // IMAGE_OBJECT_HPP