#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "player.h"
#include "draw.h"
#include "debug.h"

char getInput();

void actionFromInput(char input);

int main() {
    logOpen(); // creates the log file and opens it
    logPrint("Game start\n\n");
    //drawStartMenu(getInput());
    
    levelActiveSetFromFile(1);
    playerSpawn();

    while(1) {

        drawLevel();

        actionFromInput(getInput());
        

        
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
    
    return 0;

}

char getInput() {
    char input;
    scanf(" %c", &input);
    return input;
}

void actionFromInput(char input) {

    if (highlight.is_on) {
        highlightAction(input);
    }
    else {
        playerAction(input);
    }
    
}