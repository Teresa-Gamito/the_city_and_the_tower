
// ========================================
// Printing functions
// Prints the current level
// menu.h prints menus
// ========================================

#include <stdio.h>

#include "../level/level.h"


// Emotes for respective characters
#define CHAR_NOTHING 0
#define DRAW_CHAR_NOTHING "⬛"
// tiles
#define DRAW_CHARACTER_WALL "🧱\b"
#define DRAW_CHARACTER_GROUND "⬜"
#define DRAW_CHARACTER_PIT "🔳"
#define DRAW_CHARACTER_PLANK_TILE "➕"
#define DRAW_CHARACTER_WALL_TORCH_LIT "❗"
#define DRAW_CHARACTER_WALL_TORCH_UNLIT "❕"
#define DRAW_CHARACTER_EXIT "🚪"
// objects
#define DRAW_CHARACTER_PLAYER "🐐"
#define DRAW_CHARACTER_PLANK "📏"
#define DRAW_CHARACTER_RELIC "🏆"
#define DRAW_CHARACTER_TORCH "💡"
// light
#define DRAW_CHARACTER_DARK "⬛"
// highlight
#define DRAW_CHARACTER_HIGHLIGHT_GREEN "🟩\b"
#define DRAW_CHARACTER_HIGHLIGHT_YELLOW "🟨\b"
#define DRAW_CHARACTER_HIGHLIGHT_RED "🟥\b"
// non level emotes (ui)
// border
#define DRAW_BORDER_TOP "━━"
#define DRAW_BORDER_RIGHT "┃"
#define DRAW_BORDER_LEFT "┃"
#define DRAW_BORDER_BOTTOM "━━"
#define DRAW_BORDER_TOP_RIGHT "┓"
#define DRAW_BORDER_TOP_LEFT "┏"
#define DRAW_BORDER_BOTTOM_RIGHT "┛"
#define DRAW_BORDER_BOTTOM_LEFT "┗"

// border values
#define BORDER_TOP_BUFFER 1
#define BORDER_BOTTOM_BUFFER 1
#define BORDER_LEFT_BUFFER 1
#define BORDER_RIGHT_BUFFER 1
// drawing space
#define DRAW_WIDTH MAX_WIDTH + BORDER_LEFT_BUFFER + BORDER_RIGHT_BUFFER
#define DRAW_HEIGHT MAX_HEIGHT + BORDER_TOP_BUFFER + BORDER_BOTTOM_BUFFER

#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// contains all the layers that make a level
// will be updated with each added layer
extern char level_to_draw[DRAW_HEIGHT][DRAW_WIDTH];

// Draw order: Tiles -> Items -> light -> Player -> Highlight
void setLevelToDraw(); // to set the following functions in order
void setClear(); // reset drawing canvas

// This actions will be set in this order to print
void setTiles(int pos_x, int pos_y); // set the Tiles layer
void setItems(int pos_x, int pos_y); // set the items
void setLight(int pos_x, int pos_y); // set the light layer
void setPlayer(int pos_x, int pos_y); // set the player
void setHighlight(int pos_x, int pos_y); // set the highlighting

// Draw level
void drawLevel(); // draw and set up function to print level
void printLevel(int pos_x, int pos_y); // print respective characters at positiopn

// tools
void printEmoji(char character);
void printHeldItem();

#endif