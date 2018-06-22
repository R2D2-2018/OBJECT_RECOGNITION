#include "image/sample_image.hpp"
#include "window/image_viewer.hpp"
#include <iostream>

int main(int argc, char **argv) {
    lucidy::SampleImage img;
    if (argc != 2 || !img.set(argv[1])) {
        std::cout << "File not found or specified." << std::endl;
        img.set();
    }
    lucidy::ImageViewer window;
    window.show(img);
    char k = cv::waitKey(0);
    if (k == 27) /// escape
    {
        cv::destroyAllWindows();
    }
    return 0;
}
