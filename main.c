#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "player.h"
#include "items.h"
#include "draw.h"
#include "debug.h"

char getInput();
void logPrint(char * message);

int main() {

    getLevelFromFile(1);
    playerSpawn();

    while(1) {
        drawLevel();
        playerMoveDirection(getInput());
    }
    return 0;

}

char getInput() {
    char input;
    scanf(" %c", &input);
    return input;
}