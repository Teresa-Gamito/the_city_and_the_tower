#include <stdio.h>
#include <stdbool.h>

#include "../header/objects/item.h"
#include "../header/level/level.h"
#include "../header/objects/player.h"


bool itemCanBePickedUp(int pos_x, int pos_y) {

    if (level_active.light[pos_y][pos_x] == CHAR_LIT) {

        if (tileHasItem(pos_x, pos_y)) return 1;

        else if (level_active.tiles[pos_y][pos_x] == CHAR_PLANK_TILE) return 1;
    
    }
    return 0;
}

bool itemCanBeDropped(int pos_x, int pos_y, char item) {

    if (level_active.light[pos_y][pos_x] == CHAR_LIT) {

        if (level_active.tiles[pos_y][pos_x] == CHAR_GROUND && !tileHasItem(pos_x, pos_y)) return 1;

        else if (level_active.tiles[pos_y][pos_x] == CHAR_WALL_TORCH_UNLIT && item == CHAR_TORCH) return 1;

        else if (level_active.tiles[pos_y][pos_x] == CHAR_PIT && item == CHAR_PLANK) return 1;

        else return 0;

    }

    return 0;
}


void itemPickUp(int pos_x, int pos_y) {

    if (itemCanBePickedUp(pos_x, pos_y)) {

        if (level_active.tiles[pos_y][pos_x] == CHAR_PLANK_TILE) {

            player.item = CHAR_PLANK;
            level_active.tiles[pos_y][pos_x] = CHAR_PIT;

        }

        else if (tileHasItem(pos_x, pos_y)) {

            player.item = level_active.objects[pos_y][pos_x];
            level_active.objects[pos_y][pos_x] = CHAR_EMPTY;

        }

        if (player.item == CHAR_RELIC) {
            levelTriggerNextPhase();
            level_active.relic_was_picked_up = 1;

        }
    }
}

void itemDrop(int pos_x, int pos_y) {

    if (itemCanBeDropped(pos_x, pos_y, player.item)) {

        if (player.item == CHAR_PLANK && level_active.tiles[pos_y][pos_x] == CHAR_PIT) {

            level_active.tiles[pos_y][pos_x] = CHAR_PLANK_TILE;
            player.item = CHAR_EMPTY;

        }

        else if (tileGetType(pos_x, pos_y) == CHAR_WALL_TORCH_UNLIT && player.item == CHAR_TORCH) {

            wallTorchSetLit(pos_x, pos_y);

        }

        else {

            level_active.objects[pos_y][pos_x] = player.item;
            player.item = CHAR_EMPTY;
        
        }

    }
}
