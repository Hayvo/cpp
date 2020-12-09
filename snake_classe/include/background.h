#pragma once


class background{
    public:
        int *bg;
        void backgroundClear();
        void backgroundSetup(const int nx,const int ny);
        void printFrame(const int& nx, const int& ny, int snl);
};