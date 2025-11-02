#include <stdio.h>

#include <stdlib.h>

#include "draw.h"
#include "level.h"
#include "player.h"
#include "items.h"

char level_to_draw[MAX_HEIGHT][MAX_WIDTH][EMOJI_SIZE] = {{0}};

void setLevelToDraw() {

    setTiles();
    setItems();
    setPlayer();
    setLight();

}

void setTiles() {

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            switch (level_active.tiles[i][j]) {
                case CHAR_WALL:
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_WALL);
                break;
                case CHAR_PIT:
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_PIT);
                break;
                case CHAR_GROUND:
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_GROUND);
                break;
            }
        }
    }
}

void setLight() {
    
    lightPorcessLayers();
    
    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            if (level_active.light[i][j] == CHAR_UNLIT) 
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_DARK);
        }
    }
}

void setItems() {

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            switch (level_active.objects[i][j]) {
                case CHAR_PLANK:
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_PLANK);
                break;
                case CHAR_TORCH:
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_TORCH);
                break;
                case CHAR_RELIC:
                sprintf(level_to_draw[i][j], DRAW_CHARACTER_RELIC);
                break;
            }

        }
    }    
}

void setPlayer() {

    sprintf(level_to_draw[player.pos_y][player.pos_x], DRAW_CHARACTER_PLAYER);
}

void drawLevel() {

    //system("cls");

    setLevelToDraw();

    for(int i = 0 ; i < level_active.height ; i++) {

        for(int j = 0 ; j < level_active.width ; j++) {

            printf("%s", level_to_draw[i][j]);
        }
    
        printf("\n");
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