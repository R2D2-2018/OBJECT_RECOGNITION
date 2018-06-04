#include "root_image.hpp"

namespace lucidy{
   
    RootImage::RootImage(){
        settings = settings::IMG::data{
            lucidy::Coordinate{7,7},
            0,0, false,
            cv::IMREAD_COLOR
        };
    }

    RootImage::RootImage(const char* path, settings::IMG::data & settings):
        path(path),
        settings(settings)
    {init();}

     void RootImage::init(){
        /// <initialize with imread and settings params, Remove temporary code below
        if ( set(path) ){ preProcess(); }  
    }

    void RootImage::preProcess(){
        cv::GaussianBlur( image, image, cv::Size(settings.smoothMask.x, settings.smoothMask.y), 2, 2 );
        cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
        
        if (settings.applyThreshold){
            std::vector<cv::Mat> channels;
            cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
            cv::split(image, channels);

            cv::threshold(channels[0], channels[0], settings.maxHue, 0, cv::THRESH_TOZERO_INV );
            cv::threshold(channels[1], channels[1], settings.maxSaturation, 0, cv::THRESH_TOZERO );
            
            cv::merge(channels, image);
            cv::cvtColor(image, image, cv::COLOR_HSV2RGB);
        }
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

    const cv::Mat RootImage::get(){
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