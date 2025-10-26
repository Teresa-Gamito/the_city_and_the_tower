#include <stdio.h>
#include <stdbool.h>

#include "level.h"
#include "draw.h"
#include "player.h"
#include "items.h"

char getInput();

int main() {

    while(1) {
        
        playerMoveDirection(getInput());

    }
    return 0;
}

char getInput() {
    char input;
    scanf("%c", &input);
    return input;
}