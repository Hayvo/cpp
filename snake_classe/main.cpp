#include "./include/game.h"

#include "./src/game.cpp"
#include "./src/background.cpp"
#include "./src/food.cpp"
#include "./src/internals.cpp"
#include "./src/snake.cpp"

int main(){
    srand(time(NULL));
    game game;
    game.setupGame();
    return 0;
}
