#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "player.h"
#include "items.h"
#include "draw.h"
#include "debug.h"

char getInput();

int main() {
    char c;
    logOpen(); // creates the log file and opens it
    printf("Hello Wizard! 🧙‍♂️\n");
    //drawStartMenu(getInput());

    setLevelFromFile(1);
    playerSpawn();

    while(1) {
        drawLevel();
        c = getInput();
        playerMoveDirection(c);
        playerAction(c);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    
    return 0;

}

char getInput() {
    char input;
    scanf(" %c", &input);
    return input;
}