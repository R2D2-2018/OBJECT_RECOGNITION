#ifndef OPEN_CV_TYPES_HPP
#define OPEN_CV_TYPES_HPP

#include <vector>
#include "open_cv.hpp"
#include "../../image/sample_image.hpp"

namespace lucidy{
    typedef std::vector<cv::KeyPoint> FeatureList;
    typedef cv::Ptr<cv::xfeatures2d::SURF> SurfDetector;
    typedef cv::Mat DescriptorList;
    typedef struct{int x; int y;} Vector;
    typedef std::vector<cv::Match> MatchList;
    typedef cv::Mat AffineMatrix;

    struct FoundImageData{ SampleImage image; AffineMatrix matrix; bool match; };
    typedef std::vector<FoundImageData> FoundImageList;

}
#endif //OPEN_CV_TYPES_HPP

