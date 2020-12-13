#pragma once
#include "../include/game.h"


class background{
    private:
        static const int nx = 50;
        static const int ny = 25;
        int bg[nx*ny];
    public:
        int getNx();
        int getNy();
        int* getBg();
        void backgroundClear();
        void backgroundSetup();
        void printFrame(int snl);
      
};