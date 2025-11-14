
#include <stdio.h>

#include "level.h"


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

//border
#define DRAW_BORDER_TOP "━━"
#define DRAW_BORDER_RIGHT "┃"
#define DRAW_BORDER_LEFT "┃"
#define DRAW_BORDER_BOTTOM "━━"
#define DRAW_BORDER_TOP_RIGHT "┓"
#define DRAW_BORDER_TOP_LEFT "┏"
#define DRAW_BORDER_BOTTOM_RIGHT "┛"
#define DRAW_BORDER_BOTTOM_LEFT "┗"

#define BORDER_TOP_BUFFER 1
#define BORDER_BOTTOM_BUFFER 1
#define BORDER_LEFT_BUFFER 1
#define BORDER_RIGHT_BUFFER 1

#define DRAW_WIDTH MAX_WIDTH + BORDER_LEFT_BUFFER + BORDER_RIGHT_BUFFER
#define DRAW_HIGHT MAX_HEIGHT + BORDER_TOP_BUFFER + BORDER_BOTTOM_BUFFER

#define EMOJI_SIZE 5


#ifndef DRAW_H
#define DRAW_H


// ===== prepare level to be drawn =====
// this matrix will be updated with each added layer
extern char level_to_draw[DRAW_HIGHT][DRAW_WIDTH];
//extern char level_to_draw[MAX_HEIGHT][MAX_WIDTH];

// needs changing
// Draw order: Tiles -> Items -> Player -> light -> Highlight
void setLevelToDraw(); // to set the following functions in order

// This actions will be set in this order to print
void setTiles(int pos_x, int pos_y); // set the Tiles layer
void setItems(int pos_x, int pos_y); // set the items
void setPlayer(int pos_x, int pos_y); // set the player
void setLight(int pos_x, int pos_y); // set the light layer
void setHighlight(int pos_x, int pos_y); // set the highlighting

// Draw level
void drawLevel();
void printEmoji(char character);
void printHeldItem();

//Draw menus
int drawStartMenu(char opt);
void drawPauseMenu();
void drawOptionsMenu();
void drawCreditsMenu();

#endif