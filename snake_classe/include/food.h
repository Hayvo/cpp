#pragma once 
#include "../include/snake.h"
#include "../include/background.h"


class food{
    private:
        int food[2];
    public:
        int* getFood();
        void createFood(background &bg);
        void displayFood(background &bg);
        bool eatFood(snake &snake);
};


