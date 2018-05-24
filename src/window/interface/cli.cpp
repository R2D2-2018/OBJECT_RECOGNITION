#include "cli.hpp"

namespace lucidy{

    /// right now no library is used for formatted text, will come in an future update
    void Cli::init(){}
    void Cli::open(){}
    void Cli::close(){}

    void Cli::show(const char* text){
        std::cout << text;
    }



}