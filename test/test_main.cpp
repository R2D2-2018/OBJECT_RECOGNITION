#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/open_cv.hpp"
#include "../src/sample_image.hpp"

///< VS7
TEST_CASE("openCV -- Load image", "[loadImage]") {
    ///< Preconditions:
    cv::Mat image = cv::imread("", -1);
    bool isFaulty = false;

    ///< Run Test:
    if (!image.data) {
        isFaulty = true;
    }

    ///< Compare Postconditions:
    REQUIRE(isFaulty == true);
}

///< VS8
TEST_CASE("SampleImage -- empty constructor", "[SampleImage],[imagePaths]") {
    ///< Preconditions:
    SampleImage sampleImage_0;
    SampleImage sampleImage_1;

    ///< Run Test:
    bool valid_0 = sampleImage_0.getIsValid();
    sampleImage_1.setPath(sampleImage_0);
    bool valid_1 = sampleImage_1.getIsValid();

    ///< Compare Postconditions:
    REQUIRE(valid_0 == false);
    REQUIRE(valid_1 == false);
}