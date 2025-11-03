#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "level.h"
#include "debug.h"
#include "player.h"


Level level_active = {MAX_WIDTH, MAX_HEIGHT, {{0}}, {{0}}, {{0}}};


char * levelFileGetName(int level_num) {

    static char file_name[17];
    sprintf(file_name, LEVEL_FILE_NAME, level_num);
    return file_name;

}

FILE * levelFileOpen(int level_num) {

    char * file_name;
    FILE * level_file;

    file_name = levelFileGetName(level_num);
    level_file = fopen(file_name, "rt");

    if (!level_file) logPrint("Could not opeen file %s\n", file_name);
    else logPrint("Opened file %s\n", file_name);

    return level_file;

}

void levelFileClose(FILE * level_file) {

    fclose(level_file);
    logPrint("Closed file\n");

}


void levelFileGetLayerNext(FILE * level_file, char layer[MAX_HEIGHT][MAX_WIDTH]) {

    logPrint("Getting next layer\n");

    char temp_char;

    for (int i = 0; i < level_active.height + 1; i++) {
        for (int j = 0; j < level_active.width + 1; j++) {

            temp_char = fgetc(level_file);
        
            if (temp_char == '\n') {
                break;
            }
            else if (temp_char == '-' || temp_char == EOF) {
                fgetc(level_file);
                return;
            }
            else layer[i][j] = temp_char;
        }
    }
}

void levelActiveSetFromFile(int level_num) {

    level_active.width = levelFileGetWidth(level_num);
    level_active.height = levelFileGetHight(level_num);

    FILE *level_file;
    level_file = levelFileOpen(level_num);

    char temp_layer[MAX_HEIGHT][MAX_WIDTH];

    for (int k = 0; k < MAX_LAYERS; k++) {

        levelFileGetLayerNext(level_file, temp_layer);

        switch (k) {
            case 0:
            layerCopy((char *)temp_layer, (char *)level_active.tiles, MAX_WIDTH, MAX_HEIGHT);
            break;

            case 1:
            layerCopy((char *)temp_layer, (char *)level_active.objects, MAX_WIDTH, MAX_HEIGHT);
            break;

            case 2:
            layerCopy((char *)temp_layer, (char *)level_active.light, MAX_WIDTH, MAX_HEIGHT);
            layerCopy((char *)level_active.light, (char *)level_active.starting_light, MAX_WIDTH, MAX_HEIGHT);
            break;
        }
    }

    logPrintLevelActive();

    levelFileClose(level_file);

}


int levelFileGetWidth(int level_num) {

    FILE * level_file;
    level_file = levelFileOpen(level_num);

    char temp_char;
    int width;

    for (int i = 0; i < MAX_WIDTH + 1; i++) {
        temp_char = fgetc(level_file);
        if (temp_char == '\n') {
            width = i;
            break;
        }
    }

    logPrint("level width: %d\n", width);
    levelFileClose(level_file);

    return width;
}

int levelFileGetHight(int level_num) {

    FILE * level_file;
    level_file = levelFileOpen(level_num);

    char temp_char[MAX_WIDTH];
    int height;

    for (int i = 0; i < MAX_HEIGHT + 1; i++)  {
        fgets(temp_char, MAX_WIDTH, level_file);
        if (temp_char[0] == '-' || temp_char[0] == EOF) {
            height = i;
            break;
        }
    }

    logPrint("level height: %d\n", height);
    levelFileClose(level_file);

    return height;
}


bool tileIsWalkable(int pos_x, int pos_y) {

    return level_active.tiles[pos_y][pos_x] != CHAR_WALL 
        && level_active.tiles[pos_y][pos_x] != CHAR_PIT 
        && level_active.light[pos_y][pos_x] != CHAR_UNLIT;

}

bool tileHasItem(int pos_x, int pos_y) {

    return level_active.objects[pos_y][pos_x] != CHAR_EMPTY;
}

bool tileBlocksLight(int pos_x, int pos_y) {
    return level_active.tiles[pos_y][pos_x] != CHAR_WALL;
}


void lightReset() {

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {

            level_active.light[i][j] = level_active.starting_light[i][j];

        }
    }

}

void lightPorcessLayers() {

    logPrint("Processing light\n");

    lightReset();
    
    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {

            if (level_active.objects[i][j] == CHAR_TORCH) {
                lightProcess(j, i, LIGHT_RADIUS_TORCH);
            }
            else if (level_active.tiles[i][j] == CHAR_WALL_TORCH) {
                lightProcess(j, i, LIGHT_RADIUS_WALL_TORCH);
            }

        }
    }
    if (player.item == ITEM_TORCH) {
        lightProcess(player.pos_x, player.pos_y, LIGHT_RADIUS_TORCH);
        logPrint("Processing player light\n");
    }
    logPrint("\n");
}

void lightProcess(int pos_x, int pos_y, double light_radius) {

    logPrint("Light source at position x:%d y:%d\n", pos_x, pos_y);

    for (int i = -light_radius; i <= light_radius; i++) {
        for (int j = -light_radius; j <= light_radius; j++) {

            if (getDistance(0, 0, j, i) <= light_radius)
                //if (!lightHasCollision(pos_x, pos_y, pos_x + i, pos_y + j))
                    level_active.light[pos_y + i][pos_x + j] = CHAR_LIT; 

        }
    }
}

bool lightHasCollision(int pos_source_x, int pos_source_y, int pos_final_x, int pos_final_y) {
    
    double distance = getDistance(pos_source_x, pos_source_y, pos_final_x, pos_final_y);
    double angle = atan2(abs(pos_final_y - pos_source_y), abs(pos_final_x - pos_source_x));

    double increment = 0.1;

    int x, y;

    printf("   %f   ", distance);


    for (double d = 0; d < distance; d += increment) {


        x = pos_source_x + roundToInt(d * cos(angle));
        printf("%f", roundToInt(d * cos(angle)));

        y = pos_source_y + roundToInt(d * sin(angle));
        //if (tileBlocksLight(x, y)) return 1;
    }
    return 0;
}


void layerCopy(char * layer_source, char * layer_destiny, int max_width, int max_height) {

    memcpy(layer_destiny, layer_source, sizeof(char) * max_height * max_width);

}

double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y) {

    return sqrt(pow(abs(pos1_x - pos2_x), 2) + pow(abs(pos1_y - pos2_y), 2));

}

int roundToInt(double x) {
    if (x - ((int) x) < 0.5) return (int) x;
    return ((int) x) + 1;

}
