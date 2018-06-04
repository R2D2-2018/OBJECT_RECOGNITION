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

#include "types.hpp"

namespace lucidy{

    namespace settings{

    namespace FDT{
        
        /**
         * @brief Used in Feature detector
         * 
         */
        struct data{
            double hessianThreshold;
            int octavesNr = 4;
            int octaveLayers = 3;
        };

    }

    namespace FDC{
        /**
         * @brief Used in Feature descriptor
         * 
         */
        struct data{
            bool extendDescriptor = true;
            bool calcUpright = false;
        };
    }

    namespace OBF{
        /**
         * @brief Used in Object finder or comparator
         * @details uses settings of feature detecotr and descriptor
         */
        struct data{
            FDT::data fdt;
            FDC::data fdc;
            float matchThreshold;
        };
        
    }

    namespace IMG{
        /**
         * @brief Used as image settings (root/sample)
         * 
         */
        struct data{
            Coordinate smoothMask;
            int maxHue;
            int maxSaturation;
            bool applyThreshold;
            int flag = 1;
        };
    }

    namespace WIN{
        namespace GUI{
            /**
             * @brief Used in GUI interface or classes that implemet it
             * 
             */
            struct data{
                const char* name;
                int flag;
                int refreshRate = (1000/refreshRate);
                WindowSize windowSize;
                Coordinate windowPosition;
                char exitKey = 'q';
            };

            namespace VIW{
                /**
                 * @brief Used in video controller which implements gui settings
                 * 
                 */
                struct data{
                    GUI::data guiSet;
                    Cameras camNr;
                };

            }

        }

       

    }



}

}


#endif //SETTINGS_HPP

