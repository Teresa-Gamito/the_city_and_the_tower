
// ========================================
// Level loading and analizing related functions
// opens a level file and stores it as the current level
// analizes the current level's properties
// ========================================


#include <stdio.h>
#include <stdbool.h>

// max level properties
#define MAX_WIDTH 60
#define MAX_HEIGHT 33
#define MAX_LAYERS 3

#define MAX_PHASES 2
#define MAX_LEVELS 10

// level naming
// inside the "level" folder - 'lvl' + number of level + '-' + phase of level
#define LEVEL_FILE_NAME "level/lvl%02d-%01d.txt\0"


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


typedef struct { // loaded level structure
    int width;                                      // current level width
    int height;                                     // current level height
    char tiles[MAX_HEIGHT][MAX_WIDTH];              // tiles layer
    char objects[MAX_HEIGHT][MAX_WIDTH];            // items and player layer
    char light[MAX_HEIGHT][MAX_WIDTH];              // light layer
    char starting_light[MAX_HEIGHT][MAX_WIDTH];     // initial light layer
    int level_num;                                  // number of current level
    int phase_num;                                  // number of current phase
    bool relic_was_picked_up;                       // relic pick up status
    bool level_exit;                                // asks to exit the level
    bool level_won;                                 // completes the level
} Level;

extern Level level_active; // the current level

// file interaction
char * levelFileGetName(int level_num, int phase_num);
FILE * levelFileOpen(int level_num, int phase_num);
void levelFileClose(FILE * level_file);

// set level_active structure
void levelFileGetLayerNext(FILE * level_file, char layer[MAX_HEIGHT][MAX_WIDTH]); // get next layer from file
void levelActiveSetFromFile(int level_num, int phase_num); // sets the active level as the one from the file

void levelLoad(int level_num, int phase_num, int player_pos_x, int player_pos_y, char item); // loads a level
void levelTriggerNextPhase(); // triggers the next phase of the level
void levelLoadNextPhase(); // loads the next phase of the level
void levelGoToNext(); // goes to the next level
void levelRestart(); // restarts the level
void levelExit(); // exits the level
void levelWin(); // completes the level with win status

void levelTransitionAction(); // level transition cutscene

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