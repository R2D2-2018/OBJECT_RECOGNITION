/**
 * @brief global CLI window interface
 * @details This file contains the interface that decides what a CLI window or text based window should contain
 * @file cli.hpp
 * @author Arsalan Anwari
 * @date 2018-05-19
 */

#ifndef CLI_HPP
#define CLI_HPP

#include "window.hpp"
#include <iostream>

namespace lucidy{

/**
 * @brief Cli interface. inherits Window interface
 * 
 */
class Cli : public Window{
public:

    /**
     * @brief This function should be used to initialize the text interface library
     */
    void init() override;

    /**
     * @brief This function should be used to activate or start the text interface session
     * 
     */
    void open() override;

    /**
     * @brief This function should be used to end the text interface session
     * 
     */
    void close() override;

    /**
     * @brief This function should be used to show some formatted text on the text interface session
     * 
     * @param text : char* const
     */
    void show(const char* text);

};


}


#endif //CLI_HPP

