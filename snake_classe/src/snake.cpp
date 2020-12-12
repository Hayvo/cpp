#pragma once
#include "/home/hayvo/snake_classe/include/snake.h"
#include "/home/hayvo/snake_classe/include/background.h"

void snake::add_snake(background &bg,int nx, int ny){
        for(int i = 0; i < snl; i++){
            bg.bg[Y[i]*nx + X[i]] = 1;
        } 
    };


    void snake::remove_snake(background &bg,int nx, int ny){
        for(int i = 0; i < snl; i++){
            bg.bg[Y[i]*nx + X[i]] = 0;
        }
    };

    void snake::snake_movement(char key){
        if(key == 'z' && dxdy[1] != 1){
            dxdy[0] = 0;
            dxdy[1] = -1;
        }
        if(key == 's' && dxdy[1] != -1){
            dxdy[0] = 0;
            dxdy[1] = 1;
        }
        if(key == 'q' && dxdy[0] != 1){
            dxdy[0] = -1;
            dxdy[1] = 0;
        }
        if(key == 'd' && dxdy[0] != -1){
            dxdy[0] = 1;
            dxdy[1] = 0;
        }
    };

    bool snake::verifyOverlap(){
        for(int i = 1; i < snl ; i++){
            if(X[0] == X[i] && Y[0] == Y[i]){
                return true;
            }
        }
        return false;
    }

    bool snake::verifyBorder(int nx, int ny){
        return X[0] < nx-1 && X[0] > 0 && Y[0] < ny-1 && Y[0] > 0;
    };

    void snake::setupSnake(int nx, int ny){
        snl = 5;
        for(int i = 0; i<snl;i++){
            X[i] = nx/2;
            Y[i] = ny/2 + i;
        }
    };

    void snake::update_snake_coordinates(){
        for(int i = 0; i < snl; i++){
            X[snl - i] = X[snl - i -1];
            Y[snl - i]  = Y[snl - i - 1];
        }
        X[0] += dxdy[0];
        Y[0] += dxdy[1];
    };

    void snake::bigger_snake(){ /* Aggrandire le snake */
        snl++;
        for(int i = 0; i< snl;i++){
            X[snl - i] = X[snl-i-1];
            Y[snl - i] = Y[snl-i-1];
        }
        X[0] += dxdy[0];
        Y[0] += dxdy[1];
    };