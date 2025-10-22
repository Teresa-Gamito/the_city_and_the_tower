#include <stdio.h>
#include <stdbool.h>
#include "level.h"

/*  ===== Labels =====
'W' - Wall
'P' - Pit
'0' - Empty
'R' - Relic
'T' - Torch
'P' - Player 
*/

struct Level lvl1 = 
{
    {
        {"WWWWWWWWWW"},
        {"W00000000W"},
        {"W00000000W"},
        {"W00000000W"},
        {"W00000000W"},
        {"W00000000W"},
        {"W00000000W"},
        {"W00000000W"},
        {"W00000000W"},
        {"WWWWWWWWWW"},
    },
    {
        {"0000000000"},
        {"0000000000"},
        {"00P0000000"},
        {"0000000000"},
        {"0000000R00"},
        {"0000000000"},
        {"0000000000"},
        {"0000000000"},
        {"0000000000"},
        {"0000000000"},
    },
    {{0}}
};

bool isWalkable(struct Level level, int pos_x, int pos_y);
