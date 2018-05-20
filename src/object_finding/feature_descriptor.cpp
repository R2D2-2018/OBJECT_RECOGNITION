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

    DescriptorList& FeatureDescriptor::getDescriptorList(Image & sourceImage){
        /// compute descriptors by using featureList that has been precalculated by detector
        /// descriptor output will be placed in descriptorList
        /// if descriptorList has already been used a.k.a. is full remove all the content 

        /// if len (descriptorList) > 0: featureList.release();  
        descriptor->compute(sourceImage.get(), detector.getFeatureList(sourceImage), descriptorList );
        return descriptorList;
    }

}