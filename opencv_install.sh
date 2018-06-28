# Configuration
echo ===============================================================================
echo ================== Install OpenCV in the modules Root folder ==================
echo ===============================================================================
echo Made by Joost van Lingen, based on research by Dylan Rakiman
echo ===============================================================================
echo Enter your GCC version, often 5, 6 or 7:
read GCC_VERSION
echo Enter your G++ version, often 5, 6 or 7:
read GPP_VERSION
echo Enter your number of threads:
read NO_OF_THREADS

# Install dependencies
echo ===============================================================================
echo =========================== Installing Dependencies ===========================
echo ===============================================================================
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get -y install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get -y install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

sudo pip2 install lizard -q # Cyclomatic Complexity Check Tool
sudo unlink /usr/bin/gcc && sudo ln -s /usr/bin/gcc-$GCC_VERSION /usr/bin/gcc # Change symlinks of gcc to gcc-5
sudo unlink /usr/bin/g++ && sudo ln -s /usr/bin/g++-$GPP_VERSION /usr/bin/g++ # Change symlinks of g++ to g++-5

cd ..

# Download opencv from Github.
echo ===============================================================================
echo ================== Downloading the latest version of opencv ===================
echo ===============================================================================
git clone https://github.com/opencv/opencv.git
  
# Download EXTRA MODULES from Github.
echo ===============================================================================
echo ============== Downloading the latest version of opencv_contrib ===============
echo ===============================================================================
git clone https://github.com/opencv/opencv_contrib.git

# Copy xfeatures2d folder into OpenCV modules
cp -R opencv_contrib/modules/xfeatures2d opencv/modules/

# Create a new 'build' folder.
echo ===============================================================================
echo =============================== Building opencv ===============================
echo ===============================================================================
cd opencv
mkdir build
cd build
  
# Set build instructions for Ubuntu distro.
cmake -D OPENCV_EXTRA_MODULES_PATH= ../../opencv_contrib/modules -D WITH_TBB=ON -D INSTALL_C_EXAMPLES=ON -D WITH_EIGEN=OFF -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON -D BUILD_opencv_dnn=OFF -D BUILD_opencv_java=OFF ..

# Run 'make' with four threads
echo ===============================================================================
echo ============================== Compiling opencv ===============================
echo ===============================================================================
make -j4
  
# Install to OS.
echo ===============================================================================
echo ============================== Installing opencv ==============================
echo ===============================================================================
sudo make install
  
# Add configuration to OpenCV to tell it where the library files are located on the file system (/usr/local/lib)
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'

sudo ldconfig
echo ===============================================================================
echo =============================== opencv Installed ==============================
echo ===============================================================================
