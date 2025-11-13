#include <stdio.h>
#include <stdlib.h>

#include "../header/level/draw.h"
#include "../header/level/level.h"
#include "../header/objects/player.h"
#include "../header/level/highlight.h"
#include "../header/objects/item.h"
#include "../header/level/light.h"

char level_to_draw[MAX_HEIGHT][MAX_WIDTH] = {{0}};

void setLevelToDraw() {

    setTiles();
    setItems();
    setPlayer();
    setLight();
    setHighlight();

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

void setHighlight() {

    if (highlight.is_on) level_to_draw[highlight.pos_y][highlight.pos_x] = CHAR_HIGHLIGHT;

}


void drawLevel() {

    //system("cls");

    setLevelToDraw();

    for(int i = 0 ; i < level_active.height; i++) {
        for(int j = 0 ; j < level_active.width; j++) {
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

        case CHAR_PIT:
            printf(DRAW_CHARACTER_PIT);
            break;

        case CHAR_PLANK_TILE: 
            printf(DRAW_CHARACTER_PLANK_TILE); 
            break;

        case CHAR_WALL_TORCH_LIT:
            printf(DRAW_CHARACTER_WALL_TORCH_LIT);
            break;

        case CHAR_WALL_TORCH_UNLIT:
            printf(DRAW_CHARACTER_WALL_TORCH_UNLIT);
            break;

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

        case CHAR_HIGHLIGHT:

            if (itemCanBeDropped(highlight.pos_x, highlight.pos_y, player.item) && playerHasItem()) 
                printf(DRAW_CHARACTER_HIGHLIGHT_YELLOW);

            else if (!itemCanBeDropped(highlight.pos_x, highlight.pos_y, player.item) && playerHasItem())
                printf(DRAW_CHARACTER_HIGHLIGHT_RED);
            
            else printf(DRAW_CHARACTER_HIGHLIGHT_GREEN);

            break;
    }
}
