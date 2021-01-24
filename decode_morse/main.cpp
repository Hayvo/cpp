#include "./include/translator.h"
#include "./src/translator.cpp"

#include "./include/wave.h"
#include "./src/wave.cpp"

#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
    translator translator; 
    wave sound;


    if (argc >= 3)
    {
        string arg(argv[1]);
        string s(argv[2]);
        if (arg ==  "to_sound") 
        {
            sound.EncodeMorseCodesAsSound("morse.wav",translator.translate_alpha_to_morse(s));
        }
        else{
            if (arg ==  "to_text") 
            {
                string alpha = translator.translate_morse_to_alpha(sound.DecodeDataToMorse(sound.ReadWavFileData(s)));
                cout << "Traduction : " << alpha << endl;
            }
            else
            {       
                cout << "Arguments invalides" << endl;    
            }
            
        }
    }
    else
    {
        if (argc == 2)
        {
            string arg(argv[1]);
            if (arg == "help" or arg == "h")
            {
                cout << "Aide au programme de traduction morse-français par Pierre DENIG" << endl;
                cout << endl; cout << endl;
                cout << "Pour créer un fichier audio à pertir d'un texte : " << endl; 
                cout << "Passez la mention 'to_sound' en premier argument puis votre texte en majuscule en second argument" << endl;
                cout << "Expl : $./decode to_sound 'HELLO WORLD' " << endl;
                cout << endl; cout << endl;
                cout << "Pour décoder un fichier audio : " << endl; 
                cout << "Passez la mention 'to_text' en premier argument puis le chemin du fichier audio en second argument" << endl;
                cout << "Expl : $./decode to_text 'MY PATH'" << endl;
            }
        }
        else
        {
            cout << "Error. Please enter $./decode help or $./decode h for the help." << endl;
        }
    }
  
    return 0;
}


