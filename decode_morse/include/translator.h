#pragma once

#include <iostream>
#include <map>
#include <string>


class translator{
    private:
        std::map<std::string , std::string> alpha_to_morse;
        std::map<std::string , std::string> morse_to_alpha;
    public:
        void fill_alpha_to_morse();
        void fill_morse_to_alpha();
        std::string translate_morse_to_alpha(std::string chain);
        std::string translate_alpha_to_morse(std::string chain);
};

