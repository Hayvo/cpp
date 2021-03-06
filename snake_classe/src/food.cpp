#pragma once
#include "stdlib.h"

#include "../include/snake.h"
#include "../include/background.h"
#include "../include/food.h"

int* food::getFood(){
    return food;
}

void food::createFood(background &bg){
    if( food[0] == 0){
        food[0] = rand()%(bg.getNx()-2) + 1;
        food[1] = rand()%(bg.getNy()-2) + 1;
    }
}

void food::displayFood(background &bg){
    bg.getBg()[food[1]*bg.getNx()+food[0]] = 2;
}

bool food::eatFood(snake &snake){
    if( (food[0]== snake.getX()[0]) && (food[1] == snake.getY()[0]) ){
        food[0] = 0;
        food[1] = 0;
        return true;
    }
    return false;
}