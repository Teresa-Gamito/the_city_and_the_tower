
#include "../../../header/level/objects/item.h"


bool itemCanBePickedUp(int pos_x, int pos_y) {

    if (level_active.light[pos_y][pos_x] == CHAR_LIT) {

        if (tileHasItem(pos_x, pos_y)) return 1;

        else if (level_active.tiles[pos_y][pos_x] == CHAR_PLANK_TILE && !(player.pos_x == pos_x && player.pos_y == pos_y)) return 1;
    
    }
    return 0;
}

void itemPickUp(int pos_x, int pos_y) {

    if (itemCanBePickedUp(pos_x, pos_y)) {

        if (level_active.tiles[pos_y][pos_x] == CHAR_PLANK_TILE)
            pickUpPlank(pos_x, pos_y);

        else if (tileHasItem(pos_x, pos_y)) 
            pickUpDefault(pos_x, pos_y);

        if (player.item == CHAR_RELIC) 
            pickUpRelicTrigger();

        logPrint("Picked up item: %c\n", player.item);

    }

}


void pickUpDefault(int pos_x, int pos_y) {

    player.item = level_active.objects[pos_y][pos_x];
    level_active.objects[pos_y][pos_x] = CHAR_EMPTY;

}

void pickUpPlank(int pos_x, int pos_y) {

    player.item = CHAR_PLANK;
    level_active.tiles[pos_y][pos_x] = CHAR_PIT;

}

void pickUpRelicTrigger() {

    if (level_active.phase_num == 1) {

        level_active.relic_was_picked_up = 1;

        levelTriggerNextPhase();

    }
}



bool itemCanBeDropped(int pos_x, int pos_y) {

    if (level_active.light[pos_y][pos_x] == CHAR_LIT) {

        if (level_active.tiles[pos_y][pos_x] == CHAR_GROUND && !tileHasItem(pos_x, pos_y)) return 1;

        else if (level_active.tiles[pos_y][pos_x] == CHAR_WALL_TORCH_UNLIT && player.item == CHAR_TORCH) return 1;

        else if (level_active.tiles[pos_y][pos_x] == CHAR_PIT && player.item == CHAR_PLANK) return 1;

        else return 0;

    }

    return 0;
}

void itemDrop(int pos_x, int pos_y) {

    logPrint("Dropped item: %c\n", player.item);

    switch (player.item) {

        case CHAR_PLANK:
            dropPlank(pos_x, pos_y);
            break;

        case CHAR_TORCH:
            dropTorch(pos_x, pos_y);
            break;
        
        default:
            dropDefault(pos_x, pos_y);
            break;

    }
}


void dropPlank(int pos_x, int pos_y) {

    if (itemCanBeDropped(pos_x, pos_y)) {

        if (tileGetType(pos_x, pos_y) == CHAR_PIT) level_active.tiles[pos_y][pos_x] = CHAR_PLANK_TILE;

        else level_active.objects[pos_y][pos_x] = player.item;
        
        player.item = CHAR_EMPTY;
    }

}

void dropTorch(int pos_x, int pos_y) {

    if (itemCanBeDropped(pos_x, pos_y)) {

        if (tileGetType(pos_x, pos_y) == CHAR_WALL_TORCH_UNLIT) {

            wallTorchSetLit(pos_x, pos_y);

        }
        else {
        
            level_active.objects[pos_y][pos_x] = player.item;
            player.item = CHAR_EMPTY;
        
        }
    }
}

void dropDefault(int pos_x, int pos_y) {

    if (itemCanBeDropped(pos_x, pos_y)) {

        level_active.objects[pos_y][pos_x] = player.item;
        player.item = CHAR_EMPTY;

    }

}