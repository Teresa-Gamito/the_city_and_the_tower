
#include <stdio.h>
#include <time.h>

#include "debug.h"
#include "level.h"

FILE *file;

void debugCommand(char * msg) {
    
}


void logOpen() {

    // Get current time
    time_t now = time(NULL);         
    struct tm *t = localtime(&now);

    // file name
    char file_name[] = { 'l', 'o', 'g', 's', '/', 'l', 'o', 'g',
        ((t->tm_mon + 1) / 10) + '0', 
        ((t->tm_mon + 1) % 10) + '0', // month
        ((t->tm_mday) / 10) + '0',
        ((t->tm_mday) % 10) + '0',    // day
        ((t->tm_hour) / 10) + '0',
        ((t->tm_hour) % 10) + '0',    // hour
        ((t->tm_min) / 10) + '0',
        ((t->tm_min) % 10) + '0',     // minutes
        ((t->tm_sec) / 10) + '0',
        ((t->tm_sec) % 10) + '0'      // seconds
    };

    // open file
    file = fopen(file_name, "at");
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