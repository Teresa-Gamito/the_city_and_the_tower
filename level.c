#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "level.h"
#include "debug.h"
#include "player.h"

Level level_active = {MAX_WIDTH, MAX_HEIGHT, {{0}}, {{0}}, {{0}}};
bool level_active_starting_darkness[MAX_WIDTH][MAX_HEIGHT];

char * getLevelFileName(int level_num) {
    // get file name - naming convention is "lvlXX" (maximum of 100 levels) 
    static char file_name[17];
    sprintf(file_name, LEVEL_FILE_NAME, level_num);
    logPrint("%s\n", file_name);
    return file_name;
}

void setLevelFromFile(int level_num) {

    // open file - reading in text format
    FILE *file;
    file = fopen(getLevelFileName(level_num), "rt");
    // throw error if file cant be opened
    if(!file) perror("Error opening file");
    else logPrint("Opened level file\n");


    char temp_layer[MAX_HEIGHT][MAX_WIDTH]; // temp layer
    char temp_char; // temp char holder
    
    
    for (int k = 0; k < MAX_LAYERS; k++) { // iterate for each layer

        // Create temp_layer with current layer
        for (int i = 0; i < level_active.height + 1; i++) { // iterate for each row
            for (int j = 0; j < level_active.width + 1; j++) { // iterate for each column

                temp_char = fgetc(file);
            
                if (temp_char == '\n') { // if its the end of the line
                    if (k == 0 && i == 0) level_active.width = j; // get the width of the first row
                    break;
                }
                else if (temp_char == '-' || temp_char == EOF) { // if its the end of the layer or end of file
                    if (k == 0) level_active.height = i; // get the height of thee first column
                    fgetc(file); // skip the '\n' that comes after '-'
                    goto break2; // break twice
                }
                else temp_layer[i][j] = temp_char;
            }
        }

        break2:
        
        for (int i = 0; i < level_active.height; i++) {
            for (int j = 0; j < level_active.width; j++) {

                switch (k) {
                    
                    case 0: // set the tiles layer
                    level_active.tiles[i][j] = temp_layer[i][j];
                    break;

                    case 1: // set the items layer
                    level_active.objects[i][j] = temp_layer[i][j];
                    break;

                    case 2: // set the darkness layer
                    level_active.darkness[i][j] = temp_layer[i][j] - '0';
                    level_active_starting_darkness[i][j] = temp_layer[i][j] - '0';
                    break;
                }
            }
        }
    }
    logPrintLevelActive();

    fclose(file);
}

bool tileIsWalkable(int pos_x, int pos_y) {

    return level_active.tiles[pos_y][pos_x] != 'W' && level_active.tiles[pos_y][pos_x] != 'P' && level_active.darkness[pos_y][pos_x] != 0;
}

bool tileHasItem(int pos_x, int pos_y) {

    return level_active.objects[pos_y][pos_x] != '0';
}

void lightReset() {

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {

            level_active.darkness[i][j] = level_active_starting_darkness[i][j];

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

                level_active.darkness[pos_y + i][pos_x + j] = 1; 

        }
    }
}

double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y) {

    return sqrt(pow(abs(pos1_x - pos2_x), 2) + pow(abs(pos1_y - pos2_y), 2));

}