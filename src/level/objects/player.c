
#include <stdio.h>
#include <stdbool.h>

#include "../../../header/level/objects/player.h"
#include "../../../header/level/level.h"
#include "../../../header/level/objects/item.h"
#include "../../../header/level/highlight.h"
#include  "../../../header/draw/menu.h"
#include  "../../../header/debug.h"

Player player = {0, 0, '0'};


void playerSpawn(int pos_x, int pos_y, char item) {

    if (item != PLAYER_NO_ITEM) player.item = item;

    for(int i = 0 ; i < level_active.width ; i++) {

        for(int j = 0 ; j < level_active.height ; j++) {

            if(level_active.objects[i][j] == CHAR_PLAYER) {

                if (pos_x == PLAYER_SPAWN_FROM_FILE) player.pos_x = j;
                if (pos_y == PLAYER_SPAWN_FROM_FILE) player.pos_y = i;

                level_active.objects[i][j] = CHAR_EMPTY;
                
                return;
            }
        }
    }

    logPrint("Player Spawned\n");


    highlight.pos_x = player.pos_x;
    highlight.pos_y = player.pos_y;

}

void playerAction(char dir) {

    switch(dir) {

        case 'w':
        case 'W':
            if(tileIsWalkable(player.pos_x, player.pos_y - 1) || debug_phase_through_walls)
            playerMove(player.pos_x, player.pos_y - 1);
            break;

        case 's':
        case 'S':
            if(tileIsWalkable(player.pos_x, player.pos_y + 1) || debug_phase_through_walls)
                playerMove(player.pos_x, player.pos_y + 1);
            break;

        case 'a':
        case 'A':
            if(tileIsWalkable(player.pos_x - 1, player.pos_y) || debug_phase_through_walls)
                playerMove(player.pos_x - 1, player.pos_y);
            break;

        case 'd':
        case 'D':
            if(tileIsWalkable(player.pos_x + 1, player.pos_y) || debug_phase_through_walls)
                playerMove(player.pos_x + 1, player.pos_y);
            break;

        case 'Z':
        case 'z':
            highlightSpawn();
            break;

        case 'P':
        case 'p':
            menuTravelPause();
            break;
        
    }
}

void playerMove(int pos_x, int pos_y) {

    player.pos_x = pos_x;
    player.pos_y = pos_y;

    logPrint("Player move: x:%d, y%d\n", pos_x, pos_y);
    
    
    if (player.item == CHAR_RELIC && tileGetType(player.pos_x, player.pos_y) == CHAR_EXIT) 
        levelWin();

}

bool playerHasItem() {

    return player.item != CHAR_EMPTY;

}