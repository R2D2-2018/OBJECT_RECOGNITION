/**
 * @file feature_detector.hpp
 * 
 * @brief Feature set detector file
 * 
 * @details This file is used to detect features out of an image and put them into a feature list
 * This is done by using a openCV function named SURF.detect()

 * @author Arsalan Anwari
 * 
 * @license See LICENSE
 * 
 * @date 2018-05-16
 */

#ifndef FEATURE_DETECTOR_HPP
#define FEATURE_DETECTOR_HPP

#include "../image/image.hpp"
#include "../external/settings.hpp"
#include "../external/libraries/open_cv_types.hpp"


namespace lucidy
{

/**
 * @brief Feature detector class
 * 
 */
class FeatureDetector
{
private:
  SurfDetector detector;
  settings::FDT::data &settings;
  FeatureList featureList;

  /**
   * @brief Function used to initialize the surf detector with their belonging setting 
   * 
   */
  void initDetector();

public:
  FeatureDetector(settings::FDT::data &settings);

  /**
   * @brief Function used to return last detected FeatureList
   * 
   * @param sourceImage 
   * @return FeatureList& 
   */
  FeatureList &getFeatureList(Image &sourceImage);
  
  /**
   * @brief Function used to return SURF detector so it can be used by another class 
   * 
   * @return SurfDetector& 
   */
  SurfDetector &getDetector();

  /**
   * @brief Function used to change the settings of the surf detector 
   * 
   * @param new_data 
   */
  void changeSettings(const settings::FDT::data &new_data);
  
  /**
   * @brief Function used to return current settings of the surf detector
   * 
   * @return settings::FDT::data& 
   */
  settings::FDT::data &getSettings();
};

} // namespace lucidy

#endif //FEATURE_DETECTOR_HPP