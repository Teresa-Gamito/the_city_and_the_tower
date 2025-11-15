
// ========================================
// Light related functions
// processes the lighing system
// ========================================

#include <stdbool.h>

// default light radius
#define LIGHT_RADIUS_TORCH 4.5
#define LIGHT_RADIUS_WALL_TORCH 4.5

#ifndef LIGHT_H
#define LIGHT_H

void lightReset(); // resets light to starting values
void lightPorcessLayers(); // find light emitting tiles and process the light coming from them
void lightProcess(int pos_x, int pos_y, double light_radius); // from a light source, set the surrounding tiles as lit
bool lightHasCollision(int pos_source_x, int pos_source_y, int pos_final_x, int pos_final_y); // checks if the path of a light ray colides with a light blocking tile

#endif