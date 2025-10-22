#include <stdio.h>
#include <stdbool.h>

/*  ===== Labels =====
'W' - Wall
'P' - Pit
'0' - Empty
'R' - Relic
'T' - Torch
'P' - Player 
*/

#define MAX_WIDTH 60
#define MAX_HIGHT 33


#ifndef LEVEL_H
#define LEVEL_H

typedef struct Level {
    char tiles[MAX_HIGHT][MAX_WIDTH];
    char items[MAX_HIGHT][MAX_WIDTH];
    bool darkness[MAX_HIGHT][MAX_WIDTH];
} Level;

extern Level lvl1;

bool tileIsWalkable(Level level, int pos_x, int pos_y);
bool tileHasItem(Level level, int pos_x, int pos_y);

int levelGetWidth(Level level);
int levelGetHight(Level level);


#endif
