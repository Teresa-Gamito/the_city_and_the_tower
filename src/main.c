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

#define MAX_INPUT_LENGHT 255

char * getInput();
void actionFromInput(char * input);

void printSpace();

int main() {

    logOpen();
    logPrint("Game start\n\n");


    int level_num, phase_num;

    scanf(" %d %d", &level_num, &phase_num);

    // temp
    phase_num == 1 ? levelLoad(level_num, phase_num, -1, -1, 0) : levelLoad(level_num, phase_num, 0, 0, 'R');

    while(1) {

        drawLevel();

        actionFromInput(getInput());
        
        printSpace();
    }
    
    return 0;

}

char * getInput() {

    static char input[MAX_INPUT_LENGHT];
    scanf("%s", input);
    return input;

}

void printSpace() {

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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