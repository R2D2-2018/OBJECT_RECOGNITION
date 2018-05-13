#include "object_finder.hpp"

namespace lucidy{

    

    ObjectFinder::ObjectFinder(settings::OBF::data & settings):
        comparator(settings)
    {}

    void ObjectFinder::initFinder(){
        // initialize object finder with custom things. The nessecary has been done in constructor so
        // this is optional!

    }

    bool ObjectFinder::isMatch(RootImage & sourceImage, SampleImage & sampleImage){
        // use a complex algorithm to decide wether the match results are valid. return true of false
        
        MatchList results = comparator.getMatchList(sourceImage, sampleImage );
        // if result == ?something? return true : return false;
        return true;

    }

    FoundImageData ObjectFinder::checkMatch(RootImage & sourceImage, SampleImage & sampleImage){
        // check weather sample image isMatch and change its validy if it valid
        // return FoundImageData of sampleImage
        bool valid = false;
        if ( isMatch( sourceImage, sampleImage ) ){ valid = true; }
        
        FoundImageData temp;
        temp.image = sampleImage;
        temp.matrix = comparator.calcAffineMatrix(sourceImage, sampleImage);
        temp.match = valid;
            
        return temp;     
    }

    FoundImageList ObjectFinder::checkMatch(RootImage & sourceImage, SampleImageList & sampleImages){
        // iterate trough a series of sample images to check wether they match the root image. 
        // append all image data to a FoundImageList with the member function call checkMatch()
        // return FoundImageList

        FoundImageList tmp;
        for (SampleImage & img : sampleImages){
            tmp.push_back( checkMatch(sourceImage, img) );
        }

        return tmp;
    }


}