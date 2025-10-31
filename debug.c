
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "debug.h"
#include "level.h"

FILE *logFile;

void debugCommand(char * msg) {
    
}


void logOpen() {

    // Get current time
    time_t now = time(NULL);         
    struct tm *t = localtime(&now);

    // file name
    char file_name[30];
    sprintf(file_name, "logs/log%02d%02d%02d%02d.txt\0", 
        t->tm_mon + 1,  //month
        t->tm_mday,     //day
        t->tm_hour,     //hour
        t->tm_min,      //min
        t->tm_sec);     //sec

    // open file
    logFile = fopen(file_name, "at");
}

void logPrint(char * message,...) {
    va_list args;
    va_start(args, message);
    vfprintf(logFile, message, args);
    va_end(args);
}

void logClose() {
    fclose(logFile);
}

void logPrintLevelActive() {

    logPrint("level_active : \nTiles :\n");

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {
            logPrint("%c", level_active.tiles[i][j]);
        }
        logPrint("\n");
    }
    logPrint("Objects :\n");

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {
            logPrint("%c", level_active.objects[i][j]);
        }
        logPrint("\n");
    }
    logPrint("Darkness :\n");

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {
            logPrint("%d", level_active.darkness[i][j]);
        }
        logPrint("\n");
    }
    logPrint("\n");
}