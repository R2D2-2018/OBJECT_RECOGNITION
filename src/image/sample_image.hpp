/**
 * @file sample_image.hpp
 *
 * @brief Sample image wrapper file
 *
 * @details This file contains a class which is used to load in a sample image. A sample image can be defined
 * as the image used for comparing a shape ON A ROOT IMAGE.

 * @author Arsalan Anwari
 *
 * @license See LICENSE
 *
 * @date 2018-05-15
 */

#ifndef SAMPLE_IMAGE_HPP
#define SAMPLE_IMAGE_HPP

#include "image.hpp"

namespace lucidy {
/**
 * @brief Sample image wrapper class
 *
 * Implements Image interface
 */
class SampleImage : public Image {
  private:
    const char *path;
    settings::IMG::data settings;

  public:
    SampleImage();
    SampleImage(const char *path, settings::IMG::data &settings);

    /**
     * @brief Function used to initialise wrapper class without specifying path or settings.
     */
    void init() override;

    /**
     * @brief Function used to check wether a loaded image is a valid sample image
     *
     * @return bool
     */
    bool isValid() override;

    /**
     * @brief Function used to retrieve usable data from image container
     *
     * @return cv::Mat
     */
    cv::Mat get() override;

    /**
     * @brief Function for asking the user to input an image path through std::cin.
     *
     * This function asks the user for an image path through std::cin.
     * The image path can then be looked up and the image container can be filled with said image data.
     * The user will get continously prompted to insert an image path until the image path is valid.
     *
     * @warning The image container will be cleared on this function call.
     */
    void set() override;

    /**
     * @brief This function is used to to fill the image container with an image specified from a path as parameter.
     *
     * It returns a boolean specifying whether or not the set was successful.
     *
     * @param new_path : const char*
     * @return bool
     *
     * @warning The image container will be cleared on this function call
     */

    bool set(const char *new_path) override;

    /**
     * @brief Function used to copy the content of another sample image into the current one
     *
     * @param other : sampleImage&
     */
    void set(SampleImage &other);

    /**
     * @brief This function is used as CLI interface that prompts the user to input an image path.
     *
     * The user input is printed back and converted to a cv::String.
     *
     * @return cv::String
     */
    cv::String getPath() override;
};

/// This is a custom made type that holds a list of SampleImage's.
typedef std::vector<SampleImage> SampleImageList;

} // namespace lucidy

#endif /// SAMPLE_IMAGE_HPP
