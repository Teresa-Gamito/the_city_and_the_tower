
#define MAX_INPUT_LENGHT 255

#ifndef TOOLS_H
#define TOOLS_H


char * getInput();

void delay(int miliseconds);
void printSpace();

void layerCopy(char * layer_to_copy, char * layer_destiny, int max_width, int max_height);
double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y); // get distance btwwen two points


#endif