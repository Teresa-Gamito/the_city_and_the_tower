#include <stdbool.h>

#ifndef PLAYER_H
#define PLAYER_H

//create a structure for player with the position

struct Player {
    
    int position_x;
    int position_y;

};

void playerMove(struct Player player);

#endif
