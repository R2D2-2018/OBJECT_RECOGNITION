# Libraries:

link_libraries (gcc)

add_library(OpenCV SHARED IMPORTED)
set_property(TARGET OpenCV PROPERTY IMPORTED_LOCATION "/usr/local/lib")
find_package( OpenCV REQUIRED )

set (opencv ${build_environment}/libraries/opencv)
include_directories (${opencv}/include/opencv2/)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    "src/image/root_image.cpp"
    "src/image/sample_image.cpp"
    "src/object_finding/feature_detector.cpp"
    "src/object_finding/feature_descriptor.cpp"
    "src/object_finding/feature_comparator.cpp"
    "src/object_finding/object_finder.cpp"
    "src/window/interface/gui.cpp"
    "src/window/interface/cli.cpp"
    "src/window/image_viewer.cpp"
)
