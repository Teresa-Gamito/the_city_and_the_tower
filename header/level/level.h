#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 60
#define MAX_HEIGHT 33
#define MAX_LAYERS 3

#define MAX_PHASES 2
#define MAX_LEVELS 10

#define LEVEL_FILE_NAME "../level/lvl%02d-%01d.txt\0"


// labels for level creation
// these are the characters read from the lvl.txt file
#define CHAR_LAYER_TRANSITION '-'
// tiles layer
#define CHAR_WALL 'W'
#define CHAR_GROUND 'G'
#define CHAR_PIT 'V'
#define CHAR_WALL_TORCH_LIT 'I'
#define CHAR_WALL_TORCH_UNLIT 'O'
#define CHAR_PLANK_TILE 'Y'
#define CHAR_EXIT 'E'
// objects layer
#define CHAR_PLAYER 'P'
#define CHAR_RELIC 'R'
#define CHAR_TORCH 'T'
#define CHAR_PLANK 'L'
#define CHAR_EMPTY '0'
// light layer
#define CHAR_LIT '1'
#define CHAR_UNLIT '0'
// highlight
#define CHAR_HIGHLIGHT 'H'

// timing
#define DELAY_WALL_TORCH_ERASE 600

#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
    int width;
    int height;
    char tiles[MAX_HEIGHT][MAX_WIDTH]; // this includes tiles
    char objects[MAX_HEIGHT][MAX_WIDTH]; // this includes only items and the player
    char light[MAX_HEIGHT][MAX_WIDTH]; // setting this layer allows to define permanently lit spaces
    char starting_light[MAX_HEIGHT][MAX_WIDTH];
    int level_num;
    int phase_num;
    bool relic_was_picked_up;
    bool level_exit;
    bool level_won;
} Level;

extern Level level_active; // this will be the current level

// file interaction
char * levelFileGetName(int level_num, int phase_num);
FILE * levelFileOpen(int level_num, int phase_num);
void levelFileClose(FILE * level_file);

// set level_active structure
void levelFileGetLayerNext(FILE * level_file, char layer[MAX_HEIGHT][MAX_WIDTH]); // get next layer from file
void levelActiveSetFromFile(int level_num, int phase_num); // sets the active level as the one from the file

void levelLoad(int level_num, int phase_num, int player_pos_x, int player_pos_y, char item);
void levelTriggerNextPhase();
void levelLoadNextPhase();
void levelGoToNext();
void levelRestart();
void levelExit();
void levelWin();

void levelTransitionAction();

// gets current level size
int levelFileGetWidth(int level_num, int phase_num);
int levelFileGetHight(int level_num, int phase_num);

// checks for specific tiles
bool tileIsWalkable(int pos_x, int pos_y);
bool tileHasItem(int pos_x, int pos_y);
bool tileBlocksLight(int pos_x, int pox_y);
bool tileCanHaveItem(int pos_x, int pos_y, char item);
char tileGetType(int pos_x, int pos_y);

//specific tiles
void wallTorchSetLit(int pos_x, int pos_y);
void wallTorchSetUnlit(int pos_x, int pos_y);

#endif