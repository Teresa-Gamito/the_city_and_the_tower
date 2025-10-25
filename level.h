#include <stdio.h>
#include <stdbool.h>

#include "items.h"

#define MAX_WIDTH 60
#define MAX_HIGHT 33

#define LEVEL_FILE_NAME "lvl00.txt\0"

#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
    int width;
    int height;
    char tiles[MAX_HIGHT][MAX_WIDTH]; // this includes tiles
    char objects[MAX_HIGHT][MAX_WIDTH]; // this includes only items and the player
    bool darkness[MAX_HIGHT][MAX_WIDTH]; // setting this layer allows to define permanently lit spaces
} Level;

extern Level level_active; // this will be the current level

void loadLevel(Level level, int level_num);
Level getLevelFromFile(int level_num);
char * getLevelFileName(int level_num);

/*

Here we can save the current level progress
Will be added when working on menus

*/

// ===== Get info from level =====
// checks for specific positions within the level selected
bool tileIsWalkable(Level level_active, int pos_x, int pos_y);
bool tileHasItem(Level level_active, int pos_x, int pos_y);

// gets current level size
int levelGetWidth(Level level_active);
int levelGetHight(Level level_active);

void processLightItems(Level * level_active, Item * item_stack); // will process the light coming from items



#endif