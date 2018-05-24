#include "feature_comparator.hpp"

namespace lucidy{

    FeatureComparator::FeatureComparator(lucidy::settings::OBF::data & settings):
        settings(settings),
        matcher(cv::NORM_L2),
        detector(settings.fdt),
        descriptor(detector, settings.fdc)
    {initMatcher();}

    void FeatureComparator::initMatcher(){
        /// initalize comparator with custom desires, nessecary has been done in constructor

    }
    
    MatchList FeatureComparator::getMatchList(RootImage & sourceImage, SampleImage & sampleImage){
        /// compute descriptors of both root and sample image. match them with descriptor matcher.
        /// calculated matches output is in matchList. return matchList. 
        DescriptorList source = descriptor.getDescriptorList(sourceImage);
        DescriptorList sample = descriptor.getDescriptorList(sampleImage);
        matcher.match(sample, source, matchList);
        return matchList;
    }
    
    AffineMatrix FeatureComparator::calcAffineMatrix(RootImage & sourceImage, SampleImage & sampleImage){
        /// use complex algorithm to calculate affine transformation matrix of sampleImage into sourceImage
        /// .. some calculations later ..
        
        /// remove sample code below
        AffineMatrix tmp;
        return tmp;
    }

    Vector FeatureComparator::calcPos(FeatureList & data){
        /// use complex algorithm to calculate {ask Dylan} position
        return Vector{1,1};


    }

    Vector FeatureComparator::calcOrientation(FeatureList & data){
        /// use compex algorithm to calculate oriantation assignment using featurelist 
        return Vector{1,1};
    }


}