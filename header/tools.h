
// ========================================
// contains functions that have more general uses
// ========================================

#define MAX_INPUT_LENGHT 255

#ifndef TOOLS_H
#define TOOLS_H


char * getInput(); // gets input from the player

void delay(int miliseconds); // creates a delay
void clear(); // separates each printing instance

void layerCopy(char * layer_to_copy, char * layer_destiny, int max_width, int max_height); // copies one 2D matrix to another

double getDistance(int pos1_x, int pos1_y, int pos2_x, int pos2_y); // get distance btwwen two points

void printImage(char * image_file_name); // prints a full text file - can be used to print ascii art

void gameExit(); // exits the game

#endif