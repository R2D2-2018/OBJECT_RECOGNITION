/**
 * @file object_finder.hpp
 * 
 * @brief Module communication class file
 * 
 * @details This file contains the class which will be used as the module
 * All operations to find an object or recognise one should go through this class
 * 
 * @author Arsalan Anwari
 * 
 * @license See LICENSE
 * 
 * @date 2018-05-16
 */

#ifndef OBJECT_FINDER_HPP
#define OBJECT_FINDER_HPP

#include "feature_comparator.hpp"

namespace lucidy
{

/**
 * @brief Object finding class
 * 
 */
class ObjectFinder
{
private:
  FeatureComparator comparator;

  /**
   * @brief This function is used to initialize the object finder with some optional settings
   * 
   */
  void initFinder();

public:
  ObjectFinder(settings::OBF::data &settings);

  /**
   * @brief Function used to check wether two a sample image matches or come forth in a root image
   * @param sourceImage 
   * @param sampleImage 
   * @return true : algorithm determines matchlist is valid
   * @return false : algorithm determines matchlist is invalid
   */
  bool isMatch(RootImage &sourceImage, SampleImage &sampleImage);

  /**
   * @brief Function that returns a copy of the to be tested image with some additional data and if it matched
   * @details The reason a copy should be made is so a list can be made of images with some meta data if they matched. This uses the function isMatch()
   * @param sourceImage 
   * @param sampleImage 
   * @return FoundImageData 
   */
  FoundImageData checkMatch(RootImage &sourceImage, SampleImage &sampleImage);

  /**
   * @brief Function that iterates through a list of sample images t determain which of them matched. 
   * 
   * @param sourceImage 
   * @param sampleImages 
   * @return FoundImageList 
   */
  FoundImageList checkMatch(RootImage &sourceImage, SampleImageList &sampleImages);
};

} // namespace lucidy

#endif //OBJECT_FINDER_HPP
