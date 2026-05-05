
#include "../header/debug.h"

bool debug_phase_through_walls = false;
int debug_light_buffer = 0;
bool debug_screen_clear = 0;

FILE *logFile = NULL;

void debugCommand(SDL_Event *event) {

    if (event->type == SDL_EVENT_KEY_DOWN) {
        switch (event->key.scancode) {
        case COMMAND_RESTART:
            levelRestart();
            break;
        case COMMAND_NEXT_PHASE:
            levelLoadNextPhase();
            break;
        case COMMAND_NEXT_LEVEL:
            levelGoToNext();
            break;
        case COMMAND_TORCH:
            level_active.objects[player.pos_y][player.pos_x] = CHAR_TORCH;
            break;
        case COMMAND_RELIC:
            level_active.objects[player.pos_y][player.pos_x] = CHAR_RELIC;
            break;
        case COMMAND_PLANK:
            level_active.objects[player.pos_y][player.pos_x] = CHAR_PLANK;
            break;
        case COMMAND_LIGHT:
            char temp_arr[MAX_HEIGHT][MAX_WIDTH] = {{'1'}};
            layerCopy((char *)temp_arr, (char *)level_active.starting_light, MAX_WIDTH, MAX_HEIGHT);
            break;
        case COMMAND_PHASE:
            debug_phase_through_walls = !debug_phase_through_walls;
            break;
        case COMMAND_LIGHT_RADIUS_UP:
            debug_light_buffer++;
            break;
        case COMMAND_LIGHT_RADIUS_DOWN:
            debug_light_buffer--;
            break;
        }
    }
}


void logOpen() {

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char file_name[30];
    sprintf(
        file_name, 
        LOG_NAME, 
        t->tm_mon + 1,
        t->tm_mday,
        t->tm_hour,
        t->tm_min,
        t->tm_sec
    );
    logFile = fopen(file_name, "at");
}

void logPrint(char * message,...) {

    if (!logFile) return;
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
