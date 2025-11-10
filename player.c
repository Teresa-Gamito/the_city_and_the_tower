#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "level.h"

Player player = {0, 0, '0'};
Highlight highlight = {0, 0, 0};


void playerSpawn() {

    for(int i = 0 ; i < level_active.width ; i++) {

        for(int j = 0 ; j < level_active.height ; j++) {

            if(level_active.objects[i][j] == 'P') {

                player.pos_x = j;
                player.pos_y = i;

                level_active.objects[i][j] = '0';
                
                return;
            }
        }
    }

    highlight.pos_x = player.pos_x;
    highlight.pos_y = player.pos_y;

}

void playerAction(char dir) {

    switch(dir) {

        case 'w':
        case 'W':
            if(tileIsWalkable(player.pos_x, player.pos_y - 1)) {
                
                playerMove(player.pos_x, player.pos_y - 1);
            }
        break;

        case 's':
        case 'S':
            if(tileIsWalkable(player.pos_x, player.pos_y + 1)) {
                
                playerMove(player.pos_x, player.pos_y + 1);
            }
        break;

        case 'a':
        case 'A':
            if(tileIsWalkable(player.pos_x - 1, player.pos_y)) {
                
                playerMove(player.pos_x - 1, player.pos_y);
            }
        break;

        case 'd':
        case 'D':
            if(tileIsWalkable(player.pos_x + 1, player.pos_y)) {
                
                playerMove(player.pos_x + 1, player.pos_y);
            }
        break;

        case 'Z':
        case 'z':
            highlightSpawn();
        break;
        
    }

    
}

void playerMove(int pos_x, int pos_y) {

    player.pos_x = pos_x;
    player.pos_y = pos_y;
}

bool playerHasItem() {

    return player.item != '0';
}

void playerPickUpItem(int pos_x, int pos_y) {

    if(!playerHasItem() && tileHasItem(pos_x, pos_y)) {

        if (level_active.tiles[pos_x][pos_y] == CHAR_PLANK_TILE) {
            player.item = CHAR_PLANK;
            level_active.tiles[pos_x][pos_y] = CHAR_PIT;
        }
        else player.item = level_active.objects[pos_y][pos_x];

        level_active.objects[pos_y][pos_x] = '0';
    }
}

void playerDropItem(int pos_x, int pos_y) {

    if(playerHasItem() && !tileHasItem(pos_x, pos_y) && playerCanDropItem(pos_x, pos_y)) {

        if (level_active.tiles[pos_x][pos_y] == CHAR_PIT && player.item == CHAR_PLANK) level_active.tiles[pos_x][pos_y] = CHAR_PLANK_TILE;
        else level_active.objects[pos_y][pos_x] = player.item;

        player.item = '0';
    }
}

bool playerCanDropItem(int pos_x, int pos_y) {
    
    if (level_active.tiles[pos_y][pos_x] == CHAR_GROUND) return 1;
    if (player.item == CHAR_PLANK && level_active.tiles[pos_y][pos_x] == CHAR_PIT) return 1;


    return 0;
}


void highlightSpawn() {
    highlight.pos_x = player.pos_x;
    highlight.pos_y = player.pos_y;
    highlight.is_on = 1;
}

void highlightDespawn() {
    highlight.is_on = 0;
}

void highlightMove(int pos_x, int pos_y) {
    highlight.pos_x = pos_x;
    highlight.pos_y = pos_y;
}

void highlightAction(char input) {
    switch (input) {
        case 'w':
        case 'W':
            highlightMove(player.pos_x, player.pos_y - 1);
        break;

        case 's':
        case 'S':
            highlightMove(player.pos_x, player.pos_y + 1);
        break;

        case 'a':
        case 'A':
            highlightMove(player.pos_x - 1, player.pos_y);
        break;

        case 'd':
        case 'D':
            highlightMove(player.pos_x + 1, player.pos_y);
        break;

        case 'z':
        case 'Z':
            if (tileHasItem(highlight.pos_x, highlight.pos_y) && !playerHasItem()) {
                playerPickUpItem(highlight.pos_x, highlight.pos_y);
            }
            else if (!tileHasItem(highlight.pos_x, highlight.pos_y) && playerHasItem() && playerCanDropItem(highlight.pos_x, highlight.pos_y)) {
                playerDropItem(highlight.pos_x, highlight.pos_y);
            }
            highlightDespawn();
        break;
    }
}


