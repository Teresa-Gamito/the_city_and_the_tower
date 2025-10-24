#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 60
#define MAX_HIGHT 33

#define LEVEL_FILE_NAME "lvl00.txt"
#define LEVEL_FILE_NAME_SIZE 10

#ifndef LEVEL_H
#define LEVEL_H

typedef struct Level {
    int width;
    int height;
    char tiles[MAX_HIGHT][MAX_WIDTH]; // this includes tiles
    char objects[MAX_HIGHT][MAX_WIDTH]; // this includes only items and the player
    bool darkness[MAX_HIGHT][MAX_WIDTH]; // setting this layer allows to define permanently lit spaces
} Level;

extern Level level_active; // this will be the current level

Level getLevelFromFile(int level_num);
char * getLevelFileName(int level_num);

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