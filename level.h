#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 60
#define MAX_HEIGHT 33

#define LEVEL_FILE_NAME "level/lvl%02d.txt\0"

#define LIGHT_RADIUS_TORCH 3.17
#define LIGHT_RADIUS_WALL_TORCH 3.17

// labels for level creation
// these are the characters read from the lvl.txt file
// tiles layer
#define CHAR_WALL 'W'
#define CHAR_GROUND '0'
#define CHAR_PIT 'P'
#define CHAR_WALL_TORCH 'T'
// objects layer
#define CHAR_PLAYER 'P'
#define CHAR_RELIC 'R'
#define CHAR_TORCH 'T'
#define CHAR_PLANK 'L'
#define CHAR_EMPTY '0'
// darkness layer
#define CHAR_LIT 1
#define CHAR_UNLIT 0

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

void lightReset(); // resets light to starting values
void lightPorcessLayers(); // find light emitting tiles and process the light coming from them
void lightProcess(int pos_x, int pos_y, double light_radius); // from a light source, set the surrounding tiles as lit

// other functions
double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y); // get distance btwwen two points

#endif