
#include <stdio.h>
#include <stdarg.h>

#include "level/level.h"

// commands
#define COMMAND_RESTART "restart"
#define COMMAND_NEXT_PHASE "next_phase" // fix
#define COMMAND_NEXT_LEVEL "next_level"


/*
- cheats

spawn item
illuminate
phase theough walls
*/



#define LOG_NAME "../logs/log%02d%02d%02d%02d%02d.txt\0"

#ifndef DEBUG_H
#define DEBUG_H

extern FILE *file;

// logging related functions
void logOpen();
void logPrint(char * message,...);
void logClose();

void logPrintLayer(char layer[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void logPrintLevelActive();

void debugCommand(char * msg); // run debug commands

#endif