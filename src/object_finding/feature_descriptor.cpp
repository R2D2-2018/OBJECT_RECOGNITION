#include "feature_descriptor.hpp"

namespace lucidy{

    FeatureDescriptor::FeatureDescriptor(FeatureDetector & detector, settings::FDC::data & settings):
        detector(detector),
        settings(settings),
        descriptor( detector.getDetector() )
    {initDescriptor();}

    void FeatureDescriptor::initDescriptor(){
        /// initialize detector settings which in reality is just a surf dector.
        descriptor->setExtended( settings.extendDescriptor );
        descriptor->setUpright( settings.calcUpright );
    }

    bool FeatureDescriptor::computeDescriptors(Image & sourceImage){
        /// compute descriptors by using image featureList that has been precalculated by detector
        /// descriptor output will be placed in image descriptorList
        /// if descriptorList has already been used a.k.a. is full remove all the content 
        /// check if image has a featurelist first
        if ( sourceImage.features.size() <= 0 ){
            std::cout << "IMAGE FEATURE ERROR: No featurelist found to compute descriptors. descriptors not added\r\n";
            return false;
        }

        if (sourceImage.descriptors.data){ sourceImage.descriptors = cv::Mat(); }
        descriptor->compute(sourceImage.get(), sourceImage.features, sourceImage.descriptors );
        return true;
    }

}