#define CATCH_CONFIG_MAIN
#include "../src/open_cv.hpp"
#include "catch.hpp"

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
