#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "../../header/level/level.h"
#include "../../header/debug.h"
#include "../../header/level/objects/player.h"
#include "../../header/tools.h"
#include "../../header/level/light.h"
#include "../../header/draw/draw.h"
#include "../../header/draw/menu.h"


Level level_active = {MAX_WIDTH, MAX_HEIGHT, {{0}}, {{0}}, {{0}}, 0, 0, 0, 0, 0};


char * levelFileGetName(int level_num, int phase_num) {

    static char file_name[17];
    sprintf(file_name, LEVEL_FILE_NAME, level_num, phase_num);
    return file_name;

}

FILE * levelFileOpen(int level_num, int phase_num) {

    char * file_name;
    FILE * level_file;

    file_name = levelFileGetName(level_num, phase_num);
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
            else if (temp_char == CHAR_LAYER_TRANSITION || temp_char == EOF) {
                fgetc(level_file);
                return;
            }
            else layer[i][j] = temp_char;
        }
    }
}

void levelActiveSetFromFile(int level_num, int phase_num) {

    level_active.width = levelFileGetWidth(level_num, phase_num);

    level_active.height = levelFileGetHight(level_num, phase_num);


    level_active.level_num = level_num;
    level_active.phase_num = phase_num;

    if (level_active.phase_num == 1) level_active.relic_was_picked_up = 0;
    else level_active.relic_was_picked_up = 1;

    FILE *level_file;
    level_file = levelFileOpen(level_num, phase_num);

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


void levelLoad(int level_num, int phase_num, int player_pos_x, int player_pos_y, char item) {

    logPrint("Loading level\n");

    levelActiveSetFromFile(level_num, phase_num);
    playerSpawn(player_pos_x, player_pos_y, item);


}

void levelTriggerNextPhase() {

    logPrint("Triggered next phase\n");

    if (level_active.phase_num == MAX_PHASES);
    
    else {
        levelTransitionAction();
        levelLoadNextPhase();
    }

}

void levelLoadNextPhase() {

    logPrint("Loaded next phase");

    levelLoad(level_active.level_num, level_active.phase_num + 1, player.pos_x, player.pos_y, player.item);

}

void levelGoToNext() {

    logPrint("Next level\n");

    levelLoad(level_active.level_num + 1, 1, PLAYER_SPAWN_FROM_FILE, PLAYER_SPAWN_FROM_FILE, CHAR_EMPTY);

}

void levelExit() {

    logPrint("level exited\n");

    level_active.level_exit = true;
    
}

void levelWin() {

    logPrint("level Won\n");
    
    level_active.level_won = true;
    menuTravelWin();

}

void levelRestart() {

    logPrint("level restarted\n");

    levelLoad(level_active.level_num, 1, PLAYER_SPAWN_FROM_FILE, PLAYER_SPAWN_FROM_FILE, CHAR_EMPTY);

}


void levelTransitionAction() {

    logPrint("level transition action\n");

    for (int j = 0; j < level_active.width; j++) {
        for (int i = 0; i < level_active.height; i++) {

            if (tileGetType(j,i) == CHAR_WALL_TORCH_LIT) {
                
                level_active.tiles[i][j] = CHAR_WALL_TORCH_UNLIT;
                drawLevel();
                delay(DELAY_WALL_TORCH_ERASE);

            }
        }
    }
}


int levelFileGetWidth(int level_num, int phase_num) {

    FILE * level_file;
    level_file = levelFileOpen(level_num, phase_num);

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

int levelFileGetHight(int level_num, int phase_num) {

    FILE * level_file;
    level_file = levelFileOpen(level_num, phase_num);

    char temp_char[MAX_WIDTH + 1];
    int height;

    for (int i = 0; i < MAX_HEIGHT + 1; i++)  {

        fgets(temp_char, MAX_WIDTH * 2, level_file);

        if (temp_char[0] == CHAR_LAYER_TRANSITION) {
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

    return level_active.objects[pos_y][pos_x] != CHAR_EMPTY || 
        level_active.tiles[pos_x][pos_y] == CHAR_PLANK_TILE;
}

bool tileBlocksLight(int pos_x, int pos_y) {

    return level_active.tiles[pos_y][pos_x] == CHAR_WALL;

}

bool tileCanHaveItem(int pos_x, int pos_y, char item) {

    if (level_active.light[pos_y][pos_y] == CHAR_UNLIT) return 0;

    if (level_active.tiles[pos_y][pos_x] == CHAR_PIT) {

        if (item == CHAR_PLANK) return 1;

    }
    else if (level_active.tiles[pos_y][pos_x] == CHAR_GROUND) return 1;

    return 0;
}

char tileGetType(int pos_x, int pos_y) {

    return level_active.tiles[pos_y][pos_x];

}


void wallTorchSetLit(int pos_x, int pos_y) {

    logPrint("Wall torch set unlit at: x:%d, y%d\n", pos_x, pos_y);
    
    level_active.tiles[pos_y][pos_x] = CHAR_WALL_TORCH_LIT; 

}

void wallTorchSetUnlit(int pos_x, int pos_y) {

    logPrint("Wall torch set lit at: x:%d, y%d\n", pos_x, pos_y);

    level_active.tiles[pos_y][pos_x] = CHAR_WALL_TORCH_UNLIT; 

}






