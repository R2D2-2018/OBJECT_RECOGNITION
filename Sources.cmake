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

include_directories (src/)

set (sources
	"src/sample_image.cpp"
)
