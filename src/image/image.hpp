#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../external/libraries/open_cv.hpp"
#include "../external/settings.hpp"

/**
 * @brief   Image wrapper class
 * @file    image.hpp
 */
namespace lucidy
{

class Image
{
  protected:
    cv::Mat image;

  public:
    virtual void init() = 0;
    virtual cv::Mat get() { return image; }

    virtual bool isValid()
    {
        for (const char &c : image.data)
        {
            if (c == '0')
            {
                return false;
            }
        }
        return true;
    }
};

} // namespace lucidy

#endif //IMAGE_HPP
