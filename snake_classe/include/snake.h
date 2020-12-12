#pragma once
#include "/home/hayvo/snake_classe/include/config.h"
#include "/home/hayvo/snake_classe/include/background.h"

class snake{
    public:
    
        int X[SNAKE_LEN];
        int Y[SNAKE_LEN];

        int dxdy[2] = {0,-1};
        
        int snl;

        void add_snake(background &bg,int nx, int ny);

        void remove_snake(background &bg,int nx, int ny);

        void snake_movement(char key);

        bool verifyBorder(int nx, int ny);

        bool verifyOverlap();

        void setupSnake(int nx, int ny);

        void update_snake_coordinates();

        void bigger_snake();
};

