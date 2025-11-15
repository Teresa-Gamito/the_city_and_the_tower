
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

#include "../header/debug.h"
#include "../header/level/level.h"
#include "../header/level/objects/player.h"
#include "../header/tools.h"

bool debug_phase_through_walls = false;
int debug_light_buffer = 0;
bool debug_screen_clear = 1;

FILE *logFile;

void debugCommand(char * msg) {

    logPrint("DEBUG COMMAND: %s", msg);

    if (!strcmp(msg, COMMAND_RESTART)) levelRestart();

    else if (!strcmp(msg, COMMAND_NEXT_PHASE)) levelLoadNextPhase();

    else if (!strcmp(msg, COMMAND_NEXT_LEVEL)) levelGoToNext();

    else if (!strcmp(msg, COMMAND_TORCH)) level_active.objects[player.pos_y][player.pos_x] = CHAR_TORCH;

    else if (!strcmp(msg, COMMAND_RELIC)) level_active.objects[player.pos_y][player.pos_x] = CHAR_RELIC;

    else if (!strcmp(msg, COMMAND_PLANK)) level_active.objects[player.pos_y][player.pos_x] = CHAR_PLANK;
 
    else if (!strcmp(msg, COMMAND_LIGHT)) {

        char temp_arr[MAX_HEIGHT][MAX_WIDTH] = {{'1'}};

        layerCopy((char *)temp_arr, (char *)level_active.starting_light, MAX_WIDTH, MAX_HEIGHT);

    }
    
    else if (!strcmp(msg, COMMAND_PHASE))  debug_phase_through_walls = !debug_phase_through_walls;

    else if (!strcmp(msg, COMMAND_LIGHT_RADIUS_UP)) debug_light_buffer++;

    else if (!strcmp(msg, COMMAND_LIGHT_RADIUS_DOWN)) debug_light_buffer--;

    else if (!strcmp(msg, COMMAND_CLEAR_TOGGLE)) debug_screen_clear = !debug_screen_clear;

}


void logOpen() {

    // Get current time
    time_t now = time(NULL);         
    struct tm *t = localtime(&now);

    // file name
    char file_name[30];
    sprintf(file_name, LOG_NAME, 
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
    fflush(logFile);
    va_end(args);
}

void logClose() {
    fclose(logFile);
}

void logPrintLayer(char layer[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    printf("test");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            logPrint("%c", layer[i][j]);
        }
        logPrint("\n");
    }
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
            logPrint("%c", level_active.light[i][j]);
        }
        logPrint("\n");
    }
    logPrint("\n");
}