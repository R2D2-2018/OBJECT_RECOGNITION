/**
 * @brief Feature comparator file
 * @details This file contains the class with the main logic, to compare two descriptor lists
 * of the source and root image. A descriptor list is based of a feature list
 * @file feature_comparator.hpp
 * @author Arsalan Anwari
 * @date 2018-05-25
 */
#ifndef FEATURE_COMPARATOR_HPP
#define FEATURE_COMPARATOR_HPP

#include "feature_descriptor.hpp"
#include "../image/root_image.hpp"
#include "../image/sample_image.hpp"

namespace lucidy
{
/**
 * @brief feature comparator class
 * @details contains both a detector and descriptor
 */
class FeatureComparator
{
private:
  lucidy::settings::OBF::data &settings;
  cv::BFMatcher matcher;
  MatchList matchList;

  FeatureDetector detector;
  FeatureDescriptor descriptor;

  /**
   * @brief Function used to pass initilaize detector and descriptor with their settings
   * 
   */
  void initMatcher();

public:
  FeatureComparator(lucidy::settings::OBF::data &settings);

  /**
   * @brief Function that uses an algorithm to recognize matches between two descriptor lists.
   * @details simple FLANN algorithm is used to find good matches. 
   * @param sourceImage 
   * @param sampleImage 
   * @warning If sample image already contains descriptors or features, these will not be recalculated again. 
   * Please clear those first
   */
  void calcMatchList(RootImage &sourceImage, SampleImage &sampleImage);

  /**
   * @brief Function that uses an algorithm to recognize matches between two descriptor lists. 
   * @details simple FLANN algorithm is used to find good matches. goodmatches are returned 
   * @param sourceImage 
   * @param sampleImage 
   * @return MatchList 
   * @warning If sample image already contains descriptors or features, these will not be recalculated again. 
   * Please clear those first
   */
  MatchList getMatchList(RootImage &sourceImage, SampleImage &sampleImage);

  /**
   * @brief Function used to return latest calculated matchlist
   * 
   * @return MatchList 
   */
  MatchList getMatchList();

  /**
   * @brief Function used to calculate the sample image affine matrix that contains both position and orientation
   * 
   * @param sourceImage 
   * @param sampleImage 
   * @return AffineMatrix 
   */
  AffineMatrix calcAffineMatrix(RootImage &sourceImage, SampleImage &sampleImage);

  /**
   * @brief Function used to calculate position of sample image
   * 
   * @param data 
   * @return Vector 
   */
  Vector calcPos(FeatureList &data);

  /**
   * @brief Function used to calculate orientation of sample image
   * 
   * @param data 
   * @return Vector 
   */
  Vector calcOrientation(FeatureList &data);
};

} // namespace lucidy

#endif //FEATURE_COMPARATOR_HPP
