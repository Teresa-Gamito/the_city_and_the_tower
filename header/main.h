
// ==============================
// main functions
// ==============================


#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "level/light.h"
#include "draw/menu.h"
#include "draw/draw.h"
#include "debug.h"

// gamestate that keeps the current saved options throughout the game
// used for options and menus
typedef struct Gamestate {
    int current_screen;
    int current_menu;
    int current_submenu;
    int current_option;
    bool volume_main;
    bool volume_music;
    bool volume_sfx;
} Gamestate;

// global game state
extern Gamestate gamestate;

// quit the game
void game_quit();

// update the game
void gameUpdate();





