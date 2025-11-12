
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

void highlightSpawn();
void highlightDespawn();

void highlightAction(char input);
void highlightMove(int pos_x, int pos_y);


#endif