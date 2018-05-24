#include "feature_detector.hpp"

namespace lucidy{

    FeatureDetector::FeatureDetector(settings::FDT::data & settings):
        settings(settings)
    {initDetector();}

    void FeatureDetector::initDetector(){
        /// initialize detector with settings param
        /// detector = cv::xfeatures2d::SURF::create(); --> cannot me mimiced with typedef, but works in open_cv
        detector = cv::xfeatures2d::SURF::create();
        detector->setHessianThreshold(settings.hessianThreshold);
        detector->setNOctaves(settings.octavesNr);
        detector->setNOctaveLayers(settings.octaveLayers);
    }

    FeatureList& FeatureDetector::getFeatureList(Image & sourceImage){
        /// detect features in image and put them in featureList
        /// if featureList has already been used a.k.a. is full remove all the content 

        /// if len (featureList) > 0: featureList.release();  
        detector->detect(sourceImage.get(), featureList, cv::Mat() );
        return featureList;

    }

    SurfDetector& FeatureDetector::getDetector(){
        /// return feature detector so memberfunctions can be called in another class
        return detector;
    }

    void FeatureDetector::changeSettings(const settings::FDT::data & new_data ){
        /// change settings of detector, either one by one or complete copy
        
        /// settings.hessianThreshold = new_data.data.hessianThreshold;
        /// settings.octavesNr = new_data.data.octavesNr;
        /// settings.octaveLayers = new_data.data.octaveLayers;
        settings = new_data;
    }
    
    settings::FDT::data& FeatureDetector::getSettings(){
        /// return settings so an user can see what the current settings of the surf detector are
        return settings;
    }

}