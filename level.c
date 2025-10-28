#include <stdio.h>
#include <stdbool.h>
#include "level.h"

Level level_active = {MAX_WIDTH, MAX_HEIGHT, {{0}}, {{0}}, {{0}}};

char * getLevelFileName(int level_num) {
    // get file name - naming convention is "lvlXX" (maximum of 100 levels) 
    static char file_name[] = LEVEL_FILE_NAME;
    file_name[4] = (level_num % 10) + '0';
    file_name[3] = (level_num / 10) + '0';
    return file_name;
}

void getLevelFromFile(int level_num) {

    // open file - reading in text format
    FILE *file;
    file = fopen(getLevelFileName(level_num), "rt");
    // throw error if file cant be opened
    if(!file) perror("Error opening file!");


    char temp_layer[MAX_HEIGHT][MAX_WIDTH]; // temp layer
    char c; // temp char holder
    
    
    for (int k = 0; k < 3; k++) { // iterate for each layer

        // Create temp_layer with current layer
        for (int i = 0; i < level_active.height + 1; i++) { // iterate for each row
            for (int j = 0; j < level_active.width + 1; j++) { // iterate for each column

                c = fgetc(file);
            
                if (c == '\n') { // if its the end of the line
                    if (k == 0 && i == 0) level_active.width = j; // get the width of the first row
                    break;
                }
                else if (c == '-' || c == EOF) { // if its the end of the layer or end of file
                    if (k == 0) level_active.height = i; // get the height of thee first column
                    fgetc(file); // skip the '\n' that comes after '-'
                    goto break2; // break twice
                }
                else temp_layer[i][j] = c;
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
                    break;
                }
            }
        }
    }

    fclose(file);
}

bool tileIsWalkable(int pos_x, int pos_y) {

    return level_active.tiles[pos_y][pos_x] != 'W' && level_active.tiles[pos_y][pos_x] != 'P';
}