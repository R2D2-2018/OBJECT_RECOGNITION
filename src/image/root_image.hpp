/**
 * @brief Root Image wrapper file
 * @details This file contains a class which is used to load in a root image. A root image can be defined
 * as the image used to compare a shape ON
 * @file root_image.hpp
 * @author Arsalan Anwari
 * @date 2018-05-15
 */
#ifndef ROOT_IMAGE_HPP
#define ROOT_IMAGE_HPP

#include "image.hpp"


namespace lucidy
{
/**
 * @brief Root image wrapper class
 * @details implements interface Image
 */
class RootImage : public Image
{
private:
  const char *path;
  settings::IMG::data settings;

public:

  RootImage();
  RootImage(const char *path, settings::IMG::data &settings);

  /**
   * @brief Function used to load in image from image path and settings.
   */
  void init() override;

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
  void set(const char * new_path) override;
  
  /**
   * @brief Function used to retrieve usable data from image container
   * @return cv::Mat 
   */
  cv::Mat get() override;

  /**
   * @brief This function is used as CLI interface that prompts the user to input a image path 
   * @details Feed back is givin on the currently inputed value. This value will be converted to a cv::String
   * @return cv::String 
   */
  cv::String getPath() override;
};

} // namespace lucidy

#endif //ROOT_IMAGE_HPP