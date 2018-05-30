/**
 * @brief Vertical slice 1 UNIT TEST
 * @details This file contains unit tests in Catch2 of Vertical Slice 1
 *
 * @file image_parser_viewer.cpp
 * @author Arsalan Anwari, Dylan Rakiman
 * @date 2018-05-19
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <stdlib.h>

#include "../src/external/settings.hpp"
#include "../src/external/types.hpp"
#include "../src/image/root_image.hpp"
#include "../src/image/sample_image.hpp"
#include "../src/window/image_viewer.hpp"
#include "../src/window/interface/gui.hpp"

TEST_CASE("Window size comparisons succesfull", "Type Test") {
    for (int n = 0; n < 10; ++n) {
        lucidy::WindowSize tmp{n, n};
        REQUIRE((tmp.height == n && tmp.width == n));
    }
}

TEST_CASE("Coordinate comparisons succesfull", "Type Test") {
    for (int n = 0; n < 10; ++n) {
        lucidy::Coordinate tmp{n, n};
        REQUIRE((tmp.x == n && tmp.y == n));
    }
}

TEST_CASE("Settings passtrough succesfull", "Setting Test") {
    lucidy::settings::WIN::GUI::data source{"TestWindow", 1, lucidy::WindowSize{1, 1}, lucidy::Coordinate{10, 10}};
    lucidy::settings::WIN::GUI::data test = source;
    bool b = ((test.name == source.name && test.flag == source.flag) &&
              ((test.windowSize.height == source.windowSize.height && test.windowSize.width == source.windowSize.width) &&
               (test.windowPosition.x == source.windowPosition.x && test.windowPosition.y == source.windowPosition.y)));

    REQUIRE(b);
}

// TEST_CASE("RootImage user input parser ", "UserInput Test"){
//     lucidy::RootImage test;
//     test.set();
//     REQUIRE( test.get().data );
// }

/// Sets the file location of our sample image, namely the same folder as test_main.cpp
std::string source_path = __FILE__;
std::string str_path = source_path.substr(0, source_path.rfind("/")) + "/sample.jpg";
const char *path = str_path.c_str();
const char *wrong_path = "WRONG_PATH";

TEST_CASE("RootImage normal parser ", "Input Test") {
    lucidy::RootImage test1;
    REQUIRE(test1.set(path) == true);
    REQUIRE(test1.set(wrong_path) == false);

    lucidy::settings::IMG::data tmp{1};
    lucidy::RootImage test2(path, tmp);
    REQUIRE(test2.get().data);
    REQUIRE(test2.set(path) == true);
    REQUIRE(test2.set(wrong_path) == false);
}

// TEST_CASE("SampleImage user input parser ", "UserInput Test"){
//     lucidy::SampleImage test;
//     test.set();
//     REQUIRE( test.get().data );
// }

TEST_CASE("SampleImage normal parser ", "Input Test") {
    lucidy::SampleImage test1;
    REQUIRE(test1.set(path) == true);
    REQUIRE(test1.set(wrong_path) == false);

    lucidy::settings::IMG::data tmp{1};
    lucidy::SampleImage test2(path, tmp);

    REQUIRE(test2.get().data);
    REQUIRE(test2.set(path) == true);
    REQUIRE(test2.set(wrong_path) == false);

    lucidy::SampleImage test3;
    test3.set(test2);
    REQUIRE(test3.get().data == test2.get().data);
}

TEST_CASE("GUI window basic util test", "GUI Test") {
    lucidy::Gui test;
    test.init();

    /// state get test
    states tmp = test.getState();
    REQUIRE(test.getState() == tmp);

    /// open test
    test.open();
    REQUIRE(test.getState() == states::open);

    /// hide test
    test.hide();
    REQUIRE(test.getState() == states::hidden);

    /// close test
    test.close();
    REQUIRE(test.getState() == states::closed);
}

TEST_CASE("ImageViewer basic util test", "GUI Test") {
    lucidy::RootImage img;
    img.set(path);

    lucidy::settings::WIN::GUI::data tmp{"TestWindow", 1, lucidy::WindowSize{400, 400}, lucidy::Coordinate{200, 300}};
    lucidy::ImageViewer test(tmp);

    test.show(img);
    int k = cv::waitKey(1000);
    if (k == 27) {
        cv::destroyAllWindows();
    }

    REQUIRE(1 == 1);
}
