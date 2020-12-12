#pragma once
#include "../include/game.h"


class background{
    public:
        static const int nx = 50;
        static const int ny = 25;
        int bg[nx*ny];
        void backgroundClear();
        void backgroundSetup();
        void printFrame(int snl);
      
};