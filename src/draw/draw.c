#include <stdio.h>
#include <stdlib.h>

#include "../../header/draw/draw.h"
#include "../../header/level/level.h"
#include "../../header/level/objects/player.h"
#include "../../header/level/highlight.h"
#include "../../header/level/objects/item.h"
#include "../../header/level/light.h"
#include "../../header/debug.h"
#include "../../header/tools.h"


char level_to_draw[DRAW_HEIGHT][DRAW_WIDTH] = {{CHAR_NOTHING}};

void setLevelToDraw() {

    int center_x = DRAW_WIDTH;
    int center_y = DRAW_HEIGHT;

    center_x /= 2;
    center_y /= 2;

    int offset_x = level_active.width / 2;
    int offset_y = level_active.height / 2;

    int pos_x = center_x - offset_x;
    int pos_y = center_y - offset_y;

    logPrint("Setting level to draw at: x:%d, y:%d\n", pos_x, pos_y);

    setClear();

    setTiles(pos_x, pos_y);
    setItems(pos_x, pos_y);
    setLight(pos_x, pos_y);
    setPlayer(pos_x, pos_y);
    setHighlight(pos_x, pos_y);

}

void setClear() {

    char layer_clear[DRAW_HEIGHT][DRAW_WIDTH] = {{CHAR_NOTHING}};

    layerCopy((char *)layer_clear, (char *)level_to_draw, DRAW_WIDTH, DRAW_HEIGHT);

}


void setTiles(int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            level_to_draw[pos_y + i][pos_x + j] = level_active.tiles[i][j];

        }
    }
    logPrint("Set draw tiles\n");

}

void setLight(int pos_x, int pos_y) {
    
    lightPorcessLayers();
    
    for(int i = 0 ; i < level_active.height ; i++) {
        for(int j = 0 ; j < level_active.width ; j++) {

            if (level_active.light[i][j] == CHAR_UNLIT) 
                level_to_draw[pos_y + i][pos_x + j] = level_active.light[i][j];
        }
    }

    logPrint("Set draw light\n");
}

void setItems(int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            if (level_active.objects[i][j] != CHAR_EMPTY)
                level_to_draw[pos_y + i][pos_x + j] = level_active.objects[i][j];

        }
    }

    logPrint("Set draw items\n");
}

void setPlayer(int pos_x, int pos_y) {

    level_to_draw[player.pos_y + pos_y][player.pos_x + pos_x] = CHAR_PLAYER;

    logPrint("Set draw player\n");

}

void setHighlight(int pos_x, int pos_y) {

    if (highlight.is_on) level_to_draw[highlight.pos_y + pos_y][highlight.pos_x + pos_x] = CHAR_HIGHLIGHT;

    logPrint("Set draw highlight\n");

}



void drawLevel() {

    clear();

    setLevelToDraw();

    logPrint("Drawing level\n");

    for(int i = 0 ; i < DRAW_HEIGHT; i++) {
        for(int j = 0 ; j < DRAW_WIDTH; j++) {

            printLevel(j, i);

        }
    
        printf("\n");
    }

    printHeldItem();
    
}


void printLevel(int pos_x, int pos_y) {

    if (pos_y == 0 && pos_x == DRAW_WIDTH - 1) printf(DRAW_BORDER_TOP_RIGHT);
    else if (pos_y == 0 && pos_x == 0) printf(DRAW_BORDER_TOP_LEFT);
    else if (pos_y == DRAW_HEIGHT - 1 && pos_x == DRAW_WIDTH - 1) printf(DRAW_BORDER_BOTTOM_RIGHT);
    else if (pos_y == DRAW_HEIGHT - 1 && pos_x == 0) printf(DRAW_BORDER_BOTTOM_LEFT);

    else if (pos_y == 0) printf(DRAW_BORDER_TOP);
    else if (pos_y == DRAW_HEIGHT - 1) printf(DRAW_BORDER_BOTTOM);
    else if (pos_x == 0) printf(DRAW_BORDER_LEFT);
    else if (pos_x == DRAW_WIDTH - 1) printf(DRAW_BORDER_RIGHT);

    else printEmoji(level_to_draw[pos_y][pos_x]);


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

            if (itemCanBeDropped(highlight.pos_x, highlight.pos_y) && playerHasItem()) 
                printf(DRAW_CHARACTER_HIGHLIGHT_YELLOW);

            else if (!itemCanBeDropped(highlight.pos_x, highlight.pos_y) && playerHasItem())
                printf(DRAW_CHARACTER_HIGHLIGHT_RED);
            
            else printf(DRAW_CHARACTER_HIGHLIGHT_GREEN);

            break;

        case CHAR_EXIT:
            printf(DRAW_CHARACTER_EXIT);
            break;

        case CHAR_NOTHING:
            printf(DRAW_CHAR_NOTHING);
            break;
    }
}

void printHeldItem() {

    printf("\nHeld Item: ");
    if (player.item != CHAR_EMPTY) printEmoji(player.item);
    printf("\n");

}