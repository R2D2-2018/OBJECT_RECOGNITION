#ifndef OBJECT_FINDER_HPP
#define OBJECT_FINDER_HPP

#include "feature_comparator.hpp"

/**
 * @brief   Object descriptor finding class
 * @file    object_finder.hpp
 * @author  Dylan Rakiman, Arsalan Anwari
 */
namespace lucidy
{

class ObjectFinder
{
private:
  FeatureComparator comparator;

  void initFinder();

public:
  ObjectFinder(settings::OBF::data &settings);

  bool isMatch(RootImage &sourceImage, SampleImage &sampleImage);

  FoundImageData checkMatch(RootImage &sourceImage, SampleImage &sampleImage);
  FoundImageList checkMatch(RootImage &sourceImage, SampleImageList &sampleImages);
};

} // namespace lucidy

#endif //OBJECT_FINDER_HPP
