#include "image_viewer.hpp"

namespace lucidy {

ImageViewer::ImageViewer() {
}

ImageViewer::ImageViewer(settings::WIN::GUI::data &settings) {
    window_settings = settings;
    init();
}

void ImageViewer::show(Image &image) {
    cv::imshow(window_settings.name, image.get());
}

void ImageViewer::changeSettings(settings::WIN::GUI::data &settings) {
    window_settings = settings;
}

} // namespace lucidy