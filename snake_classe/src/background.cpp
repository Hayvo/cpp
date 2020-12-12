#include "stdlib.h"
#include <iostream>
#include "../include/background.h"


const char* cmd_clear="clear";


void background::backgroundClear(){ /* Effacer tout l'écran */
    int out = system(cmd_clear);
    if( out != 0){
        std::cerr << "clear command failed" << std::endl;
        exit(1);
    }
}

void background::printFrame(int snl){ /* Affichage jeu */
    for( int j=0; j<ny; j++){
        for( int i=0; i<nx; i++){
            if( bg[i+j*nx] == 1 ){
                std::cout << "#";
            }
            else if( bg[i+j*nx] == 2 ){
                std::cout << "@" ; 
            }    
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Score = " << 10*(snl - 5) << std::endl;
    
}

void background::backgroundSetup(){ /* Initialisation plateau de jeu */
    for( int i=0; i<nx*ny; i++){ /* Pour ne rien avoir partout */
        bg[i] = -1;
    }
    for(int i = 0; i < nx ;i++){ /* Bords hauts et bas */
        bg[i] = 1;
        bg[(ny-1)*nx + 1 + i] = 1;
    }
    for(int i = 1; i < ny;i++){ /* Bords droits et gauches */
        bg[i*nx] = 1;
        bg[(i+1)*nx-1] = 1;
    }
}