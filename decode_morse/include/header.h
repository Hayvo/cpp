#pragma once

#include <stdlib.h>

#define FREQUENCE 11025
#define BITPERSAMPLE 16

class headerWav 
{
    public:
        u_int8_t FileTypeBlocID[4] = {'R','I','F','F'} ;
        u_int32_t FileSize;
        u_int8_t FileFormatID[4] = {'W','A','V','E'};
        u_int8_t FormatBlocID[4] = {'f','m','t',' '};
        u_int32_t BlocSize = 16;
        u_int16_t AudioFormat = 1;
        u_int16_t NbrCanaux = 1;
        u_int32_t Frequence = FREQUENCE;
        u_int32_t BytePerSec = FREQUENCE*BITPERSAMPLE/8;
        u_int16_t BytePerBloc = BITPERSAMPLE/8 ;
        u_int16_t BitsPerSample = BITPERSAMPLE;
};

class rawHeaderWav 
{
    public:
    u_int8_t FileTypeBlocID[4];
    u_int32_t FileSize;
    u_int8_t FileFormatID[4];
    u_int8_t FormatBlocID[4];
    u_int32_t BlocSize;
    u_int16_t AudioFormat;
    u_int16_t NbrCanaux;
    u_int32_t Frequence;
    u_int32_t BytePerSec;
    u_int16_t BytePerBloc;
    u_int16_t BitsPerSample;
};