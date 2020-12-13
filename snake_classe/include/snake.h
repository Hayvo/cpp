#pragma once
#include "../include/config.h"
#include "../include/background.h"

class snake{
    private:
    
        int X[SNAKE_LEN];
        int Y[SNAKE_LEN];
        int dxdy[2] = {0,-1};
        int snl;

    public:

        int* getX();
        int* getY();
        int* getDxdy();
        int getSnl();
        void add_snake(background &bg);
        void remove_snake(background &bg);
        void snake_movement(char key);
        bool verifyBorder(background &bg);
        bool verifyOverlap();
        void setupSnake(background &bg);
        void update_snake_coordinates();
        void bigger_snake();
};

