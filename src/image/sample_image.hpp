#ifndef SAMPLE_IMAGE_HPP
#define SAMPLE_IMAGE_HPP

#include "image.hpp"

/**
 * @brief   Sample image wrapper class
 * @file    sample_image.hpp
 * @author  Dylan Rakiman, Arsalan Anwari
 */
namespace lucidy
{

class SampleImage : public Image
{
private:
  const char *path;
  settings::IMG::data settings;

public:
  SampleImage();
  SampleImage(const char *path, settings::IMG::data &settings);

  void init() override;
  bool isValid() override;
  cv::Mat get() override;

  void set(SampleImage &other);
  void set(const char *new_path);
};

typedef std::vector<SampleImage> SampleImageList;

} // namespace lucidy

#endif //SAMPLE_IMAGE_HPP
