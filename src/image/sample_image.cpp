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
         set(path); 
        
        
    }

    cv::Mat SampleImage::get(){
        return image;
    }
    
    bool SampleImage::isValid(){
        /// test out some conditions like size, color, etc
        return true;

    }
    
    void SampleImage::set(SampleImage & other){
        /// copy funtion: clear img.data, setup again with new settings
        
        if (image.data){ image = cv::Mat(); }
        image = other.image;
    }

    void SampleImage::set(){
        if (image.data){ image = cv::Mat(); }
        cv::String path = getPath();
        image = cv::imread(path, settings.flag);
        while (!image.data){
            std:: cout << "\r\n \t-FILENAME ERROR: Could not find image: " << path << "\r\n";
            path = getPath();
            image = cv::imread(path, settings.flag);
        }
    }

    bool SampleImage::set(const char * new_path){
        image = cv::imread(new_path, settings.flag);
        if(! image.data )   /// Check for invalid input
        {
            std::cerr << "Could not open or find the image." << std::endl;
            return 0;
        }
        return 1;
    }

    cv::String SampleImage::getPath(){
        std::string path;
        std::cout << "\r\nPlease insert path of SampleImage: ";
        std::cin >> path;
        std:: cout << "\r\n \t-You inserted: " << path;
        return cv::String(path);
    }

}

