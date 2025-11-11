#include <stdio.h>
#include <stdbool.h>

#include "../header/level.h"
#include "../header/player.h"
#include "../header/draw.h"
#include "../header/debug.h"
#include "../header/item.h"
#include "../header/highlight.h"
#include "../header/light.h"
#include "../header/item.h"

char getInput();
void actionFromInput(char input);

void printSpace();

int main() {

    logOpen();
    logPrint("Game start\n\n");

    int level_num, phase_num;

    scanf(" %d %d", &level_num, &phase_num);

    // temp
    phase_num == 1 ? levelLoad(level_num, phase_num, 0, 0, '0') : levelLoad(level_num, phase_num, 0, 0, 'R');

    while(1) {

        drawLevel();

        actionFromInput(getInput());
        
        printSpace();
    }
    
    return 0;

}

char getInput() {

    char input;
    scanf(" %c", &input);
    return input;

}

void printSpace() {

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}


void actionFromInput(char input) {

    if (highlight.is_on) {
        highlightAction(input);
    }
    else {
        playerAction(input);
    }
    
}