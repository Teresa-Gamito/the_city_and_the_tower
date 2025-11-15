
// ========================================
// Highlight layer functions
// ========================================

#include <stdio.h>
#include <stdbool.h>

#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

typedef struct Highlight {

    int pos_x; // highlight position x
    int pos_y; // highlight position y
    bool is_on; // is the highlight active

} Highlight;

extern Highlight highlight;

void highlightSpawn(); // spawns the highlight ui
void highlightDespawn(); // deespawns the highlight ui

void highlightAction(char input); // actions when highlight is on
void highlightMove(int pos_x, int pos_y); // move highlight


#endif