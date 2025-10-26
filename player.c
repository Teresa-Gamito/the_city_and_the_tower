#include "player.h"

void playerMoveDirection(char dir) {

    switch(dir) {

        case 'w':
        case 'W':
            player.pos_y--;
            break;

        case 's':
        case 'S':
            player.pos_y++;
            break;

        case 'a':
        case 'A':
            player.pos_x--;
            break;

        case 'd':
        case 'D':
            player.pos_x++;
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
    player.pos_y = pos.y;
}

bool playerHasItem() {

    return player.item 
}