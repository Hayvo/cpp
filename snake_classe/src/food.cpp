#pragma once
#include "stdlib.h"

#include "../include/snake.h"
#include "../include/background.h"
#include "../include/food.h"

void food::createFood(background &bg, const int nx, const int ny){
    if( food[0] == 0){
        food[0] = rand()%(nx-2) + 2;
        food[1] = rand()%(ny-2) + 2;
        bg.bg[food[1]*nx+food[0]] = 2;
    }
}

bool food::eatFood(snake &snake){
    if( (food[0]== snake.X[0]) && (food[1] == snake.Y[0]) ){
        food[0] = 0;
        food[1] = 0;
        return true;
    }
    return false;
}