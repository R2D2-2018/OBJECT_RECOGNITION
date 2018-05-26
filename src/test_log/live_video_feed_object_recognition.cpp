/**
 * @brief Vertical slice 3 UNIT TEST
 * @details This file contains the unit test with catch2 of the current Vertical Slice 2
 * Please uncomment the code and put the following code in the file "CMakeLists.txt"
 *      - src/test_log/image_parser_viewer.cpp
 * @file live_video_feed_object_recognition.cpp
 * @author Arsalan Anwari
 * @date 2018-05-25
 */

#define CATCH_CONFIG_MAIN
#include "/home/arsalan/ti-software/Build-environment/libraries/Catch2/single_include/catch.hpp"

#include "../object_finding/object_finder.hpp"


TEST_CASE("Feature comparator good match test", "AlgorithmTest"){

    lucidy::settings::IMG::data imgSet{cv::IMREAD_GRAYSCALE};
    lucidy::settings::OBF::data compSet{
        lucidy::settings::FDT::data{400},
        lucidy::settings::FDC::data{false, true}
    };

    lucidy::RootImage bill("/home/arsalan/Pictures/bill_gates.jpg", imgSet);
    lucidy::SampleImage wouter("/home/arsalan/Pictures/woutah.jpg", imgSet);
    lucidy::FeatureComparator comparator(compSet);

    lucidy::MatchList result = comparator.getMatchList(bill, wouter);

    REQUIRE( result.size() > 0 );
    REQUIRE( result.size() <= wouter.descriptors.rows );
}

TEST_CASE("Object finder match percentage test", "FormulaTest"){

    lucidy::settings::IMG::data imgSet{cv::IMREAD_GRAYSCALE};
    lucidy::settings::OBF::data compSet{
        lucidy::settings::FDT::data{400},
        lucidy::settings::FDC::data{false, true}, 10.0
    };

    lucidy::RootImage bill("/home/arsalan/Pictures/bill_gates.jpg", imgSet);
    lucidy::SampleImage wouter("/home/arsalan/Pictures/woutah.jpg", imgSet);

    lucidy::ObjectFinder finder(compSet);

    float result = finder.calcMatch(bill, wouter);

    REQUIRE(compSet.matchThreshold > 0.0);
    REQUIRE(compSet.matchThreshold == 10.0);
    REQUIRE(result > 0.0);
    REQUIRE(result >= 10.0);
    REQUIRE(result >= compSet.matchThreshold );

}

TEST_CASE("Object finder match check test", "CompareTest"){

    lucidy::settings::IMG::data imgSet{cv::IMREAD_GRAYSCALE};
    lucidy::settings::OBF::data compSet{
        lucidy::settings::FDT::data{400},
        lucidy::settings::FDC::data{false, true}, 10.0
    };

    lucidy::RootImage bill("/home/arsalan/Pictures/bill_gates.jpg", imgSet);
    lucidy::SampleImage wouter("/home/arsalan/Pictures/woutah.jpg", imgSet);

    lucidy::ObjectFinder finder(compSet);

    bool result = finder.isMatch(bill,wouter);

    REQUIRE(compSet.matchThreshold > 0.0);
    REQUIRE(compSet.matchThreshold == 10.0);
    REQUIRE(result);
}

TEST_CASE("Object finder single match meta data test", "DataTest"){

    lucidy::settings::IMG::data imgSet{cv::IMREAD_GRAYSCALE};
    lucidy::settings::OBF::data compSet{
        lucidy::settings::FDT::data{400},
        lucidy::settings::FDC::data{false, true}, 10.0
    };

    lucidy::RootImage bill("/home/arsalan/Pictures/bill_gates.jpg", imgSet);
    lucidy::SampleImage wouter("/home/arsalan/Pictures/woutah.jpg", imgSet);

    lucidy::ObjectFinder finder(compSet);

    lucidy::FoundImageData result = finder.checkMatch(bill, wouter);
    
    REQUIRE(compSet.matchThreshold > 0.0);
    REQUIRE(compSet.matchThreshold == 10.0);
    REQUIRE(result.id == 1);
    REQUIRE(result.match);
    REQUIRE(!result.matrix.data);
}

TEST_CASE("Object finder list of matches meta data test", "DataTest"){

    lucidy::settings::IMG::data imgSet{cv::IMREAD_GRAYSCALE};
    lucidy::settings::OBF::data compSet{
        lucidy::settings::FDT::data{400},
        lucidy::settings::FDC::data{false, true}, 10.0
    };

    lucidy::RootImage bill("/home/arsalan/Pictures/bill_gates.jpg", imgSet);
    lucidy::SampleImageList wouters{
        lucidy::SampleImage("/home/arsalan/Pictures/woutah.jpg", imgSet),
        lucidy::SampleImage("/home/arsalan/Pictures/wouter2.jpg", imgSet),
        lucidy::SampleImage("/home/arsalan/Pictures/woutah3.jpg", imgSet)
    };
    lucidy::ObjectFinder finder(compSet);

    lucidy::FoundImageList results = finder.checkMatch(bill, wouters);
    
    REQUIRE(compSet.matchThreshold > 0.0);
    REQUIRE(compSet.matchThreshold == 10.0);

    for (auto & result : results){
        REQUIRE(result.id == 1);
        REQUIRE( result.match );
        REQUIRE(!result.matrix.data);
    }

}

/// GUI TEST CANNOT BE DONE PROPERLY WITH CI Travis.yml