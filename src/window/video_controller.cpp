#include "video_controller.hpp"

namespace lucidy{

    VideoController::VideoController(){}

    VideoController::VideoController(settings::WIN::GUI::VIW::data & settings){
        window_settings = settings.guiSet;
        cameraNr = settings.camNr;
        init();
    }

    cv::String VideoController::requestPath(){
        std::string path;
        std::cout << "\r\nPlease insert path of VideoFeed: ";
        std::cin >> path;
        std:: cout << "\r\n \t-You inserted: " << path;
        return cv::String(path);
    }

    bool VideoController::displayFrame(cv::VideoCapture & cam, cv::Mat & frame){
        frame = cv::Mat();
        cam >> frame;
        cv::imshow(window_settings.name, frame );
        char key = cv::waitKey(window_settings.refreshRate);
        if (key == window_settings.exitKey){return true;}
        return false;
    }

    bool VideoController::saveFrame(cv::VideoCapture & cam, cv::Mat & frame){
        RootImage image;
        frame = cv::Mat();
        cam >> frame;
        image.set(frame);
        recordFeed.push_back(image);
        char key = cv::waitKey(window_settings.refreshRate);
        if (key == window_settings.exitKey){return true;}
        return false;
    }

    bool VideoController::displayAndSaveFrame(cv::VideoCapture & cam, cv::Mat & frame){
        RootImage image;
        frame = cv::Mat();
        cam >> frame;
        image.set(frame);
        recordFeed.push_back(image);
        cv::imshow(window_settings.name, frame );
        char key = cv::waitKey(window_settings.refreshRate);
        if (key == window_settings.exitKey){return true;}
        return false;
    }

    void VideoController::show(){
        cv::String path = requestPath();
        cv::VideoCapture cam( path );
        cv::Mat frame;
        while( !cam.isOpened() ){
            std:: cout << "\r\n \t-FILENAME ERROR: Could not find videofeed: " << path << "\r\n";
            path = requestPath();
            cam.open(path);
        }
        for(;;){ if( displayFrame(cam, frame) ){ stopRecording(cam); return;} }
    }

    void VideoController::show(const char* path){
        cv::VideoCapture cam( path );
        if( !cam.isOpened() ){std:: cout << "\r\n \t-FILENAME ERROR: Could not find videofeed: " << path << "\r\n"; stopRecording(cam); return; }
        cv::Mat frame;
        for(;;){ if( displayFrame(cam, frame) ){ stopRecording(cam); return;} }
    }

    void VideoController::show(ImageList & feed){
        for( auto & frame : feed){
            cv::imshow(window_settings.name, frame->get() );
            char key = cv::waitKey(window_settings.refreshRate);
            if (key == window_settings.exitKey){return;} 
        }
    }

    void VideoController::show(ImageList & feed, bool repeat){
        if (repeat){
            for(;;){ show(feed); }
        }else{
            show(feed);
        }

    }

    void VideoController::showRecordFeed(){
        for( auto & frame : recordFeed){
            cv::imshow(window_settings.name, frame.get() );
            char key = cv::waitKey(window_settings.refreshRate);
            if (key == window_settings.exitKey){return;} 
        }
    }

    void VideoController::startRecording(){
        recorder.open(cameraNr);
        if(!recorder.isOpened()){ std:: cout << "\r\n \t-CAMERA ERROR: Could not find camera: " << cameraNr << "\r\n"; stopRecording(recorder); return; }
        recordFeed.clear();
        cv::Mat frame;
        for(;;){ if( saveFrame(recorder, frame) ){ stopRecording(recorder); return;} }
    }

    void VideoController::startRecording(bool showRecording){
        if (showRecording){
            recorder.open(cameraNr);
            if(!recorder.isOpened()){ std:: cout << "\r\n \t-CAMERA ERROR: Could not find camera: " << cameraNr << "\r\n"; stopRecording(recorder); return; }
            cv::Mat frame;
            recordFeed.clear();
            for(;;){ if( displayAndSaveFrame(recorder, frame) ){ stopRecording(recorder); return;} }
        }else{ startRecording(); }

    }

    void VideoController::startRecording(bool once, bool showRecording){
        if (once){
            recorder.open(cameraNr);
            if(!recorder.isOpened()){ std:: cout << "\r\n \t-CAMERA ERROR: Could not find camera: " << cameraNr << "\r\n"; stopRecording(recorder); return; }
            cv::Mat frame;
            recordFeed.clear();
            if (showRecording){ 
               if( displayAndSaveFrame(recorder, frame) ){ stopRecording(recorder); return;}
            }else{
                if( saveFrame(recorder, frame) ){ stopRecording(recorder); return;}
            }
        }else{ 
            startRecording(showRecording);
         }

    }

    void VideoController::stopRecording(cv::VideoCapture & cam){
        cam.release();
    }

    void VideoController::recordAndExecute(const std::function<void()> & task, bool executeOnce){
        recorder.open(cameraNr);
        if(!recorder.isOpened()){ std:: cout << "\r\n \t-CAMERA ERROR: Could not find camera: " << cameraNr << "\r\n"; stopRecording(recorder); return; }
        if (executeOnce){ task(); }
        cv::Mat frame;
        recordFeed.clear();
        for(;;){
            if(!executeOnce){ task(); }
            if( displayAndSaveFrame(recorder, frame) ){ stopRecording(recorder); return;}
        }
    }

    void VideoController::recordAndApply(const std::function<cv::Mat(RootImage&)> & apply, const std::function<void()> & startTask, const std::function<void()> & endTask){
        recorder.open(cameraNr);
        if(!recorder.isOpened()){ std:: cout << "\r\n \t-CAMERA ERROR: Could not find camera: " << cameraNr << "\r\n"; stopRecording(recorder); return; }
        startTask();
        cv::Mat frame;
        cv::Mat result;
        RootImage frameImage;
        recordFeed.clear();
        for(;;){
            recorder >> frame;
            frameImage.set(frame);

            result = apply(frameImage);
            try{ cv::imshow(window_settings.name, result ); }catch(cv::Exception &err){err.what();}
            char key = cv::waitKey(window_settings.refreshRate);
            if (key == window_settings.exitKey){ endTask(); stopRecording(recorder); return;}

        }
    }

    RootImageList VideoController::getRecordFeed(){ return recordFeed; }

    void VideoController::changeSettings(settings::WIN::GUI::VIW::data & settings){
        window_settings = settings.guiSet;
        cameraNr = settings.camNr;
    }


}