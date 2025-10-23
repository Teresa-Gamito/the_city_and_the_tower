#include <stdio.h>
#include <stdbool.h>
#include "level.h"

/*  ===== Labels =====
'W' - Wall
'P' - Pit
'0' - Empty
'R' - Relic
'T' - Torch
'P' - Player 
*/





// ===== This zone is mine - no touch =====

// this is not optimized because right now its focused on getting the most ample results
// should optimize to fscanf and make more legible
// should separatee in different functions
Level getLevelFromFile(int level_num) {

    FILE *file;
    Level level = {{{0}}, {{0}}, {{0}}};

    char temp_level[MAX_HIGHT][MAX_WIDTH];

    // ===== File =====
    // get file name - naming convention is "lvlXX" (maximum of 100 levels) 
    char file_name[4 + MAX_NUM_OF_DIGITS_FOR_LEVEL_NAME] = "lvl00\0";
    file_name[4] = (level_num % 10) + '0';
    file_name[3] = (level_num / 10) + '0';

    // open file - reading in text format
    file = fopen(file_name, "rt");

    // throw error if file cant be opened
    if(!file) perror("Error opening file!");


    // =====layer holder =====
    char c; // temp char holder
    for (int k = 0; k < 3; k++) {

        // Create temp_level with current layer
        for (int i = 0; i < MAX_HIGHT; i++) {
            for (int j = 0; j < MAX_WIDTH + 1; j++) {

                c = fgetc(file);
            
                if (c == '\n') { // if its the end of the line
                    break;
                }
                else if (c == '-') { // if its the end of the layer
                    c = fgetc(file);
                    goto break2; // break twice
                }
                else temp_level[i][j] = c;
            }
        }

        break2:

        

        switch (k) {
        case 0: // set the tiles layer
            for (int i = 0; i < MAX_HIGHT; i++) {
                for (int j = 0; j < MAX_WIDTH; j++) {
                    level.tiles[i][j] = temp_level[i][j];
                }
            }
            break;

        case 1: // set the items layer
            for (int i = 0; i < MAX_HIGHT; i++) {
                for (int j = 0; j < MAX_WIDTH; j++) {
                    level.objects[i][j] = temp_level[i][j];
                }
            }
            break;

        case 2: // set the darkness layer
            for (int i = 0; i < MAX_HIGHT; i++) {
                for (int j = 0; j < MAX_WIDTH; j++) {
                    level.darkness[i][j] = temp_level[i][j] - '0';
                }
            }
            break;
        }
    }
    fclose(file);
    return level;
}