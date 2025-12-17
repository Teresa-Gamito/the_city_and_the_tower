
// ==============================
// Player related functions
// ==============================

#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "item.h"
#include "../level.h"
#include "../highlight.h"
#include "../../draw/menu.h"
#include "../../draw/audio.h"
#include "../../debug.h"


// player spawning

#define PLAYER_SPAWN_FROM_FILE -1
#define PLAYER_NO_ITEM '0'


// player sprite info

#define PLAYER_SPRITE_DIRECTION_LEFT 0
#define PLAYER_SPRITE_DIRECTION_RIGHT 1


// player sprites

#define PLAYER_SPRITE_ITEM_NONE 0
#define PLAYER_SPRITE_ITEM_TORCH 1
#define PLAYER_SPRITE_ITEM_PLANK 2
#define PLAYER_SPRITE_ITEM_RELIC 3


// player movement

#define PLAYER_MOVE_UP      0
#define PLAYER_MOVE_DOWN    1
#define PLAYER_MOVE_LEFT    2
#define PLAYER_MOVE_RIGHT   3


#ifndef PLAYER_H
#define PLAYER_H


// define the player as an object
typedef struct Player {
    
    int pos_x;      // player x position
    int pos_y;      // player y position
    char item;      // player held item
    bool sprite_direction;  // player direction ()

} Player;

// global player
extern Player player;

// spawns the player into the level
void playerSpawn(int pos_x, int pos_y, char item); 

// move the player
void playerMove(int pos_x, int pos_y); 
// execute actions related to the player with given input
void playerAction(int input); 

// return true if the player has an item
bool playerHasItem(); 

#endif