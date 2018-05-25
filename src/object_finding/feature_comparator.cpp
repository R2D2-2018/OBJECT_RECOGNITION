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

    void FeatureComparator::calcMatchList(RootImage & sourceImage, SampleImage & sampleImage){
        /// compute descriptors of both root and sample image. match them with descriptor matcher.
        /// calculated matches output is in matchList. return matchList. 
        detector.detectFeatures(sourceImage);
        if(sampleImage.features.size() <= 0 ){detector.detectFeatures(sampleImage);}
        descriptor.computeDescriptors(sourceImage);
        if(!sampleImage.descriptors.data ){ descriptor.computeDescriptors(sampleImage); }
        matcher.match(sampleImage.descriptors, sourceImage.descriptors, matchList);

        double max_dist = 0; double min_dist = 100;

        for( int i = 0; i < sampleImage.descriptors.rows; i++ ){ 
            double dist = matchList[i].distance;
            if( dist < min_dist ) {min_dist = dist;}
            if( dist > max_dist ) {max_dist = dist;}
        }
        
        MatchList goodMatches;
        for( int i = 0; i < sampleImage.descriptors.rows; i++ ) { 
            if( matchList[i].distance <= std::max(2*min_dist, 0.02) ){ goodMatches.push_back( matchList[i]); }
        }
        matchList.clear();
        matchList = goodMatches;
    }
    
    MatchList FeatureComparator::getMatchList(RootImage & sourceImage, SampleImage & sampleImage){
        /// compute descriptors of both root and sample image. match them with descriptor matcher.
        /// calculated matches output is in matchList. return matchList. 
        calcMatchList(sourceImage, sampleImage);
        return matchList;
    }

    MatchList FeatureComparator::getMatchList(){
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