
// ========================================
// contains functions that have more general uses
// ========================================

#pragma once

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "debug.h"

#define MAX_INPUT_LENGHT 255

#ifndef TOOLS_H
#define TOOLS_H

char * getInput(); // gets input from the player

void delay(int miliseconds); // creates a delay
void clear(); // separates each printing instance

void layerCopy(char * layer_to_copy, char * layer_destiny, int max_width, int max_height); // copies one 2D matrix to another

double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y); // get distance btwwen two points

#endif