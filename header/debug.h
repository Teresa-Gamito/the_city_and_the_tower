
// ========================================
// Debugging tools
// Logging
// Commands
// ========================================


#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#include "level/level.h"


// command naming
#define COMMAND_RESTART "restart"               // restart level
#define COMMAND_NEXT_PHASE "next_phase"         // go to next phase
#define COMMAND_NEXT_LEVEL "next_level"         // go to next leevel
#define COMMAND_TORCH "torch"                   // spawn torch
#define COMMAND_RELIC "relic"                   // spawn relic
#define COMMAND_PLANK "plank"                   // spawn plank
#define COMMAND_LIGHT "light"                   // light up room
#define COMMAND_PHASE "phase"                   // toggle phasing through obstacles
#define COMMAND_LIGHT_RADIUS_UP "rad_up"        // increse light radius
#define COMMAND_LIGHT_RADIUS_DOWN "rad_down"    // decrese light radius
#define COMMAND_CLEAR_TOGGLE "clr"              // decrese light radius


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
void debugCommand(char * msg); // run debug commands

#endif