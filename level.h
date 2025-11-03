#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 60
#define MAX_HEIGHT 33
#define MAX_LAYERS 3

#define LEVEL_FILE_NAME "level/lvl%02d.txt\0"

#define LIGHT_RADIUS_TORCH 3.17
#define LIGHT_RADIUS_WALL_TORCH 3.17

// labels for level creation
// these are the characters read from the lvl.txt file
// tiles layer
#define CHAR_WALL 'W'
#define CHAR_GROUND 'G'
#define CHAR_PIT 'P'
#define CHAR_WALL_TORCH 'T'
// objects layer
#define CHAR_PLAYER 'P'
#define CHAR_RELIC 'R'
#define CHAR_TORCH 'T'
#define CHAR_PLANK 'L'
#define CHAR_EMPTY '0'
// light layer
#define CHAR_LIT '1'
#define CHAR_UNLIT '0'

#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
    int width;
    int height;
    char tiles[MAX_HEIGHT][MAX_WIDTH]; // this includes tiles
    char objects[MAX_HEIGHT][MAX_WIDTH]; // this includes only items and the player
    char light[MAX_HEIGHT][MAX_WIDTH]; // setting this layer allows to define permanently lit spaces
    char starting_light[MAX_HEIGHT][MAX_WIDTH];
} Level;

extern Level level_active; // this will be the current level

// file interaction
char * levelFileGetName(int level_num);
FILE * levelFileOpen(int level_num);
void levelFileClose(FILE * level_file);

// set level_active structure
void levelFileGetLayerNext(FILE * level_file, char layer[MAX_HEIGHT][MAX_WIDTH]); // get next layer from file
void levelActiveSetFromFile(int level_num); // sets the active level as the one from the file

// gets current level size
int levelFileGetWidth(int level_num);
int levelFileGetHight(int level_num);

// checks for specific tiles
bool tileIsWalkable(int pos_x, int pos_y);
bool tileHasItem(int pos_x, int pos_y);
bool tileBlocksLight(int pos_x, int pox_y);



// light
void lightReset(); // resets light to starting values
void lightPorcessLayers(); // find light emitting tiles and process the light coming from them
void lightProcess(int pos_x, int pos_y, double light_radius); // from a light source, set the surrounding tiles as lit
bool lightHasCollision(int pos_source_x, int pos_source_y, int pos_final_x, int pos_final_y);

// other functions
void layerCopy(char * layer_to_copy, char * layer_destiny, int max_width, int max_height);
double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y); // get distance btwwen two points
int roundToInt(double x);

#endif