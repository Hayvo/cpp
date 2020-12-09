#pragma once 
#include "/home/hayvo/snake_classe/include/snake.h"
#include "/home/hayvo/snake_classe/include/background.h"


class food{
    public:
        int food[2];
        void createFood(background bg, const int& nx, const int& ny);
        bool eatFood(snake snake);
};

