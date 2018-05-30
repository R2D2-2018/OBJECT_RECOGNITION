/**
 * @file root_image.hpp
 *
 * @brief Root Image wrapper file
 *
 * @details This file contains a class which is used to load in a root image. A root image can be defined
 * as the image used to compare a shape ON

 * @author Arsalan Anwari
 *
 * @license See LICENSE
 *
 * @date 2018-05-15
 */
#ifndef ROOT_IMAGE_HPP
#define ROOT_IMAGE_HPP

#include "image.hpp"

namespace lucidy {
/**
 * @brief Root image wrapper class
 *
 * Implements Image interface
 */
class RootImage : public Image {
  private:
    const char *path;
    settings::IMG::data settings;

  public:
    RootImage();
    RootImage(const char *path, settings::IMG::data &settings);

    /**
     * @brief Function used to initialise class without entering path or settings.
     */
    void init() override;

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
     * The function returns a boolean specifying whether or not the set was successful.
     *
     * @param new_path : const char*
     * @return bool
     *
     * @warning The image container will be cleared on this function call
     */
    bool set(const char *new_path) override;

    /**
     * @brief Function used to retrieve image data from image container
     *
     * @return cv::Mat
     */
    cv::Mat get() override;

    /**
     * @brief This function is used as CLI interface that prompts the user to input an image path.
     *
     * The user input is printed back and converted to a cv::String.
     *
     * @return cv::String
     */
    cv::String getPath() override;
};

} // namespace lucidy

#endif // ROOT_IMAGE_HPP