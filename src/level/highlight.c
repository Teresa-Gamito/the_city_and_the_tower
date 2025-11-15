
#include <stdio.h>
#include <stdbool.h>

#include "../../header/level/highlight.h"
#include "../../header/level/objects/player.h"
#include "../../header/level/objects/item.h"
#include "../../header/draw/draw.h"
#include "../../header/level/level.h"
#include "../../header/debug.h"


Highlight highlight = {0, 0, 0};

void highlightSpawn() {

    highlight.pos_x = player.pos_x;
    highlight.pos_y = player.pos_y;
    highlight.is_on = 1;

    logPrint("Spawned highlight\n");

}

void highlightDespawn() {

    highlight.is_on = 0;
    
    logPrint("Despawned highlight\n");

}

void highlightMove(int pos_x, int pos_y) {

    highlight.pos_x = pos_x;
    highlight.pos_y = pos_y;

}

void highlightAction(char input) {

    logPrint("Highlight action: key %c\n", input);

    switch (input) {
        case 'w':
        case 'W':
            highlightMove(player.pos_x, player.pos_y - 1);
        break;

        case 's':
        case 'S':
            highlightMove(player.pos_x, player.pos_y + 1);
        break;

        case 'a':
        case 'A':
            highlightMove(player.pos_x - 1, player.pos_y);
        break;

        case 'd':
        case 'D':
            highlightMove(player.pos_x + 1, player.pos_y);
        break;

        case 'z':
        case 'Z':
            if (!playerHasItem()) itemPickUp(highlight.pos_x, highlight.pos_y);
            else itemDrop(highlight.pos_x, highlight.pos_y);
            highlightDespawn();
        break;
    }
}

