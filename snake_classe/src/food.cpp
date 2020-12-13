#pragma once
#include "stdlib.h"

#include "../include/snake.h"
#include "../include/background.h"
#include "../include/food.h"

void food::createFood(background &bg){
    if( food[0] == 0){
        food[0] = rand()%(bg.nx-2) + 1;
        food[1] = rand()%(bg.ny-2) + 1;
    }
}

void food::displayFood(background &bg){
    bg.bg[food[1]*bg.nx+food[0]] = 2;
}

bool food::eatFood(snake &snake){
    if( (food[0]== snake.X[0]) && (food[1] == snake.Y[0]) ){
        food[0] = 0;
        food[1] = 0;
        return true;
    }
    return false;
}