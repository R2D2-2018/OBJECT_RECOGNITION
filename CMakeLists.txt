cmake_minimum_required(VERSION 2.6)

project(object_recognition)
set(exe_name "object_recognition")

enable_testing()
include(../../flags.cmake)

add_library(OpenCV SHARED IMPORTED)
set_property(TARGET OpenCV PROPERTY IMPORTED_LOCATION "/usr/local/lib")
find_package( OpenCV REQUIRED )

include_directories("/home/dylrak/Documents/R2D2/libraries/opencv/include/opencv2/")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(sources
    src/image/root_image.cpp
    src/image/sample_image.cpp
    src/object_finding/feature_detector.cpp
    src/object_finding/feature_descriptor.cpp
    src/object_finding/feature_comparator.cpp
    src/object_finding/object_finder.cpp
    src/window/interface/gui.cpp
    src/window/interface/cli.cpp
    src/window/image_viewer.cpp
    src/main.cpp)
set (unit_test_main test/test_main.cpp)

add_executable(${exe_name} ${sources})
target_link_libraries( object_recognition ${OpenCV_LIBS} )
