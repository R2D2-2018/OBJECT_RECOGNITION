/**
 * @brief Module communication class file
 * @details This file contains the class which will be used as the module
 * All operations to find an object or recognise one should go through this class
 * @file object_finder.hpp
 * @author Arsalan Anwari
 * @date 2018-05-16
 */

#ifndef OBJECT_FINDER_HPP
#define OBJECT_FINDER_HPP

#include "feature_comparator.hpp"
#include <cmath>
#include <cstdlib>
namespace lucidy
{

/**
 * @brief Object finding class
 * 
 */
class ObjectFinder
{
private:
  FeatureComparator comparator; //copy of comparator
  float & matchThreshold; //copy of threshold 
  
  /**
   * @brief This function is used to initialize the object finder with some optional settings
   * 
   */
  void initFinder();
  
  /**
   * @brief This function is used to draw a line on an image
   * 
   * @param output : cv::Mat&
   * @param start : cv::Point2f const&
   * @param end 
   * @param color 
   * @param lineWidth 
   */
  void drawLine(cv::Mat & output, const cv::Point2f & start, const cv::Point2f & end, const cv::Scalar & color, const int & lineWidth = 4);
  
  /**
   * @brief This function is used to draw a square which takes perspective into consideration
   * 
   * @param input : sample image 
   * @param output : image
   * @param T : homography matrix
   * @param color 
   */
  void drawSquare(const cv::Mat & input, cv::Mat & output, AffineMatrix & T, const cv::Scalar & color = cv::Scalar(66,66,244) );
  
  /**
   * @brief This function is used to draw a triangle on the screen
   * @details perspective is not taken into consieration. 
   * @param input 
   * @param output 
   * @param color 
   */
  void drawTriangle(PixelCoordinates & input, cv::Mat & output, const cv::Scalar & color = cv::Scalar(66,66,244) );
  

public:
  ObjectFinder(settings::OBF::data &settings);

  /**
   * @brief Function used to check the percentage a sample image matches with the root image
   * @param sourceImage 
   * @param sampleImage 
   * @return float 
   */
  float calcMatch(RootImage &sourceImage, SampleImage &sampleImage);

  /**
   * @brief Function used to draw match with a indicator based on the amount of good matches on a image 
   * 
   * @param input 
   * @param output 
   * @param goodMatches 
   */
  void drawMatch(SampleImage & input, RootImage & output, MatchList & goodMatches);

  /**
   * @brief Funciton used to draw a circle on a image without taking perspecitve into consideration 
   * 
   * @param input 
   * @param output 
   * @param radius 
   * @param color 
   */
  void drawCircle(MatchList & input, RootImage & output, const int & radius, const cv::Scalar & color = cv::Scalar(66,66,244) );
  
  /**
   * @brief Function used a passtrough getter to retreive latest calculated matchlist 
   * @return MatchList 
   */
  MatchList getMatches();

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
