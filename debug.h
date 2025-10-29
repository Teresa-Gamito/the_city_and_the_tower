#include <stdio.h>

extern FILE *file;

// logging related functions
void logOpen();
void logPrints(char * message);
void logPrintc(char message);
void logClose();

void logPrintLevelActive();