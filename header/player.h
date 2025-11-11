#include <stdbool.h>

//#include "level.h"

#ifndef PLAYER_H
#define PLAYER_H

// define the player as an object
typedef struct Player {
    
    int pos_x; // player x position
    int pos_y; //player y position
    char item; // use a specific character for each item

} Player;

// global player
extern Player player;

// player creation
void playerSpawn(int pos_x, int pos_y, char item);

// player movement
void playerMove(int pos_x, int pos_y); // move the player
// other redundant functions
void playerAction(char dir);

// item related actions
bool playerHasItem(); // return true if the player has an item

#endif