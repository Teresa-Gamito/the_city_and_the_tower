
#include "../header/tools.h"

void layerCopy(char * layer_source, char * layer_destiny, int max_width, int max_height) {

    memcpy(layer_destiny, layer_source, sizeof(char) * max_height * max_width);

}

double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y) {

    return sqrt(pow(abs(pos1_x - pos2_x), 2) + pow(abs(pos1_y - pos2_y), 2));

}