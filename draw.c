#include <stdio.h>

#include <stdlib.h>

#include "draw.h"
#include "level.h"
#include "player.h"
#include "items.h"

char level_to_draw[MAX_HEIGHT][MAX_WIDTH] = {{0}};

void setLevelToDraw() {

    setTiles();
    setItems();
    setPlayer();
    setLight();

}

void setTiles() {

    for(int i = 0 ; i < level_active.height ; i++) {
        for(int j = 0 ; j < level_active.width ; j++) {
            level_to_draw[i][j] = level_active.tiles[i][j];

        }
    }
}

void setLight() {
    
    lightPorcessLayers();
    
    for(int i = 0 ; i < level_active.height ; i++) {
        for(int j = 0 ; j < level_active.width ; j++) {

            if (level_active.light[i][j] == CHAR_UNLIT) 
                level_to_draw[i][j] = level_active.light[i][j];
        }
    }
}

void setItems() {

    for(int i = 0 ; i < level_active.height ; i++) {
        for(int j = 0 ; j < level_active.width ; j++) {
            if (level_active.objects[i][j] != CHAR_EMPTY)
                level_to_draw[i][j] = level_active.objects[i][j];

        }
    }    
}

void setPlayer() {

    level_to_draw[player.pos_y][player.pos_x] = CHAR_PLAYER;
}

void drawLevel() {

    //system("cls");

    setLevelToDraw();

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            printEmoji(level_to_draw[i][j]);
        }
    
        printf("\n");
    }
    
}
void printEmoji(char character) {

    switch (character) {

        case CHAR_WALL:
        printf(DRAW_CHARACTER_WALL);
        break;

        case CHAR_GROUND:
        printf(DRAW_CHARACTER_GROUND);
        break;

        /* case CHAR_PIT:
        printf(DRAW_CHARACTER_PIT);
        break; */

        /* case CHAR_WALL_TORCH:
        printf(DRAW_CHARACTER_WALL_TORCH);
        break; */

        case CHAR_PLAYER:
        printf(DRAW_CHARACTER_PLAYER);
        break;

        case CHAR_PLANK:
        printf(DRAW_CHARACTER_PLANK);
        break;

        case CHAR_RELIC:
        printf(DRAW_CHARACTER_RELIC);
        break;

        case CHAR_TORCH:
        printf(DRAW_CHARACTER_TORCH);
        break;

        case CHAR_UNLIT:
        printf(DRAW_CHARACTER_DARK);
        break;
    }
}



/*int drawStartMenu(char opt) {

    printf("1. - Start\n2. - Options\n3. - Exit\n");

    switch(opt) {

        case '1':
            return 1;
            break;

        case '2':
            return 2;
            break;

        case '3':
            return 3;
            break;
    }

}*/