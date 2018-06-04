# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/image/sample_image.cpp
    src/image/root_image.cpp
    src/object_finding/feature_detector.cpp
    src/object_finding/feature_descriptor.cpp
    src/object_finding/feature_comparator.cpp
    src/object_finding/object_finder.cpp
    src/window/interface/gui.cpp
    src/window/interface/cli.cpp
    src/window/image_viewer.cpp
    src/window/video_controller.cpp
    src/main.cpp
)

# src/test_log/live_video_feed_object_recognition.cpp


