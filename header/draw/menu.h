
// ==============================
// Draw and navigate menus
// Starting screen is an image
// ==============================

#pragma once
#include <stdbool.h>

#include <SDL3/SDL.h>

#include "audio.h"
#include "../tools.h"
#include "../debug.h"
#include "../main.h"
#include "../level/level.h"


// =====screns=====

#define SCREEN_MENU 0
#define SCREEN_LEVEL 1


// =====menus=====

#define MENU_MAIN 0
#define MENU_PAUSE 1
#define MENU_WIN 2


// =====submenus=====

// main

#define SUBMENU_MAIN_STARTING_SCREEN 0
#define SUBMENU_MAIN_MAIN 1
#define SUBMENU_MAIN_LEVEL_SELECT 2
#define SUBMENU_MAIN_OPTIONS 3
#define SUBMENU_MAIN_CREDITS 4

// pause

#define SUBMENU_PAUSE_MAIN 0
#define SUBMENU_PAUSE_OPTIONS 1
#define SUBMENU_PAUSE_CONFIRM_MAIN_MENU 2
#define SUBMENU_PAUSE_CONFIRM_EXIT 3

// =====options=====

// main

// starting screen

#define OPTION_MAIN_STARTING_SCREEN 0
#define LENGHT_OPTIONS_MAIN_STARTING_SCREEN 1

// main menu

#define OPTION_MAIN_MAIN_LEVEL_SELECT 0
#define OPTION_MAIN_MAIN_OPTIONS 1
#define OPTION_MAIN_MAIN_CREDITS 2
#define OPTION_MAIN_MAIN_EXIT 3
#define LENGHT_OPTIONS_MAIN_MAIN 4

// level select

#define LENGHT_OPTIONS_MAIN_LEVEL_SELECT 11

// options

#define OPTION_MAIN_OPTIONS_MAIN_SOUND 0
#define OPTION_MAIN_OPTIONS_SFX 1
#define OPTION_MAIN_OPTIONS_MUSIC 2
#define OPTION_MAIN_OPTIONS_BACK 3
#define LENGHT_OPTIONS_MAIN_OPTIONS 4

// credits

#define OPTION_MAIN_CREDITS_BACK 0
#define LENGHT_OPTIONS_MAIN_CREDITS 1


// pause

// main

#define OPTION_PAUSE_CONTINUE 0
#define OPTION_PAUSE_RESTART 1
#define OPTION_PAUSE_OPTIONS 2
#define OPTION_PAUSE_MAIN_MENU 3
#define OPTION_PAUSE_QUIT 4
#define LENGHT_OPTIONS_PAUSE_MAIN 5

// options

#define OPTION_PAUSE_OPTIONS_MAIN_SOUND 0
#define OPTION_PAUSE_OPTIONS_MUSIC 1
#define OPTION_PAUSE_OPTIONS_SFX 2
#define OPTION_PAUSE_OPTIONS_BACK 3
#define LENGHT_OPTIONS_PAUSE_OPTIONS 4

// confirm main menu

#define OPTION_PAUSE_CONFIRM_MAIN_MENU_EXIT 0
#define OPTION_PAUSE_CONFIRM_MAIN_MENU_BACK 1
#define LENGHT_OPTIONS_PAUSE_MAIN_MENU_CONFIRM 2

// confirm exit

#define OPTION_PAUSE_CONFIRM_EXIT_EXIT 0
#define OPTION_PAUSE_CONFIRM_EXIT_BACK 1
#define LENGHT_OPTIONS_PAUSE_EXIT_CONFIRM 2


// win

// main

#define OPTION_WIN_NEXT_LEVEL 0
#define OPTION_WIN_RESTART 1
#define OPTION_WIN_MAIN_MENU 2
#define LENGHT_OPTIONS_WIN_MAIN 3


#ifndef MENU_H
#define MENU_H

// dictates the actions each key performs on a menu
void inMenuAction(SDL_Event *event);
// returns the number of options on a submenu
int getSubmenuOptionsLenght();

// dictates the actions each option on a menu does
void menuOptionSelect();
// dictates the actions each option on the main menu does
void menuOptionSelectMain();
// dictates the actions each option on the pause menu does
void menuOptionSelectPause();
// dictates the actions each option on thee win menu does
void menuOptionSelectWin();


#endif