cmake_minimum_required(VERSION 2.6)

project(object_recognition)
set(exe_name "object_recognition")

enable_testing()
include(../../flags.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(sources
    src/image/root_image.cpp
    src/image/sample_image.cpp
    src/object_finding/feature_detector.cpp
    src/object_finding/feature_descriptor.cpp
    src/object_finding/feature_comparator.cpp
    src/object_finding/object_finder.cpp
    src/main.cpp)

add_executable(${exe_name} ${sources})
