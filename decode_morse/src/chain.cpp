#include "../include/chain.h"
#include <string>

chain::chain(std::string chain1, std::string type1){
    text_chain = chain1;
    type_chain = type1;
};

std::string chain::getChain(){
    return text_chain;
};

std::string chain::getType(){
    return type_chain;
};

