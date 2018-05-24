#include <iostream>
#include "image/sample_image.hpp"
#include "window/image_viewer.hpp"

int main(int argc, char **argv)
  {
    lucidy::SampleImage sample_img;
    if (argc != 2 || !sample_img.set(argv[1]))
    {
      bool set_successful = false;
      std::cout << "Sample image could not be found or is not specified." << std::endl;
      while (!set_successful)
      {
        std::cout << "Please enter a valid path to the sample image:" << std::endl;
        std::string path;
        std::cin >> path;
        set_successful = sample_img.set(path.c_str());
      }
    }
    lucidy::ImageViewer window;
    window.show(sample_img);
    int k = cv::waitKey(0);
    if (k == 27) //escape
    {
      cv::destroyAllWindows();
    }
    return 0;
  }

