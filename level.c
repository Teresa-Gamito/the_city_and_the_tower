#include <stdio.h>
#include <stdbool.h>
#include <level.h>

// ===== Labels =====
// 'W' - Wall
// 'F' - Floor
// 'P' - Pit
// '0' - Empty
// 'R' - Relic
// 'T' - Torch
// 'P' - Player

struct Level lvl1 = 
{
    {
        {"WWWWWWWWWW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
        {"WFFFFFFFFW"},
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