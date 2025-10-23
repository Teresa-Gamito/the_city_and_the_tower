#include <stdio.h>
#include <stdbool.h>
#include "player.h"

/*  ===== Labels =====
'W' - Wall
'P' - Pit
'0' - Empty
'R' - Relic
'T' - Torch
'P' - Player 
*/

#define MAX_WIDTH 60
#define MAX_HIGHT 33

#define MAX_NUM_OF_DIGITS_FOR_LEVEL_NAME 2


#ifndef LEVEL_H
#define LEVEL_H

typedef struct Level {
    char tiles[MAX_HIGHT][MAX_WIDTH]; // this includes tiles
    char objects[MAX_HIGHT][MAX_WIDTH]; // this includes only items and the player
    bool darkness[MAX_HIGHT][MAX_WIDTH]; // setting this layer allows to define permanently lit spaces
} Level;

extern Level level_active; // this will be the current level


Level getLevelFromFile(int level_num);


/*

Here we can save the current level progress

*/

// ===== Get info from level =====
// checks for specific positions within the level selected
bool tileIsWalkable(Level level, int pos_x, int pos_y);
bool tileHasItem(Level level, int pos_x, int pos_y);

// gets current level size
int levelGetWidth(Level level);
int levelGetHight(Level level);




#endif