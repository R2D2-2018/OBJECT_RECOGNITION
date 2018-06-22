/**
 * @file feature_descriptor.hpp
 *
 * @brief Feature descriptor file
 *
 * @details This file is used to compute orbit descriptors of a feature list.
 * OpenCV uses the same surf detector class for this operation. This mean a reference to a feature detector object should be made
 *
 * @author Arsalan Anwari
 *
 * @license See LICENSE
 *
 * @date 2018-05-16
 */

#ifndef FEATURE_DESCRIPTOR_HPP
#define FEATURE_DESCRIPTOR_HPP

#include "feature_detector.hpp"

namespace lucidy {
/**
 * @brief Feature descriptor class
 *
 */
class FeatureDescriptor {
  private:
    FeatureDetector &detector;
    settings::FDC::data &settings;
    SurfDetector &descriptor;
    DescriptorList descriptorList;

    /**
     * @brief Function used to change surf detector settings belonging to descriptors
     *
     */
    void initDescriptor();

  public:
    FeatureDescriptor(FeatureDetector &detector, settings::FDC::data &settings);

    /**
     * @brief Function used to compute descriptor list
     *
     * @param sourceImage : Image&
     * @return DescriptorList&
     */
    DescriptorList &getDescriptorList(Image &sourceImage);
};

} // namespace lucidy

#endif // FEATURE_DESCRIPTOR_HPP