#include "./include/game.h"

#include "./src/game.cpp"
#include "./src/background.cpp"
#include "./src/food.cpp"
#include "./src/internals.cpp"
#include "./src/snake.cpp"

int main(){
    game game;
    const int lap = 100;
    game.setupGame(lap);
    return 0;
}
