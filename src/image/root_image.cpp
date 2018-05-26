#include "root_image.hpp"

namespace lucidy{
   
    RootImage::RootImage(){
        settings = settings::IMG::data{cv::IMREAD_GRAYSCALE};
    }

    RootImage::RootImage(const char* path, settings::IMG::data & settings):
        path(path),
        settings(settings)
    {init();}

     void RootImage::init(){
        /// <initialize with imread and settings params, Remove temporary code below
        set(path);
    }


    void RootImage::set(){
        if (image.data){ image = cv::Mat(); }
        cv::String path = requestPath();
        image = cv::imread(path, settings.flag);
        while (!image.data){
            std:: cout << "\r\n \t-FILENAME ERROR: Could not find image: " << path << "\r\n";
            path = requestPath();
            image = cv::imread(path, settings.flag);
        }
    }

    bool RootImage::set(const char * newPath){
        if (image.data){ image = cv::Mat(); }
        image = cv::imread(newPath, settings.flag);
        if (!image.data){ std:: cout << "\r\n \t-FILENAME ERROR: Could not find image: " << path << "\r\n"; return false; }
        return true;
    }

    void RootImage::set(cv::Mat & newImage){
        if (image.data){ image = cv::Mat(); }
        image = newImage;
    }

    cv::Mat RootImage::get(){
        return image;
    }

    cv::String RootImage::requestPath(){
        std::string path;
        std::cout << "\r\nPlease insert path of RootImage: ";
        std::cin >> path;
        std:: cout << "\r\n \t-You inserted: " << path;
        return cv::String(path);
    }


}