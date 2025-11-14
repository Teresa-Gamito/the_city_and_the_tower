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


#define LEVEL_EXIT_CODE_MAIN_MENU 0
#define LEVEL_EXIT_CODE_WIN_MENU 1


void actionFromInput(char * input);

void goToMainMenu();
void goToPauseMenu();
void goToMenuWin();
void gotoLevel(int level_num);

bool runLevel();



int main() {

    //-----
    logOpen();
    logPrint("Game start\n\n");
    //-----

    goToMainMenu();


    return 0;
}

void goToMainMenu() {

    int level_to_load;

    while (true) {

        menuTravelMain(&level_to_load);

        gotoLevel(level_to_load);
    }


}

void gotoLevel(int level_num) {

    levelLoad(level_num, 1, PLAYER_SPAWN_FROM_FILE, PLAYER_SPAWN_FROM_FILE, CHAR_EMPTY);

    while (runLevel());

}


bool runLevel() {

    drawLevel();

    actionFromInput(getInput());

    return !level_active.level_exit;

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