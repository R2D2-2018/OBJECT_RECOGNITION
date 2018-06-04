#include "sample_image.hpp"

namespace lucidy{

    SampleImage::SampleImage(){}

    SampleImage::SampleImage(const char* path, settings::IMG::data & settings):
        path(path),
        settings(settings)
    {init();}

    void SampleImage::init(){
        /// initialize with imread and settings params, check if image specifications are valid
        /// if not change image OR give error message. 
         if (!isValid()){ return; }
         if ( set(path) ){ preProcess(); }  
    }

    void SampleImage::preProcess(){
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

    const cv::Mat SampleImage::get(){
        return image;
    }
    
    bool SampleImage::isValid(){
        /// test out some conditions like size, color, etc
        return true;

    }
    
    void SampleImage::set(SampleImage & other){
        /// copy funtion: clear img.data, setup again with new settings
        
        if (image.data){ image = cv::Mat(); }
        image = other.get();
    }

    void SampleImage::set(){
        if (image.data){ image = cv::Mat(); }
        cv::String path = requestPath();
        image = cv::imread(path, settings.flag);
        while (!image.data){
            std:: cout << "\r\n \t-FILENAME ERROR: Could not find image: " << path << "\r\n";
            path = requestPath();
            image = cv::imread(path, settings.flag);
        }
    }

    bool SampleImage::set(const char * newPath){
        if (image.data){ image = cv::Mat(); }
        image = cv::imread(newPath, settings.flag);
        if (!image.data){ std:: cout << "\r\n \t-FILENAME ERROR: Could not find image: " << path << "\r\n"; return false; }
        return true;
    }

    void SampleImage::set(cv::Mat & newImage){
        if (image.data){ image = cv::Mat(); }
        image = newImage;
    }

    cv::String SampleImage::requestPath(){
        std::string path;
        std::cout << "\r\nPlease insert path of SampleImage: ";
        std::cin >> path;
        std:: cout << "\r\n \t-You inserted: " << path;
        return cv::String(path);
    }

}

