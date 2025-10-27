
#include <stdio.h>

#include "debug.h"

void logOpen() {
    file = fopen(LOG_NAME, "wt");
}
void logPrint(char * message) {
    fputs(message, file);
    fputc('\n', file);
}
void logClose() {
    fclose(file);
}