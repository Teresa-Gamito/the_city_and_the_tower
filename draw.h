
#include <stdio.h>

#include "level.h"
#include "player.h"
//#include "items.h"

#define DRAW_CHARACTER_DARKNESS '*'
#define DRAW_CHARACTER_PLAYER 'P'
#define DRAW_CHARACTER_GROUND 255
#define DRAW_CHARACTER_WALL 178
#define DRAW_CHARACTER_PIT 'X'
#define DRAW_CHARACTER_PLANK 205
#define DRAW_CHARACTER_RELIC 232
#define DRAW_CHARACTER_TORCH 173


#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[MAX_HEIGHT][MAX_WIDTH];

// needs changing
// Draw order: Tiles -> Items -> Player -> Darkness -> Highlight
void setLevelToDraw(); // to set the following functions in order

// This actions will be set in this order to print
void setTiles(); // set the Tiles layer
void setItems(); // set the items
void setPlayer(); // set the player
void setDarkness(); // set the Darkness layer
void setHighlight(int pos_x, int pos_y, char highlight_type); // set the highlighting

// Draw level
void drawLevel();

//Draw menus
int drawStartMenu(char opt);
void drawPauseMenu();
void drawOptionsMenu();
void drawCreditsMenu();

#endif