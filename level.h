#include <stdio.h>
#include <stdbool.h>

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


#ifndef LEVEL_H
#define LEVEL_H

typedef struct Level {
    char tiles[MAX_HIGHT][MAX_WIDTH];
    char objects[MAX_HIGHT][MAX_WIDTH];
    bool darkness[MAX_HIGHT][MAX_WIDTH];
} Level;

extern const Level level_list[];

// checks for specific positions within the level selected
bool tileIsWalkable(Level level, int pos_x, int pos_y);
bool tileHasItem(Level level, int pos_x, int pos_y);

// gets current level size
int levelGetWidth(Level level);
int levelGetHight(Level level);


// prepare level to be drawn
// this will be a copy of the current level that will then be changed according to required alterations
Level level_to_draw; // move to level.c

// set the tiles layer first, then the objects and the player and then the darkness
// set the copy with required modifications
void levelSetTiles(Level * level_to_draw, Level level);
void levelSetItems(Level * level_to_draw, Level level);
void levelSetDarkness(Level * level_to_draw, Level level);
void levelSetPlayer(Level * level_to_draw, Player player); //player is set on the objects layer

// merge level layout into a single layer
char* levelMerge(Level level_to_draw); // returns the level to draw as a 2D array

#endif