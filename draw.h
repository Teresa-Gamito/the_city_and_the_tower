
#include <stdio.h>

#include "level.h"
#include "player.h"
#include "items.h"

#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[MAX_HEIGHT][MAX_WIDTH];

// needs changing
// Draw order: Tiles -> Items -> Player -> Darkness -> Highlight
void setLevelToDraw(); // to set the following functions in order

// This actions will be set in this order to print
void drawSetTiles(); // print the Tiles layer
void drawSetItems(); // print the items
void drawSetPlayer(); // print the player
void drawSetDarkness(); // print the Darkness layer
void drawSetHighlight(int pos_x, int pos_y, char highlight_type); // print the highlighting

// Draw level
void drawLevel();


#endif