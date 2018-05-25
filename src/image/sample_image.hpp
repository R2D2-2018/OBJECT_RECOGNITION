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

  /**
   * @brief This function is used as CLI interface that prompts the user to input a image path 
   * @details Feed back is givin on the currently inputed value. This value will be converted to a cv::String
   * @return cv::String 
   */
  cv::String requestPath();

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
     * @brief This function is used as a way to ask the user to input a image path. 
     * @details This image path can then be looked up and the image container can be filled with some image data.
     * The user will get continously prompted to insert an image path untill the image path is correct.
     * @warning The image container will be cleared on this function call
  */
  void set() override;
 
  /**
   * @brief This function is used to to fill the image container with an image specified from a path.
   * @param new_path : char* const
   * @warning The image container will be cleared on this function call
   */
  
  bool set(const char *newPath) override;

  /**
   * @brief This function is used to fill the image container with the parameter cotainer 
   * 
   * @param newImage: new image conainter 
   */
  void set(cv::Mat & newImage) override;

   /**
   * @brief Function used to copy the content of another sample image into the current one
   * 
   * @param other 
   */
  void set(SampleImage &other);

  
};

/// This is a custom made type that holds a list of SampleImage's. 
typedef std::vector<SampleImage> SampleImageList;

} /// namespace lucidy

#endif /// SAMPLE_IMAGE_HPP
