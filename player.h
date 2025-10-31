#include <stdbool.h>

//#include "level.h"

// labels for item characters
#define ITEM_TORCH 'T'
#define ITEM_PLANK 'L'
#define ITEM_RELIC 'R'

#ifndef PLAYER_H
#define PLAYER_H

// define the player as an object
typedef struct Player {
    
    int pos_x; // player x position
    int pos_y; //player y position
    char item; // use a specific character for each item

} Player;

extern Player player;

// player creation
void playerSpawn();

// player movement
void playerMove(int pos_x, int pos_y); // move the player
// other redundant functions
void playerMoveDirection(char dir);

// item related actions
void playerAction(char act);
bool playerHasItem(); // return true if the player has an item
void playerPickUpItem(int pos_x, int pos_y); // grabs an item from the stack
void playerDropItem(int pos_x, int pos_y); // puts an item on the stack

#endif