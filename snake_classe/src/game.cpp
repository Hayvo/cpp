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



void game::setupGame(const int lap){
    srand(time(NULL));
    
    background background;
    background.backgroundSetup(); 
    int nx = background.nx;
    int ny = background.ny;
    snake snake;
    snake.setupSnake(nx,ny);
    background.printFrame(snake.snl);
    
    
    

    char key;
    food food;
    food.createFood(background, nx, ny );
    while( true ){
        internal::frameSleep(lap);
        if( internal::keyEvent() ){ /* Récupération direction */
            std::cin >> key; 
            snake.snake_movement(key);
        }
        background.backgroundClear(); /* MAJ plateau de jeu */
        snake.add_snake(background, nx, ny );
        background.printFrame(snake.snl);
        snake.remove_snake(background,nx, ny); 

        bool out1 = snake.verifyBorder(nx, ny);
        bool out2 = snake.verifyOverlap(); /* Check position */
        if( out1 == false){
            background.backgroundClear();
            std::cerr << "Game over : out of the plateform " <<std::endl;
            exit(1);
        }
        if( out2 == true){
            background.backgroundClear();
            std::cerr << "Game over : overlapping" << std::endl;
            exit(1);
        }
        bool eat = food.eatFood(snake); /* Check food */
        if(eat){
            food.createFood(background, nx, ny);
            snake.bigger_snake();
        }
        else{
        snake.update_snake_coordinates();
        }
    } 
};




