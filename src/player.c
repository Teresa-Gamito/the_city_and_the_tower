
#include <stdio.h>
#include <stdbool.h>

#include "../header/player.h"
#include "../header/level.h"
#include "../header/item.h"
#include "../header/highlight.h"

Player player = {0, 0, '0'};


void playerSpawn() {

    for(int i = 0 ; i < level_active.width ; i++) {

        for(int j = 0 ; j < level_active.height ; j++) {

            if(level_active.objects[i][j] == CHAR_PLAYER) {

                player.pos_x = j;
                player.pos_y = i;

                level_active.objects[i][j] = CHAR_EMPTY;
                
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

    return player.item != CHAR_EMPTY;

}