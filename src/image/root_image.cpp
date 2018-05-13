#include "root_image.hpp"

namespace lucidy{
   
    RootImage::RootImage(const char* path, settings::IMG::data & settings):
        path(path),
        settings(settings)
    {}

    void RootImage::init(){
        // initialize with imread and settings params, Remove temporary code below
        for (char & c: image.data){
            c = '1';
        }

    }

    cv::Mat RootImage::get(){
        return image;
    }


}