/**
 * @brief Sample image wrapper file
 * @details This file contains a class which is used to load in a sample image. A sample image can be defined
 * as the image used for comparing a shape ON A ROOT IMAGE.
 * @file sample_image.hpp
 * @author Arsalan Anwari
 * @date 2018-05-15
 */

#ifndef SAMPLE_IMAGE_HPP
#define SAMPLE_IMAGE_HPP

#include "image.hpp"

namespace lucidy
{
/**
 * @brief Sample image wrapper class
 * @details Implements Image interface
 */
class SampleImage : public Image
{
private:
  const char *path;
  settings::IMG::data settings;

public:
  SampleImage();
  SampleImage(const char *path, settings::IMG::data &settings);

   /**
   * @brief Function used to load in image from image path and settings.
   */
  void init() override;

  /**
   * @brief Function used to check wether an loaded image is a valid sample image 
   * 
   * @return true : sample image is calid
   * @return false : sample image needs to be changed
   */
  bool isValid() override;

  /**
   * @brief Function used to retrieve usable data from image container
   * 
   * @return cv::Mat 
   */
  cv::Mat get() override;

  /**
   * @brief Function used to copy the content of another sample image into the current one
   * 
   * @param other 
   */
  void set(SampleImage &other);

  /**
   * @brief Function used to change the content of the image container by loading another image with a file path
   * 
   * @param new_path 
   */
  void set(const char *new_path);
};

/// This is a custom made type that holds a list of SampleImage's. 
typedef std::vector<SampleImage> SampleImageList;

} /// namespace lucidy

#endif /// SAMPLE_IMAGE_HPP
