#ifndef OPEN_CV_HPP
#define OPEN_CV_HPP

#include <array>
#include <vector>
#include <memory>


namespace cv{
    const int IMREAD_UNCHANGED = 1;	
    const int IMREAD_GRAYSCALE = 2;	
    const int IMREAD_COLOR = 3; 	

    struct Mat{std::array<char, 100> data = {'0'};};
    typedef int flag;
    typedef float KeyPoint;

    template <typename T>
    using Ptr = std::shared_ptr<T>;

    struct Match{float distance; int imgldx; int queryldx; int trainldx;};

    class DescriptorMatcher{public: DescriptorMatcher(){}; void match(Mat a, Mat b, std::vector<Match> c){} };

    namespace xfeatures2d{
        class SURF{ public: void create(){}; 
            void setMinHessian(double a){}; void setNOctaves(int a){}; void setNOctavesLayers(int a){}; 
            void detect(Mat a, std::vector<KeyPoint> b){}; void compute(Mat a, std::vector<KeyPoint> b, Mat c){}; 
            void setExtended(bool a){}; void setUpright(bool a){};
        };


    }







}

#endif //OPEN_CV_HPP


