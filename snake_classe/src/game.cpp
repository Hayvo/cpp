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


int game::getLap(){
    return lap;
}

void game::setupGame(){
    srand(time(NULL));
    
    background background;
    background.backgroundSetup(); 
    
    snake snake;
    snake.setupSnake(background);
    background.printFrame(snake.getSnl());
    
    
    

    char key;
    food food;
    food.createFood(background);
    while( true ){
        food.displayFood(background);
        internal::frameSleep(lap);
        if( internal::keyEvent() ){ /* Récupération direction */
            std::cin >> key; 
            snake.snake_movement(key);
        }
        background.backgroundClear(); /* MAJ plateau de jeu */
        snake.add_snake(background);
        background.printFrame(snake.getSnl());
        snake.remove_snake(background); 

        bool out1 = snake.verifyBorder(background);
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
            food.createFood(background);
            snake.bigger_snake();
        }
        else{
        snake.update_snake_coordinates();
        }
    } 
};




