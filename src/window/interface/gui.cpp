#include "gui.hpp"

namespace lucidy{

    
    void Gui::init(){
        cv::namedWindow(window_settings.name, window_settings.flag);
        cv::resizeWindow(window_settings.name, window_settings.windowSize.width, window_settings.windowSize.height);
        cv::moveWindow(window_settings.name, window_settings.windowPosition.x, window_settings.windowPosition.y);
    }

    void Gui::open() { 
        cv::setWindowProperty(window_settings.name, cv::WND_PROP_VISIBLE, 4 );
        state = states::open; 
    }
    
    void Gui::close(){
        cv::destroyWindow(window_settings.name);
        state = states::closed;
    }

    void Gui::hide(){
        cv::setWindowProperty(window_settings.name, cv::WND_PROP_VISIBLE, 0 );
        state = states::hidden;
    }
    
    bool Gui::isOpen(){return state == states::open;}
    
    states Gui::getState(){return state;}
    
    settings::WIN::GUI::data & Gui::getSettings(){return window_settings;}




}