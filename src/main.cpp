// #include "object_finding/object_finder.hpp"
// #include "window/video_controller.hpp"
// #include <fstream>

// lucidy::settings::OBF::data tmp{
//   lucidy::settings::FDT::data{400},
//   lucidy::settings::FDC::data{},
//   50.0
// };

// lucidy::settings::IMG::data imgSet{cv::IMREAD_COLOR};

// lucidy::settings::WIN::GUI::VIW::data recordSet{
//   lucidy::settings::WIN::GUI::data{
//     "TestWindow",
//     cv::WINDOW_GUI_NORMAL,
//     26,
//     lucidy::WindowSize{600,600},
//     lucidy::Coordinate{1000,1000}
//   },
//   lucidy::USB_CAMERA_1
// };

// int main( ){

//   std::fstream myFile;
//   myFile.open("/home/arsalan/ti-software/Build-environment/modules/OBJECT_RECOGNITION/src/test_results.txt", std::fstream::out | std::fstream::app);

//   lucidy::SampleImage apple("/home/arsalan/ti-software/Build-environment/modules/OBJECT_RECOGNITION/src/external/binaries/apple3.jpg", imgSet);
//   lucidy::RootImage frame;
//   lucidy::ObjectFinder finder(tmp);
//   lucidy::VideoController vcr(recordSet);

//   vcr.recordAndApply( 
//     [&apple, &finder, &myFile](lucidy::RootImage & image)->cv::Mat{
      
//       float matchValue = finder.calcMatch(image, apple);
//       lucidy::MatchList goodMatches = finder.getMatches();
//       myFile << "Match percentage: " << matchValue << "%%" <<"\r\n";

//        cv::Mat imgMatches;
//        cv::drawMatches( 
//           apple.get(), apple.features, image.get(), image.features,
//           goodMatches, imgMatches, cv::Scalar::all(-1), cv::Scalar::all(-1),
//           std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS 
//         );

//       return imgMatches;
//     },
//     [&apple]()->void{ 
//       lucidy::FeatureDetector detector(tmp.fdt); lucidy::FeatureDescriptor descriptor(detector, tmp.fdc);
//       detector.detectFeatures(apple);
//       descriptor.computeDescriptors(apple);  
//     }, 
//     [&myFile]()->void{ myFile.close(); }
//   );

//   return 0;
// }


