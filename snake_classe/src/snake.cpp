#pragma once
#include "../include/snake.h"
#include "../include/background.h"


int* snake::getX(){
    return X;
};

int* snake::getY(){
    return Y;
};

int* snake::getDxdy(){
    return dxdy;
};

int snake::getSnl(){
    return snl;
};

void snake::add_snake(background &bg){
    bg.getBg()[Y[0]*bg.getNx() + X[0]] = 4;
    for(int i = 1; i < snl; i++){
        bg.getBg()[Y[i]*bg.getNx() + X[i]] = 3;
    } 
};


void snake::remove_snake(background &bg){
    for(int i = 0; i < snl; i++){
        bg.getBg()[Y[i]*bg.getNx() + X[i]] = 0;
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
};

bool snake::verifyBorder(background &bg){
    return X[0] < bg.getNx()-1 && X[0] > 0 && Y[0] < bg.getNy()-1 && Y[0] > 0;
};

void snake::setupSnake(background &bg){
    snl = 5;
    for(int i = 0; i<snl;i++){
        X[i] = bg.getNx()/2;
        Y[i] = bg.getNy()/2 + i;
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