#include <stdio.h>
#include "player.h"
#include "level.h"

Player player = {0, 0, '0'};

void playerSpawn() {

    for(int i = 0 ; i < level_active.width ; i++) {

        for(int j = 0 ; j < level_active.height ; j++) {

            if(level_active.objects[i][j] == 'P') {

                player.pos_x = j;
                player.pos_y = i;

                level_active.objects[i][j] = '0';
            }
        }
    }
}

void playerMoveDirection(char dir) {

    switch(dir) {

        case 'w':
        case 'W':
            if(tileIsWalkable(player.pos_x, player.pos_y - 1)) {
                
                player.pos_y--;
            }
            break;

        case 's':
        case 'S':
            if(tileIsWalkable(player.pos_x, player.pos_y + 1)) {
                
                player.pos_y++;
            }
            break;

        case 'a':
        case 'A':
            if(tileIsWalkable(player.pos_x - 1, player.pos_y)) {
                
            player.pos_x--;
            }
            break;

        case 'd':
        case 'D':
            if(tileIsWalkable(player.pos_x + 1, player.pos_y)) {
                
            player.pos_x++;
            }
            break;
    }
}

void playerMoveUp() {

    player.pos_y --;
}

void playerMoveDown() {

    player.pos_y ++;
}

void playerMoveLeft() {

    player.pos_x --;
}

void playerMoveRight() {

    player.pos_x ++;
}

void playerMove(int pos_x, int pos_y) {

    player.pos_x = pos_x;
    player.pos_y = pos_y;
}

bool playerHasItem() {

    return player.item != '0';
}