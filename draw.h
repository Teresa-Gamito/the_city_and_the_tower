
#include <stdio.h>

#include "level.h"
#include "player.h"
#include "items.h"

#ifndef DRAW_H
#define DRAW_H

// draw menus
void drawMenu();



// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[MAX_HIGHT][MAX_WIDTH];


// needs changing
// Draw order: Tiles -> Items -> Player -> Darkness -> Highlight
void setLevelToDraw(char * level_to_draw); // to set the following functions in order

// This actions will be set in this order to print
void levelSetTiles(char * level_to_draw, Level level); // print the Tiles layer
void levelSetItems(char * level_to_draw, Item * item_stack); // print the items
void levelSetPlayer(char * level_to_draw, Player player); // print the player
void levelSetDarkness(char * level_to_draw, Level level); // print the Darkness layer
void levelSetHighlight(char * level_to_draw, int pos_x, int pos_y); // print the highlighting

// Draw level
void drawLevel(char * level_to_draw);


#endif