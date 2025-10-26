#include <stdio.h>
#include "draw.h"

void setLevelToDraw() {

    drawSetTiles();
    drawSetItems();
    drawSetPlayer();
    drawSetDarkness();

}

void drawSetTiles() {

    for(int i = 0 ; i < level_active.width ; i++) {

        for(int j = 0 ; j < level_active.height ; j++) {

            level_to_draw[i][j] = level_active.tiles[i][j];
        }
    }
}

void drawSet() {

    for(int i = 0 ; i < level_active.width ; i++) {

        for(int j = 0 ; j < level_active.height ; j++) {

            level_to_draw[i][j] = level_active.tiles[i][j];
        }
    }
}

