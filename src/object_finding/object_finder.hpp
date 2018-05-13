#ifndef OBJECT_FINDER_HPP
#define OBJECT_FINDER_HPP

#include "feature_comparator.hpp"

namespace lucidy{

class ObjectFinder{
private:
    FeatureComparator comparator;

    void initFinder();
public:
    ObjectFinder(settings::OBF::data & settings);

    bool isMatch(RootImage & sourceImage, SampleImage & sampleImage);

    FoundImageData checkMatch(RootImage & sourceImage, SampleImage & sampleImage);
    FoundImageList checkMatch(RootImage & sourceImage, SampleImageList & sampleImages);

};

}

#endif //OBJECT_FINDER_HPP

