#include <iostream>
#include "sys/ioctl.h"

#include "stdlib.h"

#include "../include/config.h"
#include "../include/internals.h"
#include "../include/background.h"
#include "../include/food.h"
#include "../include/snake.h"
#include "../include/game.h"
#include "../include/food.h"



void game::setupGame(const int nx, const int ny, const int lap){
    srand(time(NULL));
    
    background background;
    background.backgroundSetup(nx,ny);
    
    snake snake;
    snake.setupSnake(nx,ny);
    
    char key;
    food food;

    food.createFood(background, nx, ny );
    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){
            std::cin >> key; 
            snake.snake_movement(key);
        }
        background.backgroundClear();
        snake.add_snake(background, nx, ny );
        background.printFrame(nx, ny, snake.snl);
        snake.remove_snake(background,nx, ny);
        bool out =  snake.verifyBorder(nx, ny);
        if( out == false){
            background.backgroundClear();
            std::cerr << "Game over" << std::endl;
            exit(1);
        }
        bool eat = food.eatFood(snake);
        if(eat){
            food.createFood(background, nx, ny);
            snake.bigger_snake();
        }
        else{
        snake.update_snake_coordinates();
        }
    }
};




