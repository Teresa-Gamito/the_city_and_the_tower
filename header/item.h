
#include <stdbool.h>

#ifndef ITEM_H
#define ITEM_H

bool itemCanBePickedUp(int pos_x, int pos_y);
bool itemCanBeDropped(int pos_x, int pos_y, char item);

void itemPickUp(int pos_x, int pos_y);
void itemDrop(int pos_x, int pos_y);

#endif