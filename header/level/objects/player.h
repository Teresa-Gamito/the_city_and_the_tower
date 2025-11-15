
// ==============================
// Player related functions
// ==============================



#include <stdbool.h>

#define PLAYER_SPAWN_FROM_FILE -1
#define PLAYER_NO_ITEM 0

#ifndef PLAYER_H
#define PLAYER_H

// define the player as an object
typedef struct Player {
    
    int pos_x;  // player x position
    int pos_y;  // player y position
    char item;  // player held item

} Player;

// global player
extern Player player;

void playerSpawn(int pos_x, int pos_y, char item); // spawns the player into the level

void playerMove(int pos_x, int pos_y); // move the player
void playerAction(char dir); // execute actions related to the player with given input

bool playerHasItem(); // return true if the player has an item

#endif