#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "player.h"
#include "items.h"
#include "draw.h"
#include "debug.h"

char getInput();

int main() {
    logOpen(); // creates the log file and opens it

    //drawStartMenu(getInput());

    setLevelFromFile(1);
    
    playerSpawn();

    while(1) {
        drawLevel();
        playerMoveDirection(getInput());
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    
    return 0;

}

char getInput() {
    char input;
    scanf(" %c", &input);
    return input;
}