#include <stdbool.h>

#include "level.h"
#include "items.h"

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
void playerSpawn(Level level);

// player movement
void playerMove(int pos_x, int pos_y); // move the player
// other redundant functions
void playerMoveDirection(char dir);
void playerMoveUp();
void playerMoveDown();
void playerMoveLeft();
void playerMoveRight();

// item related actions
bool playerHasItem(); // return true if the player has an item
void playerPickUpItem(int pos_x, int pos_y); // grabs an item from the stack
void playerDropItem(int pos_x, int pos_y); // puts an item on the stack

#endif