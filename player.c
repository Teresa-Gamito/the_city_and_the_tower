#include <stdio.h>
#include <stdbool.h>
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

void playerMove(int pos_x, int pos_y) {

    player.pos_x = pos_x;
    player.pos_y = pos_y;
}

bool playerHasItem() {

    return player.item != '0';
}

void playerPickUpItem(int pos_x, int pos_y) {

    if(!playerHasItem() && tileHasItem(pos_x, pos_y)) {

        player.item = level_active.objects[pos_y][pos_x];

        level_active.objects[pos_y][pos_x] = '0';
    }
}

void playerDropItem(int pos_x, int pos_y) {

    if(playerHasItem() && !tileHasItem(pos_x, pos_y)) {

        level_active.objects[pos_y][pos_x] = player.item;

        player.item = '0';
    }
}

void playerAction(char act) {

        switch(act) {

            case 'z':
        case 'Z':

            playerPickUpItem(player.pos_x, player.pos_y);
            break;

        case 'x':
        case 'X':

            playerDropItem(player.pos_x, player.pos_y);
            break;
        }
}