
// ========================================
// Debugging tools
// Logging
// Commands
// ========================================

#pragma once

#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <SDL3/SDL.h>

#include "level/level.h"
#include "level/objects/player.h"
#include "tools.h"



#define MAX_WIDTH 60
#define MAX_HEIGHT 33

// command naming
#define COMMAND_RESTART SDL_SCANCODE_R               // restart level
#define COMMAND_NEXT_PHASE SDL_SCANCODE_M         // go to next phase
#define COMMAND_NEXT_LEVEL SDL_SCANCODE_N          // go to next leevel
#define COMMAND_TORCH SDL_SCANCODE_T                    // spawn torch
#define COMMAND_RELIC SDL_SCANCODE_Y                    // spawn relic
#define COMMAND_PLANK SDL_SCANCODE_U                    // spawn plank
#define COMMAND_LIGHT SDL_SCANCODE_L                    // light up room
#define COMMAND_PHASE SDL_SCANCODE_G                    // toggle phasing through obstacles
#define COMMAND_LIGHT_RADIUS_UP SDL_SCANCODE_PERIOD       // increse light radius
#define COMMAND_LIGHT_RADIUS_DOWN SDL_SCANCODE_COMMA    // decrese light radius


// debug variables
// extern bool debug_is_active;                 // enable debug commands
extern bool debug_phase_through_walls;          // ability to phase through walls
extern int debug_light_buffer;                  // light up whole level (requires restart level to reset)
extern bool debug_screen_clear;                 // toggles between clear cmd and printing a bunch of new lines


// debug file
// inside "logs" folder, naming contains the current time
#define LOG_NAME "logs/log%02d%02d%02d%02d%02d.txt\0"



#ifndef DEBUG_H
#define DEBUG_H

// logging related functions
void logOpen(); // opens log file
void logClose(); // closes log file

void logPrint(char * message,...); // prints and flushes a message to the log file - same as printf

// temporary testing functions
void logPrintLayer(char layer[MAX_HEIGHT][MAX_WIDTH], int width, int height); // logs a full layer
void logPrintLevelActive(); // logs all layers of current level


// debug commands
void debugCommand(SDL_Event *event); // run debug commands

#endif