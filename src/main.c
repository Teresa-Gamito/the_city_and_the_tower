#include <stdio.h>
#include <stdbool.h>

#include "../header/level/level.h"
#include "../header/objects/player.h"
#include "../header/level/draw.h"
#include "../header/debug.h"
#include "../header/level/highlight.h"
#include "../header/level/light.h"
#include "../header/objects/item.h"
#include "../header/tools.h"
#include "../header/level/menu.h"


void actionFromInput(char * input);


int main() {

    logOpen();
    logPrint("Game start\n\n");

    int level_to_load;


    menuTravel(&level_to_load);
    levelLoad(level_to_load, 1, PLAYER_SPAWN_FROM_FILE, PLAYER_SPAWN_FROM_FILE, CHAR_TORCH);

    while(1) {

        drawLevel();

        actionFromInput(getInput());
    
    }
    
    return 0;

}


void actionFromInput(char * input) {

    if (input[1] == '\0') {
        if (highlight.is_on) {
            highlightAction(input[0]);
        }
        else {
            playerAction(input[0]);
        }
    }
    else debugCommand(input);
    
}