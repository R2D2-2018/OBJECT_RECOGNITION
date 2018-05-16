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
        
        /// Remove temporary code below
        for (char & c: image.data){
            c = '1';
        }
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
        
        /// if len(image) > 0: image.release();
        image = other.image;
    }

    void SampleImage::set(const char* new_path){
        /// copy funtion: clear img.data, imread again with new image
        
        /// if len(image) > 0: image.release();
        /// image = cv::imread(new_path);
    }

}

