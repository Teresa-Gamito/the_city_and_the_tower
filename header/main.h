
#pragma once


#include <stdio.h>
#include <stdbool.h>

#include "level/light.h"
#include "draw/menu.h"
#include "draw/draw.h"
#include "debug.h"

typedef struct Gamestate {
    int current_screen;
    int current_menu;
    int current_submenu;
    int current_option;
} Gamestate;

extern Gamestate gamestate;

void game_quit();





