
#include <stdio.h>

#include "level.h"
#include "player.h"
#include "items.h"

#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[MAX_HIGHT][MAX_WIDTH];

// needs changing
// Draw order: Tiles -> Items -> Player -> Darkness -> Highlight
void setLevelToDraw(char * level_to_draw); // to set the following functions in order

// This actions will be set in this order to print
void drawSetTiles(char * level_to_draw, Level level); // print the Tiles layer
void drawSetItems(char * level_to_draw, Item * item_stack); // print the items
void drawSetPlayer(char * level_to_draw, Player player); // print the player
void drawSetDarkness(char * level_to_draw, Level level); // print the Darkness layer
void drawSetHighlight(char * level_to_draw, int pos_x, int pos_y, char highlight_type); // print the highlighting

// Draw level
void drawLevel(char * level_to_draw);


#endif