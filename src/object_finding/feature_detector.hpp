#ifndef FEATURE_DETECTOR_HPP
#define FEATURE_DETECTOR_HPP

#include "../image/image.hpp"
#include "../external/settings.hpp"
#include "../external/libraries/open_cv_types.hpp"

/**
 * @brief   Feature set detecting class
 * @file    feature_detector.hpp
 */
namespace lucidy
{

class FeatureDetector
{
  private:
    SurfDetector detector;
    settings::FDT::data &settings;
    FeatureList featureList;

    void initDetector();

  public:
    FeatureDetector(settings::FDT::data &settings);

    FeatureList &getFeatureList(Image &sourceImage);
    SurfDetector &getDetector();
    void changeSettings(const settings::FDT::data &new_data);
    settings::FDT::data &getSettings();
};

} // namespace lucidy

#endif //FEATURE_DETECTOR_HPP