#include "./include/game.h"

#include "./src/game.cpp"
#include "./src/background.cpp"
#include "./src/food.cpp"
#include "./src/internals.cpp"
#include "./src/snake.cpp"

int main(){
    game game;
    const int nx = 50;
    const int ny = 25;
    const int lap = 100;
    game.setupGame(nx,ny,lap);
    return 0;
}
