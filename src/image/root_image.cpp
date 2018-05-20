#include "root_image.hpp"

namespace lucidy{
   
    RootImage::RootImage(){
        settings = settings::IMG::data{1};
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
        cv::String path = getPath();
        image = cv::imread(path, settings.flag);
        while (!image.data){
            std:: cout << "\r\n \t-FILENAME ERROR: Could not find image: " << path << "\r\n";
            path = getPath();
            image = cv::imread(path, settings.flag);
        }
    }

    void RootImage::set(const char * new_path){
        if (image.data){ image = cv::Mat(); }
        image = cv::imread(new_path, 1);
    }

    cv::Mat RootImage::get(){
        return image;
    }

    cv::String RootImage::getPath(){
        std::string path;
        std::cout << "\r\nPlease insert path of RootImage: ";
        std::cin >> path;
        std:: cout << "\r\n \t-You inserted: " << path;
        return cv::String(path);
    }


}