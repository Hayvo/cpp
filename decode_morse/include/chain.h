#pragma once

#include <string>

class chain{
    private:
        std::string type_chain;
        std::string text_chain;
    public:
        chain(std::string chain1,std::string type_chain1);
        std::string getChain();
        std::string getType();
};
