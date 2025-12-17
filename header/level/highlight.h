
// ========================================
// Highlight layer functions
// ========================================

#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "objects/player.h"
#include "objects/item.h"
#include "../debug.h"
#include "../draw/draw.h"

#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#define HIGHLIGHT_RESET 0
#define HIGHLIGHT_MOVE_UP 1
#define HIGHLIGHT_MOVE_DOWN 2
#define HIGHLIGHT_MOVE_LEFT 3
#define HIGHLIGHT_MOVE_RIGHT 4

#define DELAY_HIGHLIGHT_RESET_POSITION 1000


typedef struct Highlight {

    int pos_x; // highlight position x
    int pos_y; // highlight position y
    bool is_on; // is the highlight active

} Highlight;

extern Highlight highlight;

void highlightSpawn(); // spawns the highlight ui
void highlightDespawn(); // deespawns the highlight ui

void highlightAction(int input); // actions when highlight is on
void highlightMove(int pos_x, int pos_y); // move highlight

Uint32 highlightResetPosition(void *userdata, SDL_TimerID timerID, Uint32 interval);

#endif