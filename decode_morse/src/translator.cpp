#pragma once

#include  <map>
#include <string>

#include "../include/translator.h"

using namespace std;

void translator::fill_alpha_to_morse(){
    alpha_to_morse["A"] = ".- ";
    alpha_to_morse["B"] = "-... ";
    alpha_to_morse["C"] = "-.-. ";
    alpha_to_morse["D"] = "-.. ";
    alpha_to_morse["E"] = ". ";
    alpha_to_morse["F"] = "..-. ";
    alpha_to_morse["G"] = "--. ";
    alpha_to_morse["H"] = ".... ";
    alpha_to_morse["I"] = ".. ";
    alpha_to_morse["J"] = ".--- ";
    alpha_to_morse["K"] = "-.- ";
    alpha_to_morse["L"] = ".-.. ";
    alpha_to_morse["M"] = "-- ";
    alpha_to_morse["N"] = "-. ";
    alpha_to_morse["O"] = "--- ";
    alpha_to_morse["P"] = ".--. ";
    alpha_to_morse["Q"] = "--.- ";
    alpha_to_morse["R"] = ".-. ";
    alpha_to_morse["S"] = "... ";
    alpha_to_morse["T"] = "- ";
    alpha_to_morse["U"] = "..- ";
    alpha_to_morse["V"] = "...- ";
    alpha_to_morse["W"] = ".-- ";
    alpha_to_morse["X"] = "-..- ";
    alpha_to_morse["Y"] = "-.-- ";
    alpha_to_morse["Z"] = "--.. ";
    alpha_to_morse["0"] = "----- ";
    alpha_to_morse["1"] = ".---- ";
    alpha_to_morse["2"] = "..--- ";
    alpha_to_morse["3"] = "...-- ";
    alpha_to_morse["4"] = "....- ";
    alpha_to_morse["5"] = "..... ";
    alpha_to_morse["6"] = "-.... ";
    alpha_to_morse["7"] = "--... ";
    alpha_to_morse["8"] = "---.. ";
    alpha_to_morse["9"] = "----. ";
    alpha_to_morse[" "] = "  ";
}

void translator::fill_morse_to_alpha(){
    morse_to_alpha[".- "] = "A";
    morse_to_alpha["-... "] = "B";
    morse_to_alpha["-.-. "] = "C";
    morse_to_alpha["-.. "] = "D";
    morse_to_alpha[". "] = "E";
    morse_to_alpha["..-. "] = "F";
    morse_to_alpha["--. "] = "G";
    morse_to_alpha[".... "] = "H";
    morse_to_alpha[".. "] = "I";
    morse_to_alpha[".--- "] = "J";
    morse_to_alpha["-.- "] = "K";
    morse_to_alpha[".-.. "] = "L";
    morse_to_alpha["-- "] = "M";
    morse_to_alpha["-. "] = "N";
    morse_to_alpha["--- "] = "O";
    morse_to_alpha[".--. "] = "P";
    morse_to_alpha["--.- "] = "Q";
    morse_to_alpha[".-. "] = "R";
    morse_to_alpha["... "] = "S";
    morse_to_alpha["- "] = "T";
    morse_to_alpha["..- "] = "U";
    morse_to_alpha["...- "] = "V";
    morse_to_alpha[".-- "] = "W";
    morse_to_alpha["-..- "] = "X";
    morse_to_alpha["-.-- "] = "Y";
    morse_to_alpha["--.. "] = "Z";
    morse_to_alpha["----- "] = "0";
    morse_to_alpha[".---- "] = "1";
    morse_to_alpha["..--- "] = "2";
    morse_to_alpha["...-- "] = "3";
    morse_to_alpha["....- "] = "4";
    morse_to_alpha["..... "] = "5";
    morse_to_alpha["-.... "] = "6";
    morse_to_alpha["--... "] = "7";
    morse_to_alpha["---.. "] = "8";
    morse_to_alpha["----. "] = "9";
    morse_to_alpha["  "] = " ";
}


string translator::translate_alpha_to_morse(string chain){
    fill_alpha_to_morse();
    int n = chain.length();
    string translation;
    for(int i = 0; i <n; i++){
        std::string letter (1,chain[i]);
        translation += alpha_to_morse[letter];
    };
    return translation;
}

string translator::translate_morse_to_alpha(string chain){
    fill_morse_to_alpha();
    string alpha;
    int n = chain.length();
    int i = 0;
    while (i<n){
        string lettre_morse;
        string m(1,chain[i]);
        if (m != " "){
            while (m != " ")
            {
                lettre_morse = lettre_morse + m;
                i = i + 1;
                m = chain[i];
            }
            lettre_morse = lettre_morse + m;
            i = i+1;
        }
        else {        
            alpha = alpha + " ";
            i = i + 1;
        }
        alpha = alpha + morse_to_alpha[lettre_morse];
    }
    return alpha;
}

