
#include "../header/tools.h"

char * getInput() {

    static char input[MAX_INPUT_LENGHT];
    scanf("%s", input);
    return input;

}

void clear() {

    if (debug_screen_clear) system("cls");
    else printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}


void delay(int miliseconds) {

    clock_t start_time = clock();

    while (clock() < start_time + miliseconds);

}


void layerCopy(char * layer_source, char * layer_destiny, int max_width, int max_height) {

    memcpy(layer_destiny, layer_source, sizeof(char) * max_height * max_width);

}

double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y) {

    return sqrt(pow(abs(pos1_x - pos2_x), 2) + pow(abs(pos1_y - pos2_y), 2));

}