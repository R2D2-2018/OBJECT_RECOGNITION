/**
 * @file feature_comparator.hpp
 *
 * @brief Feature comparator file
 *
 * @details This file contains the class with the main logic, to compare two descriptor lists
 * of the source and root image. A descriptor list is based of a feature list

 * @author Arsalan Anwari
 *
 * @license See LICENSE
 *
 * @date 2018-05-16
 */
#ifndef FEATURE_COMPARATOR_HPP
#define FEATURE_COMPARATOR_HPP

#include "../image/root_image.hpp"
#include "../image/sample_image.hpp"
#include "feature_descriptor.hpp"

namespace lucidy {
/**
 * @brief feature comparator class
 *
 * Contains both a detector and descriptor
 */
class FeatureComparator {
  private:
    lucidy::settings::OBF::data &settings;
    cv::BFMatcher matcher;
    MatchList matchList;

    FeatureDetector detector;
    FeatureDescriptor descriptor;

    /**
     * @brief Function used to initialise detector and descriptor with the specified settings.
     */
    void initMatcher();

  public:
    FeatureComparator(lucidy::settings::OBF::data &settings);

    /**
     * @brief Function that uses an algorithm to recognize matches between two descriptor lists.
     *
     * @param sourceImage  : RootImage&
     * @param sampleImage : SampleImage&
     * @return MatchList
     */
    MatchList getMatchList(RootImage &sourceImage, SampleImage &sampleImage);

    /**
     * @brief Function used to calculate the sample image affine matrix that contains position and orientation
     *
     * @param sourceImage : RootImage&
     * @param sampleImage : SampleImage&
     * @return AffineMatrix
     */
    AffineMatrix calcAffineMatrix(RootImage &sourceImage, SampleImage &sampleImage);

    /**
     * @brief Function used to calculate position of sample image
     *
     * @param data : FeatureList&
     * @return Vector
     */
    Vector calcPos(FeatureList &data);

    /**
     * @brief Function used to calculate orientation of sample image
     *
     * @param data : FeatureList&
     * @return Vector
     */
    Vector calcOrientation(FeatureList &data);
};

} // namespace lucidy

#endif // FEATURE_COMPARATOR_HPP
