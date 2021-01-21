#pragma once

#include <vector>
#include <string>
#include "../include/header.h"
using namespace std;


class wave
{
public:
    wave(){};
    ~wave(){};

private:
    int dot_duration = 50;
    int dash_duration = 3*dot_duration;
    int intra_letter_duration = 2*dot_duration;
    int inter_letter_duration = 3*intra_letter_duration;
    int inter_word_duration = 7*intra_letter_duration;

public:
    void EncodeMorseCodesAsSound(const string &filename, const string &morse);
    string DecodeDataToMorse(vector<float> wave_profile);
    vector<float> ReadWavFileData(const string &filename);
    void makeWavFile(vector<int> binary, const string &filename, headerWav header);
    void fwriteDot(vector<int> &binary, headerWav header);
    void fwriteDash(vector<int> &binary, headerWav header);
    void fwriteSpace(vector<int> &binary, headerWav header);
    void fwriteWSpace(vector<int> &binary, headerWav header);
};