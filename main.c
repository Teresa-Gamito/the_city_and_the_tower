#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "player.h"
#include "items.h"
#include "draw.h"

char getInput();

int main() {

    getLevelFromFile(1);
    playerSpawn();


    while(1) {

        drawLevel();
        playerMoveDirection(getInput());
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    return 0;
}

char getInput() {
    char input;
    scanf(" %c", &input);
    return input;
}