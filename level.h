#include <stdio.h>
#include <stdbool.h>


#define MAX_WIDTH 60
#define MAX_HEIGHT 33

#define LEVEL_FILE_NAME "level/lvl00.txt\0"

#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
    int width;
    int height;
    char tiles[MAX_HEIGHT][MAX_WIDTH]; // this includes tiles
    char objects[MAX_HEIGHT][MAX_WIDTH]; // this includes only items and the player
    bool darkness[MAX_HEIGHT][MAX_WIDTH]; // setting this layer allows to define permanently lit spaces
} Level;

extern Level level_active; // this will be the current level

// gets the level and sets it as level_active
void loadLayoutLevel(int level_num);
void setLevelFromFile(int level_num);
char * getLevelFileName(int level_num);

/* Save system

Here we can save the current level progress
Will be added when working on menus

*/

// ===== Get info from level =====
// checks for specific positions within the level selected
bool tileIsWalkable(int pos_x, int pos_y);
bool tileHasItem(int pos_x, int pos_y);

// gets current level size
int levelGetWidth();
int levelGetHight();

void processLightItems(); // process the light coming from items



#endif