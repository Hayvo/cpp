#include "./include/translator.h"
#include "./src/translator.cpp"

#include "./include/wave.h"
#include "./src/wave.cpp"


#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[]){
    translator translator; 
    wave sound;
    if (argc > 1){
        string s(argv[1]);
        if (argv[2] == "sound") {
        sound.EncodeMorseCodesAsSound("./morse.wav",translator.translate_alpha_to_morse(s));
        }
        else{
            if (argv[2] == "text") {
                string alpha = translator.translate_morse_to_alpha(sound.DecodeDataToMorse(sound.ReadWavFileData(s)));
                cout << "Traduction : " << alpha << endl;
            }
        }
    }
    else{
        cout << "Please enter a valid text" << endl;
    } 
    return 0;
}


