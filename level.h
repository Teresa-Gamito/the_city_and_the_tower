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

struct Level {
    char tiles[MAX_HIGHT][MAX_WIDTH];
    char items[MAX_HIGHT][MAX_WIDTH];
    bool darkness[MAX_HIGHT][MAX_WIDTH];
};

#endif
