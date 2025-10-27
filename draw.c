#include <stdio.h>

#include <stdlib.h>

#include "draw.h"
#include "level.h"
#include "player.h"

#define CHARACTER_EMPTY 255
#define CHARACTER_PLAYER 'P'

char level_to_draw[MAX_HEIGHT][MAX_WIDTH] = {{0}};

void setLevelToDraw() {

    setTiles();
    //setItems();
    setPlayer();
    setDarkness();

}

void setTiles() {

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            level_to_draw[i][j] = level_active.tiles[i][j];
        }
    }
}

void setDarkness() {

    

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            if (level_active.darkness[i][j] == 0) 
                level_to_draw[i][j] = CHARACTER_EMPTY;
        }
    }
}

void setPlayer() {

    level_to_draw[player.pos_y][player.pos_x] = CHARACTER_PLAYER;
}

void drawLevel() {

    //system("cls");

    setLevelToDraw();

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            printf("%c", level_to_draw[i][j]);
        }
    
        printf("\n");
    }
    
}