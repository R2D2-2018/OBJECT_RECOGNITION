/**
 * @brief Image interface 
 * @details This file contains a interface which is currently used by the classes RootImage and SampleImage.
 * In the future, we will be switching to another openCV library for the Nvidea Jetson.
 * This library works a tad different and does not share same named functions and classes.
 * By implementing this interface in another class you are able to change the Image functionality, without changing the base code. 
 * @file image.hpp
 * @author Arsalan Anwari
 * @date 2018-05-15
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../external/libraries/open_cv.hpp"
#include "../external/settings.hpp"

namespace lucidy
{
/**
 * @brief Image interface
 */
class Image
{
  protected:
    cv::Mat image;

  public:
    /**
     * @brief This function should be used for the intialization process of the image container. 
     */
    virtual void init() = 0;

    /**
     * @brief This function is used to return the usable data of the image 
     * @return cv::Mat 
     */
    virtual cv::Mat get() { return image; }

    /**
     * @brief This function can be used to check wether a image matches the required specifications
     * @details Specifications like size, color, sharpness, etc. By default it check if the image contains any unspecified values
     * @return true : image is valid 
     * @return false : image is invalid 
     */
    virtual bool isValid()
    {
        for (const char &c : image.data)
        {
            if (c == ' ')
            {
                return false;
            }
        }
        return true;
    }
};

} // namespace lucidy

#endif //IMAGE_HPP
