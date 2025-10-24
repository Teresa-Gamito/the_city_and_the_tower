#include <stdio.h>
#include <stdbool.h>
#include "level.h"

char * getLevelFileName(int level_num) {
    // get file name - naming convention is "lvlXX" (maximum of 100 levels) 
    static char file_name[LEVEL_FILE_NAME_SIZE] = LEVEL_FILE_NAME;
    file_name[4] = (level_num % 10) + '0';
    file_name[3] = (level_num / 10) + '0';
    return file_name;
}

Level getLevelFromFile(int level_num) {

    // open file - reading in text format
    FILE *file;
    file = fopen(getLevelFileName(level_num), "rt");
    // throw error if file cant be opened
    if(!file) perror("Error opening file!");


    Level level = {MAX_WIDTH, MAX_HIGHT, {{0}}, {{0}}, {{0}}};
    char temp_layer[MAX_HIGHT][MAX_WIDTH]; // temp layer
    char c; // temp char holder
    
    
    for (int k = 0; k < 3; k++) { // iterate for each layer

        // Create temp_layer with current layer
        for (int i = 0; i < level.height; i++) { // iterate for each row
            for (int j = 0; j < level.width + 1; j++) { // iterate for each column

                c = fgetc(file);
            
                if (c == '\n') { // if its the end of the line
                    if (k == 0 && i == 0) level.width = j; // get the width of the first row
                    break;
                }
                else if (c == '-' || c == EOF) { // if its the end of the layer or end of file
                    if (k == 0) level.height = i; // get the hight of thee first column
                    fgetc(file); // skip the '\n' that comes after '-'
                    goto break2; // break twice
                }
                else temp_layer[i][j] = c;
            }
        }

        break2:

        for (int i = 0; i < level.height; i++) {
            for (int j = 0; j < level.width; j++) {

                switch (k) {
                    
                    case 0: // set the tiles layer
                    level.tiles[i][j] = temp_layer[i][j];
                    break;

                    case 1: // set the items layer
                    level.objects[i][j] = temp_layer[i][j];
                    break;

                    case 2: // set the darkness layer
                    level.darkness[i][j] = temp_layer[i][j] - '0';
                    break;
                }
            }
        }
    }

    fclose(file);
    return level;
}

// only for testing
void testLevelPrint(Level level) {
    for (int i = 0; i < level.height; i++) {
        for (int j = 0; j < level.width; j++) {
            printf("%c", level.tiles[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < level.height; i++) {
        for (int j = 0; j < level.width; j++) {
            printf("%c", level.objects[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < level.height; i++) {
        for (int j = 0; j < level.width; j++) {
            printf("%d", level.darkness[i][j]);
        }
        printf("\n");
    }
}

int main() { // testing

    Level level = getLevelFromFile(1);
    testLevelPrint(level);
    
    return 0;
}