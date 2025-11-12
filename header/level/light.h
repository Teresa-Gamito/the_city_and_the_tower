
#include <stdbool.h>

#define LIGHT_RADIUS_TORCH 3.17
#define LIGHT_RADIUS_WALL_TORCH 3.17

#ifndef LIGHT_H
#define LIGHT_H

void lightReset(); // resets light to starting values
void lightPorcessLayers(); // find light emitting tiles and process the light coming from them
void lightProcess(int pos_x, int pos_y, double light_radius); // from a light source, set the surrounding tiles as lit
bool lightHasCollision(int pos_source_x, int pos_source_y, int pos_final_x, int pos_final_y);

#endif