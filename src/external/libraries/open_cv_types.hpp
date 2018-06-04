/**
 * @brief Adapter file that defines custom types from openCV
 * @details This file includes and uses types and classes from the library openCV 
 * and implements them with a custom name.
 * @file open_cv_types.hpp
 * @author Arsalan Anwari, Dylan Rakiman
 * @date 2018-05-15
 */

#ifndef OPEN_CV_TYPES_HPP
#define OPEN_CV_TYPES_HPP

#include <vector>
#include "open_cv.hpp"

namespace lucidy{
    typedef std::vector<cv::KeyPoint> FeatureList;
    typedef cv::Ptr<cv::xfeatures2d::SURF> SurfDetector;
    typedef cv::Mat DescriptorList;
    typedef struct{int x; int y;} Vector;
    typedef std::vector< cv::DMatch > MatchList;
    typedef cv::Mat AffineMatrix;
    typedef std::vector<cv::Point2f> PixelCoordinates;

    struct FoundImageData{ int id; AffineMatrix matrix; bool match; };
    typedef std::vector<FoundImageData> FoundImageList;

}
#endif //OPEN_CV_TYPES_HPP

