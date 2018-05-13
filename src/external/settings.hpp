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

