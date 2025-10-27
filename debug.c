
#include <stdio.h>

#include "debug.h"
#include "level.h"

FILE *file;

void logOpen() {
    file = fopen(LOG_NAME, "wt");
}

void logPrints(char * message) {
    fputs(message, file);
    fputc('\n', file);
}

void logPrintc(char message) {
    fputc(message, file);

}

void logClose() {
    fclose(file);
}

void logPrintLevelActive() {

    logPrints("level_active : \nTiles :");

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {
            logPrintc(level_active.tiles[i][j]);
        }
        logPrintc('\n');
    }
    logPrints("Objects :");

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {
            logPrintc(level_active.objects[i][j]);
        }
        logPrintc('\n');
    }
    logPrints("Darkness :");

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {
            logPrintc(level_active.darkness[i][j] + '0');
        }
        logPrintc('\n');
    }
    logPrintc('\n');
}