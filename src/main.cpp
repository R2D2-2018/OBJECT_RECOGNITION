#include "window/video_controller.hpp"

int main( ){
  
  lucidy::settings::WIN::GUI::VIW::data tmp{
    lucidy::settings::WIN::GUI::data{
      "TestWindow",
      cv::WINDOW_GUI_NORMAL,
      30,
      lucidy::WindowSize{600,600},
      lucidy::Coordinate{1000,1000}
    },
    lucidy::Cameras::USB_CAMERA_1
  };

  lucidy::VideoController vcr(tmp);

  vcr.startRecording(lucidy::SHOW_VIDEO_FEED);

  lucidy::RootImageList container = vcr.getRecordFeed();

  int size = static_cast<int>( container.size() );
  std::cout << "Container size: " << size;

  return 0;
}


