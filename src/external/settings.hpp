/**
 * @brief Settings structure for class constructors
 * @details This file contains nested namescpace structs which contain some variables that are 
 * used in constructor of classes. This ensures the user can create dummy settings object in another file
 * to pass by reference to a using class. This way the user will not get large object with many variables. 
 * @file settings.hpp
 * @author Arsalan Anwari
 * @date 2018-05-15
 */

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "libraries/open_cv.hpp"

namespace lucidy{
    namespace settings{

    namespace FDT{
        struct data{
            double hessianThreshold;
            int octavesNr = 0;
            int octaveLayers = 0;
        };

    }

    namespace FDC{
        struct data{
            bool extendDescriptor = true;
            bool calcUpright = false;
        };
    }

    namespace OBF{
        struct data{
            FDT::data fdt;
            FDC::data fdc;
        };
        
    }

    namespace IMG{
        struct data{
            cv::flag flag;
        };
    }



}

}


#endif //SETTINGS_HPP

