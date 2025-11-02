
#include <stdio.h>

#include "level.h"
#include "player.h"
//#include "items.h"

// tiles
#define DRAW_CHARACTER_WALL "🟨"
#define DRAW_CHARACTER_GROUND "⬜"
#define DRAW_CHARACTER_PIT "🟥"
// objects
#define DRAW_CHARACTER_PLAYER "🐐"
#define DRAW_CHARACTER_PLANK "📏"
#define DRAW_CHARACTER_RELIC "🏆"
#define DRAW_CHARACTER_TORCH "💡"
// light
#define DRAW_CHARACTER_DARK "⬛"

/* // tiles
#define DRAW_CHARACTER_WALL "a"
#define DRAW_CHARACTER_GROUND "b"
#define DRAW_CHARACTER_PIT "c"
// objects
#define DRAW_CHARACTER_PLAYER "d"
#define DRAW_CHARACTER_PLANK "e"
#define DRAW_CHARACTER_RELIC "f"
#define DRAW_CHARACTER_TORCH "g"
// light
#define DRAW_CHARACTER_DARK "h" */

#define EMOJI_SIZE 5


#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[MAX_HEIGHT][MAX_WIDTH][EMOJI_SIZE];

// needs changing
// Draw order: Tiles -> Items -> Player -> light -> Highlight
void setLevelToDraw(); // to set the following functions in order

// This actions will be set in this order to print
void setTiles(); // set the Tiles layer
void setItems(); // set the items
void setPlayer(); // set the player
void setLight(); // set the light layer
void setHighlight(int pos_x, int pos_y, char highlight_type); // set the highlighting

// Draw level
void drawLevel();

//Draw menus
int drawStartMenu(char opt);
void drawPauseMenu();
void drawOptionsMenu();
void drawCreditsMenu();

#endif