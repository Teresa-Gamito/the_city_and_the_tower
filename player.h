#include <stdbool.h>

#include "level.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
    
    int pos_x; // player x position
    int pos_y; //player y position
    char item; // use a specific character for each item

} Player;

// player creation
void playerSpawn(Player * player, Level level);

// player movement
void playerMove(Player * player, int pos_x, int pos_y); // move the player

// item related actions
bool playerHasItem(Player player); // return true if the player has an item
void playerPickUpItem(Player * player, Level * level, int pos_x, int pos_y); // gets an item on the selected level
void playerDropItem(Player * player, Level * level, int pos_x, int pos_y); // gets an item on the selected level

#endif
