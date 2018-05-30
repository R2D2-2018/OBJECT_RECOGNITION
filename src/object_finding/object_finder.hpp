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

namespace lucidy {

/**
 * @brief Object finding class
 *
 */
class ObjectFinder {
  private:
    FeatureComparator comparator;

    /**
     * @brief This function is used to initialise the object finder with some optional settings
     *
     */
    void initFinder();

  public:
    ObjectFinder(settings::OBF::data &settings);

    /**
     * @brief Function used to check wether two a sample image matches or come forth in a root image
     *
     * It returns a boolean specifying whether or not the algorithm determined the matchList to be valid.
     *
     * @param sourceImage : RootImage&
     * @param sampleImage : SampleImage&
     * @return bool
     */
    bool isMatch(RootImage &sourceImage, SampleImage &sampleImage);

    /**
     * @brief Function that returns a copy of the image to be tested, along with some additional data and whether or not it matched
     * The reason a copy should be made is so a list can be made of images with some meta data if they matched. This uses the
     * function isMatch()
     *
     * @param sourceImage : RootImage&
     * @param sampleImage : SampleImage&
     * @return FoundImageData
     */
    FoundImageData checkMatch(RootImage &sourceImage, SampleImage &sampleImage);

    /**
     * @brief Function that iterates through a list of sample images to determine any or all matches.
     *
     * @param sourceImage : RootImage&
     * @param sampleImage : SampleImage&
     * @return FoundImageList
     */
    FoundImageList checkMatch(RootImage &sourceImage, SampleImageList &sampleImages);
};

} // namespace lucidy

#endif // OBJECT_FINDER_HPP
