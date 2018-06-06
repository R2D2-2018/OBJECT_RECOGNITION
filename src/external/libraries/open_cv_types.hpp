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
    /**
     * @brief Used to store features of image
     * 
     */
    using FeatureList = std::vector<cv::KeyPoint>;

    /**
     * @brief Used to create a surf detector
     * 
     */
    using SurfDetector = cv::Ptr<cv::xfeatures2d::SURF>;

    /**
     * @brief used to store computed descriptors of feature list
     * 
     */
    using DescriptorList = cv::Mat;

    /**
     * @brief used to store descriptor macthes
     * 
     */
    using MatchList = std::vector< cv::DMatch >;

    /**
     * @brief Matrix that represents Homograph matrix
     * 
     */
    using AffineMatrix = cv::Mat;

    /**
     * @brief used to indicate pixel coordinate 
     * 
     */
    using PixelCoordinates = std::vector<cv::Point2f> ;

    /**
     * @brief used to represent a 2d coordinate (not pixel coordinate)
     * 
     */
    struct Vector{int x; int y;};

    /**
     * @brief used to story found image with id and homograph matrix
     * 
     */
    struct FoundImageData{ int id; AffineMatrix matrix; bool match; };

    /**
     * @brief used to story a list of FoundImagaData
     * 
     */
    using FoundImageList = std::vector<FoundImageData>;

}
#endif //OPEN_CV_TYPES_HPP

