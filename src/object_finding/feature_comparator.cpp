#include "feature_comparator.hpp"

namespace lucidy{

    FeatureComparator::FeatureComparator(lucidy::settings::OBF::data & settings):
        settings(settings),
        detector(settings.fdt),
        descriptor(detector, settings.fdc)
    {initMatcher();}

    void FeatureComparator::initMatcher(){
        /// initalize comparator with custom desires, nessecary has been done in constructor

    }

    PixelCoordinates FeatureComparator::getPixelCoordinates(MatchList & goodMatches, Image & image, const IMAGE_TYPE & type){
        PixelCoordinates data;
        if(type == IMAGE_TYPE::ROOT_IMAGE){ 
            for( cv::DMatch & match: goodMatches){ data.push_back(image.features[match.trainIdx].pt);}
        }else if(type == IMAGE_TYPE::SAMPLE_IMAGE){
            for( cv::DMatch & match: goodMatches){ data.push_back(image.features[match.queryIdx].pt);}
        }else{
            std::cout << "heh?";
        }
        return data;
    }

    void FeatureComparator::calcMatchList(RootImage & sourceImage, SampleImage & sampleImage){
        /// compute descriptors of both root and sample image. match them with descriptor matcher.
        /// calculated matches output is in matchList. return matchList. 
        for(MatchList & elem : matchList){
            elem.clear();
        } matchList.clear();
        goodMatches.clear();
        
        detector.detectFeatures(sourceImage);
        if( sampleImage.features.size() <= 0 ){detector.detectFeatures(sampleImage);}
        if ( !descriptor.computeDescriptors(sourceImage) ){ return; }
        if( !sampleImage.descriptors.data ){ 
            if(!descriptor.computeDescriptors(sampleImage)){ return; } 
        }
        
        matcher.knnMatch(sampleImage.descriptors, sourceImage.descriptors, matchList, 2);
        if (matchList.size() <= 0){return;}
        for (int k = 0; k < std::min(sampleImage.descriptors.rows - 1, (int)matchList.size()); k++){
            if ( 
                (matchList[k][0].distance < 0.6*(matchList[k][1].distance)) &&
                ((int)matchList[k].size() <= 2 && (int)matchList[k].size()>0) 
            ){
                goodMatches.push_back( matchList[k][0] );
            }
        }
    }
    
    MatchList FeatureComparator::getMatchList(RootImage & sourceImage, SampleImage & sampleImage){
        /// compute descriptors of both root and sample image. match them with descriptor matcher.
        /// calculated matches output is in matchList. return matchList. 
        calcMatchList(sourceImage, sampleImage);
        return goodMatches;
    }

    MatchList FeatureComparator::getMatchList(){
        return goodMatches;
    }

    AffineMatrix FeatureComparator::calcAffineMatrix(RootImage & sourceImage, SampleImage & sampleImage){
        /// use algorithm to calculate affine transformation matrix of sampleImage into sourceImage
        /// .. some calculations later ..
        MatchList goodMatches = getMatchList();
        PixelCoordinates sample = getPixelCoordinates(goodMatches, sampleImage, IMAGE_TYPE::SAMPLE_IMAGE);
	    PixelCoordinates root = getPixelCoordinates(goodMatches, sourceImage, IMAGE_TYPE::ROOT_IMAGE);
        T = cv::Mat();
        try {
            // if (sample.size() < 0 || root.size() < 0){return T;} 
            T  = cv::findHomography(sample, root, cv::RANSAC); 
        }catch(cv::Exception & err){}
        return T;
    }

    Vector FeatureComparator::calcPos(AffineMatrix & data){
        /// use complex algorithm to calculate {ask Dylan} position
        return Vector{1,1};


    }

    Vector FeatureComparator::calcOrientation(AffineMatrix & data){
        /// use compex algorithm to calculate oriantation assignment using featurelist 
        return Vector{1,1};
    }


}