#include "../include/wave.h"
#include "../include/header.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h> 
#include <sstream>

using namespace std;

#define FREQUENCY 440 

void wave::fwriteDash(vector<int> &binary, headerWav header)
{
    for (int i = 0; i < (int) header.Frequence*dash_duration/1000; i++)
    {
        binary.push_back((int) 31000*sin(2*3.14*FREQUENCY*i/header.Frequence));
    }
    for (int i = 0; i < header.Frequence*intra_letter_duration/1000; i++)
    {
        binary.push_back(0);
    }
}

void wave::fwriteDot(vector<int> &binary, headerWav header)
{
    for (int i = 0; i < (int) header.Frequence*dot_duration/1000; i++)
    {
        binary.push_back((int) 31000*sin(2*3.14*FREQUENCY*i/header.Frequence));
    }
    for (int i = 0; i < header.Frequence*intra_letter_duration/1000; i++)
    {
        binary.push_back(0);
    }
}

void wave::fwriteSpace(vector<int> &binary, headerWav header)
{
    for (int i = 0; i < header.Frequence*(inter_letter_duration - intra_letter_duration)/1000; i++)
    {
        binary.push_back(0);
    }
}

void wave::fwriteWSpace(vector<int> &binary, headerWav header)
{
    for (int i = 0; i < header.Frequence*(inter_word_duration - inter_letter_duration - intra_letter_duration)/1000 ; i++)
    {
        binary.push_back(0);
    }
}

void wave::makeWavFile(vector<int> binary, const string &filename, headerWav header)
{
    ofstream wav;
    wav.open(filename, ofstream::out | ofstream::binary);
    if (wav.is_open())
    {
        int n = binary.size();
        header.FileSize = n + 36;
        wav.write(reinterpret_cast<char*>(&header),sizeof(header));
        wav << "data";
        for(int i = 0; i < n; i++)
        {
            uint16_t byte = binary[i];
            wav.write(reinterpret_cast<char*>(&byte),sizeof(byte));
        }
        wav.close();
    }
}


void wave::EncodeMorseCodesAsSound(const string &filename, const string &morse)
{
    vector<int> binary;
    headerWav header;
    int n = morse.length();
     
    for (int i = 0; i < n; i++) 
    {
        if (morse[i] == '.') 
        {
            fwriteDot(binary,header);
        }
        else 
        {
            if (morse[i] == '-')
            {
                fwriteDash(binary,header);
            }
            else 
            {
                if (morse[i] == ' ' && i < n-1 && morse[i+1] == ' ')
                {
                    fwriteWSpace(binary,header);
                }
                else 
                {
                    if (morse[i] == ' ')
                    {
                        fwriteSpace(binary,header);
                    }
                    else 
                    {
                    printf("Erreur dans l'encodage");
                    }
                }   
            } 
        }
    }
    makeWavFile(binary,filename,header);
}

vector<float> wave::ReadWavFileData(const string &filename)
{
    headerWav header;

    ifstream wav;

    char dataBalise[4];

    wav.open(filename, ifstream::in | ifstream::binary);

    vector<float> wave_profile;

    if (wav.is_open())
    {
        wav.read(reinterpret_cast<char *>(&header), sizeof(headerWav));

        char data[4];
        wav.read(reinterpret_cast<char *>(&data), sizeof(data));
        
        int ret;


        while(wav.read(reinterpret_cast<char *>(&ret), sizeof(ret)))
        {
            wave_profile.push_back(ret);
        }
    }
    else
    {
        cout << "Fichier introuvable" << endl;
    }
    wav.close();
    return wave_profile;
}

string wave::DecodeDataToMorse(vector<float> wave_profile)
{

    int n = wave_profile.size();



    vector<int> inter;


    int dot_duration = 0;
    int dash_duration = 0;
    int intra_letter_duration = 0;
    int inter_letter_duration = 0;
    int inter_word_duration = 0;

    int i = 1;
    while(i < n)
    {
        int size = 0;
        if(pow(wave_profile[i],2) + pow(wave_profile[i-1] ,2) != 0)
        {
            while(pow(wave_profile[i],2) + pow(wave_profile[i-1] ,2) != 0 and i < n)
            {
                size += 1;
                i++; 
            }
            inter.push_back(size);
            if (dot_duration > 0)
            {
                if(size > 2.75*dot_duration)
                {
                    dash_duration = size;
                }  
                else
                {
                    dot_duration = size;
                }            
            }
            else
            {
                dot_duration = size;
            }            
        }
        else
        {
            while(pow(wave_profile[i],2) + pow(wave_profile[i-1] ,2) == 0 and i <= n)
            {
                size += 1;
                i++; 
            }
            inter.push_back(size);
            if(intra_letter_duration == 0)
            {
                intra_letter_duration = size;
                inter_letter_duration = size;
                inter_word_duration = size;
            }
            else
            {
                if(size < 0.95*intra_letter_duration)
                {
                    intra_letter_duration = size;
                }
                else
                {
                    if (inter_letter_duration > intra_letter_duration)
                    {
                        if(size > inter_word_duration)
                        {
                            inter_word_duration = size;
                        }                
                    }
                    else
                    {
                        inter_letter_duration = size;
                    } 
                }
                
            }
            
        }   
    }

    int m = inter.size();
  
    string morse = "";

    for(int i = 0; i < m; i++)
    {
        if(abs(inter[i] - dot_duration) < 0.05*dot_duration )
        {
            morse +=".";
        }
        if(abs(inter[i] - dash_duration) < 0.05*dash_duration )
        {
            morse +="-";
        }
        if(abs(inter[i] - inter_letter_duration) < 0.05*inter_letter_duration )
        {
            morse +=" ";
        }
        if(abs(inter[i] - inter_word_duration) < 0.05*inter_word_duration )
        {
            morse +="  ";
        }
    }
    cout << "Code morse détécté : " << morse << endl;
    return morse;
}
