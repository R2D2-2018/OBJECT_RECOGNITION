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
  settings::IMG::data &settings;

public:
  RootImage(const char *path, settings::IMG::data &settings);

  /**
   * @brief Function used to load in image from image path and settings.
   */
  void init() override;

  /**
   * @brief Function used to retrieve usable data from image container
   * @return cv::Mat 
   */
  cv::Mat get() override;
};

} // namespace lucidy

#endif //ROOT_IMAGE_HPP