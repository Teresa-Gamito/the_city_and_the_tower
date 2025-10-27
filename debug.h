#include <stdio.h>

#define LOG_NAME "log.txt\0"

extern FILE *file;

// logging related functions
void logOpen();
void logPrint();
void logClose();