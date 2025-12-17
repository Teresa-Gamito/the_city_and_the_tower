
// ==============================
// Item related funcitons
// ==============================

#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "../level.h"
#include "../../draw/audio.h"
#include "../../debug.h"
#include "player.h"

#ifndef ITEM_H
#define ITEM_H


// Pick up items
bool itemCanBePickedUp(int pos_x, int pos_y); // checks if an item can be picked up

void itemPickUp(int pos_x, int pos_y); // picks up an item
// specific items
void pickUpPlank(int pos_x, int pos_y); // pick up plank from ground or plank tile
void pickUpDefault(int pos_x, int pos_y); // other items
void pickUpRelicTrigger(); // trigger pahse change


// Drop items
bool itemCanBeDropped(int pos_x, int pos_y); // checks if an item can be dropped

void itemDrop(int pos_x, int pos_y); // drops an item
// specific items
void dropPlank(int pos_x, int pos_y); // drop plank or create plank tile
void dropTorch(int pos_x, int pos_y); // drop torch or activate wall torch
void dropDefault(int pos_x, int pos_y); // other items


#endif