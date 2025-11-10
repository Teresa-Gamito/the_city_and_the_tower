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

typedef struct Highlight {

    int pos_x; // highlight position x
    int pos_y; // highlight position y
    bool is_on; // is the highlight active

} Highlight;

extern Player player;
extern Highlight highlight;

// player creation
void playerSpawn();

// player movement
void playerMove(int pos_x, int pos_y); // move the player
// other redundant functions
void playerAction(char dir);

// item related actions
bool playerHasItem(); // return true if the player has an item
void playerPickUpItem(int pos_x, int pos_y); // grabs an item from the stack
void playerDropItem(int pos_x, int pos_y); // puts an item on the stack
bool playerCanDropItem(int pos_x, int pos_y);

void highlightSpawn();
void highlightDespawn();
void highlightAction(char input);
void highlightMove(int pos_x, int pos_y);

#endif