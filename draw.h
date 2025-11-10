
#include <stdio.h>

#include "level.h"
#include "player.h"
//#include "items.h"

// tiles
#define DRAW_CHARACTER_WALL "❌"
#define DRAW_CHARACTER_GROUND "⬜"
#define DRAW_CHARACTER_PIT "🟥"
#define DRAW_CHARACTER_PLANK_TILE "🌉"
// objects
#define DRAW_CHARACTER_PLAYER "🐐"
#define DRAW_CHARACTER_PLANK "📏"
#define DRAW_CHARACTER_RELIC "🏆"
#define DRAW_CHARACTER_TORCH "💡"
// light
#define DRAW_CHARACTER_DARK "⬛"
// highlight
#define DRAW_CHARACTER_HIGHLIGHT_GREEN "💚"
#define DRAW_CHARACTER_HIGHLIGHT_YELLOW "💛"
#define DRAW_CHARACTER_HIGHLIGHT_RED "💔"



#define EMOJI_SIZE 5


#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[MAX_HEIGHT][MAX_WIDTH];

// needs changing
// Draw order: Tiles -> Items -> Player -> light -> Highlight
void setLevelToDraw(); // to set the following functions in order

// This actions will be set in this order to print
void setTiles(); // set the Tiles layer
void setItems(); // set the items
void setPlayer(); // set the player
void setLight(); // set the light layer
void setHighlight(); // set the highlighting

// Draw level
void drawLevel();
void printEmoji(char character);

//Draw menus
int drawStartMenu(char opt);
void drawPauseMenu();
void drawOptionsMenu();
void drawCreditsMenu();

#endif