/**
 * @brief Vertical slice 2 UNIT TEST
 * @details This file contains the unit test with catch2 of the current Vertical Slice 2
 * Please uncomment the code and put the following code in the file "CMakeLists.txt"
 *      - src/test_log/image_parser_viewer.cpp
 *
 * @file image_parser_viewer.cpp
 * @author Arsalan Anwari
 * @date 2018-05-19
 */

// #define CATCH_CONFIG_MAIN
// #include "/home/arsalan/ti-software/Build-environment/libraries/Catch2/single_include/catch.hpp"

// #include "../external/types.hpp"
// #include "../external/settings.hpp"
// #include "../image/root_image.hpp"
// #include "../image/sample_image.hpp"
// #include "../window/interface/gui.hpp"
// #include "../window/image_viewer.hpp"

// TEST_CASE("Window size comparisons succesfull", "Type Test"){
//     for(int n=0; n<10; ++n){
//         lucidy::WindowSize tmp{n,n};
//         REQUIRE( (tmp.height == n && tmp.width == n) );
//     }
// }

// TEST_CASE("Coordinate comparisons succesfull", "Type Test"){
//     for(int n=0; n<10; ++n){
//         lucidy::Coordinate tmp{n,n};
//         REQUIRE( (tmp.x == n && tmp.y == n) );
//     }
// }

// TEST_CASE("Settings passtrough succesfull", "Setting Test"){
//     lucidy::settings::WIN::GUI::data source{"TestWindow", 1, lucidy::WindowSize{1,1}, lucidy::Coordinate{10,10}};
//     lucidy::settings::WIN::GUI::data test = source;
//     bool b = (
//         (test.name == source.name && test.flag == source.flag) &&
//         (
//             (test.windowSize.height == source.windowSize.height && test.windowSize.width == source.windowSize.width) &&
//             (test.windowPosition.x == source.windowPosition.x && test.windowPosition.y == source.windowPosition.y )
//         )
//     );

//     REQUIRE( b );
// }

// TEST_CASE("RootImage user input parser is correct", "UserInput Test"){
//     lucidy::RootImage test;
//     test.set();
//     REQUIRE( test.get().data );
// }

// TEST_CASE("RootImage normal parser is correct", "Input Test"){
//     lucidy::RootImage test1;
//     test1.set("/home/arsalan/Pictures/woutah.jpg");
//     REQUIRE( test1.get().data );

//     lucidy::settings::IMG::data tmp{1};
//     lucidy::RootImage test2("/home/arsalan/Pictures/woutah.jpg", tmp );
//     REQUIRE( test2.get().data );
// }

// TEST_CASE("SampleImage user input parser is correct", "UserInput Test"){
//     lucidy::SampleImage test;
//     test.set();
//     REQUIRE( test.get().data );
// }

// TEST_CASE("SampleImage normal parser is correct", "Input Test"){
//     lucidy::SampleImage test1;
//     test1.set("/home/arsalan/Pictures/woutah.jpg");

//     REQUIRE( test1.get().data );

//     lucidy::settings::IMG::data tmp{1};
//     lucidy::SampleImage test2("/home/arsalan/Pictures/woutah.jpg", tmp );
//     REQUIRE( test2.get().data );

//     lucidy::SampleImage test3;
//     test3.set(test2);
//     REQUIRE( test3.get().data == test2.get().data );
// }

// TEST_CASE("GUI window basic util test", "GUI Test"){
//     lucidy::Gui test;
//     test.init();

//     /// state get test
//     states tmp = test.getState();
//     REQUIRE (test.getState() == tmp );

//     /// open test
//     test.open();
//     REQUIRE( test.getState() == states::open );

//     /// hide test
//     test.hide();
//     REQUIRE( test.getState() == states::hidden );

//     /// close test
//     test.close();
//     REQUIRE( test.getState() == states::closed );
// }

// TEST_CASE("ImageViewer basic util test", "GUI Test"){
//     lucidy::settings::WIN::GUI::data tmp{"TestWindow", 1, lucidy::WindowSize{400, 400}, lucidy::Coordinate{200,300} };
//     lucidy::ImageViewer test(tmp);
//     lucidy::RootImage img;
//     img.set("/home/arsalan/Pictures/woutah.jpg");

//     test.show(img);
//     int k = cv::waitKey(1000);
//     if (k == 27){
//         cv::destroyAllWindows();
//     }

//     REQUIRE(1==1);
// }
