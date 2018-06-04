#include "image_viewer.hpp"

namespace lucidy{

    ImageViewer::ImageViewer(){}

    ImageViewer::ImageViewer(settings::WIN::GUI::data & settings)
    {
        window_settings = settings;
        init();
    }

    void ImageViewer::show(Image & image){
        cv::imshow(window_settings.name, image.get() );
    }

    void ImageViewer::show(Image & image, bool loop){
        if (loop){
            for (;;){
                cv::imshow(window_settings.name, image.get() );
                char key = cv::waitKey(window_settings.refreshRate);
                if (key == window_settings.exitKey){  return;} 
            }
        }else{ show(image); }
    }
    
    void ImageViewer::showAndExecute(Image & image, std::function<void()> & task, bool executeOnce){
        if (executeOnce){ task(); }
        for (;;){
            cv::imshow(window_settings.name, image.get() );
            char key = cv::waitKey(window_settings.refreshRate);
            if (key == window_settings.exitKey){ return;} 
            if (!executeOnce){task();}
        }

    }

    void ImageViewer::changeSettings(settings::WIN::GUI::data & settings){
        window_settings = settings;
    }


}