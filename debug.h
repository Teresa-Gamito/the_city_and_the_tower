#include <stdio.h>
#include <stdarg.h>

#define LOG_NAME "logs/log%02d%02d%02d%02d%02d.txt\0"

#ifndef DEBUG_H
#define DEBUG_H

extern FILE *file;

// logging related functions
void logOpen();
void logPrint(char * message,...);
void logClose();

void logPrintLayer(char layer[33][60], int width, int height);
void logPrintLevelActive();

void debugCommand(char * msg); // run debug commands

#endif