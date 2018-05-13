#ifndef FEATURE_COMPARATOR_HPP
#define FEATURE_COMPARATOR_HPP

#include "feature_descriptor.hpp"
#include "../image/root_image.hpp"
#include "../image/sample_image.hpp"

namespace lucidy{

class FeatureComparator{
private:
    lucidy::settings::OBF::data & settings;
    cv::DescriptorMatcher matcher;
    MatchList matchList;

    FeatureDetector detector;
    FeatureDescriptor descriptor;

    void initMatcher();
public:
    FeatureComparator(lucidy::settings::OBF::data & settings);

    MatchList getMatchList(RootImage & sourceImage, SampleImage & sampleImage);
    AffineMatrix calcAffineMatrix(RootImage & sourceImage, SampleImage & sampleImage);
    Vector calcPos(FeatureList & data);
    Vector calcOrientation(FeatureList & data);



};

}

#endif //FEATURE_COMPARATOR_HPP

