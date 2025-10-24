
#include <stdio.h>

#include "level.h"
#include "player.h"
#include "items.h"

#ifndef DRAW_H
#define DRAW_H

// draw menus
void drawMenu();



// ===== prepare level to be drawn =====
// an array will be created with the active level layout (Level level_active) that consists on a single layer
// items and the player will be converted into objects and removed from the layer
extern char level_to_draw[MAX_HIGHT][MAX_WIDTH];


// needs changing
// Draw order: Tiles -> Items -> Player -> Darkness -> Highlight
void setLevelToDraw(char * level_to_draw); // to set the following functions in order

// This actions will be set in this order to print
void levelSetTiles(char * level_to_draw, Level level);
//void levelSetItems(char * level_to_draw,...); // there should be a better way of doing this
void levelSetPlayer(char * level_to_draw, Player player);
void levelSetDarkness(char * level_to_draw, Level level);
void levelSetHighlight(char * level_to_draw, int pos_x, int pos_y);

// Draw level
void drawLevel(char * level_to_draw);


#endif