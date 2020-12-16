
#include "./include/translator.h"

#include "./src/translator.cpp"

int main(int argc, char* argv[]){
    translator translator; 
    if (argc > 1){
        std::string s(argv[1]);
        std::cout << "Morse code : " << translator.translate_alpha_to_morse(s) << std::endl;
    }
    else{
        std::cout << "Please enter a valid text" << std::endl;
    }
    return 0;
}