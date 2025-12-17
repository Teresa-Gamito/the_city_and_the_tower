
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

#define DELAY_HIGHLIGHT_RESET_POSITION 5000


// Highlight associated with player interactions with the environment
typedef struct Highlight {

    int pos_x;      // highlight position x
    int pos_y;      // highlight position y
    bool is_on;     // is the highlight active

} Highlight;

// global highlight
extern Highlight highlight; 

// spawns the highlight ui
void highlightSpawn();
// deespawns the highlight ui
void highlightDespawn(); 

// actions when the highlight is on
void highlightAction(int input); 
// move the highlight
void highlightMove(int pos_x, int pos_y); 

// callback function associated with a timer
Uint32 highlightResetPosition(void *userdata, SDL_TimerID timerID, Uint32 interval); 

#endif