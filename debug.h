#include <stdio.h>
#include <stdarg.h>

#ifndef DEBUG_H
#define DEBUG_H

extern FILE *file;

// logging related functions
void logOpen();
void logPrint(char * message,...);
void logClose();

void logPrintLevelActive();

void debugCommand(char * msg); // run debug commands

#endif