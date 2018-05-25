/**
 * @file    image.hpp
 *
 * @brief   Image interface
 *
 * @details This file contains a interface which is currently used by the
 * classes RootImage and SampleImage. In the future, we will be switching to
 * another openCV library for the Nvidea Jetson. This library works a tad bit
 * different and does not share same named functions and classes. By
 * implementing this interface in another class you are able to change the Image
 * functionality, without changing the base code.
 *
 * @author  Arsalan Anwari
 *
 * @license See LICENSE
 *
 * @date    2018-05-19
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../external/libraries/open_cv.hpp"
#include "../external/settings.hpp"
#include <iostream>
#include <string>

namespace lucidy
{
/**
 * @brief Image interface
 */
class Image
{
protected:
  cv::Mat image;

  virtual cv::String getPath() = 0;

public:
  /**
   * @brief This function should be used for the intialization process of the
   * image container.
   */
  virtual void init() = 0;

  /**
   * @brief This function should be used to fill the image container with an
   * image specified from a path.
   * 
   * It returns a boolean specifying whether or not the set was successful.
   *
   * @param[in] new_path : const char*
   * @return bool
   */
  virtual bool set(const char *new_path) = 0;

  /**
   * @brief This function should be used as a way to ask the user to input a
   * image path.
   *
   * This image path can then be looked up and the image container can be filled
   * with some image data
   */
  virtual void set() = 0;
  /**
   * @brief This function is used to return the usable data of the image
   *
   * @return cv::Mat
   */
  virtual cv::Mat get() { return image; }

  /**
   * @brief This function can be used to check wether a image matches the
   * required specifications
   *
   * Specifications like size, color, sharpness, etc.
   *
   * @return bool
   */
  virtual bool isValid() { return true; }
};

} // namespace lucidy

#endif // IMAGE_HPP
