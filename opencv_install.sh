# Go to libraries folder
cd ../../libraries
# Extract OpenCV and OpenCV_contrib
echo "===Cloning OpenCV Git repositories==="
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
# Copy xfeatures2d folder into OpenCV modules
echo "===Copying xfeatures2d into OpenCV==="
cp -R opencv_contrib/modules/xfeatures2d opencv/modules/
# Create a new 'build' folder.
cd opencv
mkdir build
cd build
# Set build instructions for Ubuntu distro.
echo "===Building OpenCV==="
cmake -D OPENCV_EXTRA_MODULES_PATH= ../../opencv_contrib/modules -D WITH_TBB=ON -D INSTALL_C_EXAMPLES=ON -D WITH_EIGEN=OFF -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON -D BUILD_opencv_dnn=OFF -D BUILD_opencv_java=OFF ..
# Run 'make' with four threads
make -j4
# Install to OS.
sudo make install
# Add configuration to OpenCV to tell it where the library files are located on the file system (/usr/local/lib)
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
echo "===OpenCV installed==="
