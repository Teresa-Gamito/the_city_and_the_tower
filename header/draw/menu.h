
// ==============================
// Draw and navigate menus
// Starting screen is an image
// ==============================

#pragma once
#include <stdio.h>
#include <stdbool.h>

#include <SDL3/SDL.h>

#include "../level/level.h"
#include "../tools.h"
#include "../debug.h"
#include "../main.h"

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
#define OPTION_PAUSE_MAIN_MENU 2
#define OPTION_PAUSE_QUIT 3
#define LENGHT_OPTIONS_PAUSE_MAIN 4
// win
// main
#define OPTION_WIN_NEXT_LEVEL 0
#define OPTION_WIN_RESTART 1
#define OPTION_WIN_MAIN_MENU 2
#define LENGHT_OPTIONS_WIN_MAIN 3

// awawa
// options
// main menu options
#define MAIN_MENU_START 0
#define MAIN_MENU_OPTIONS 1
#define MAIN_MENU_CREDITS 2
#define MAIN_MENU_QUIT 3
// options options
#define OPTIONS_MAIN_SOUND 0
#define OPTIONS_SOUND_EFFECTS 1
#define OPTIONS_MUSIC 2
#define OPTIONS_ACCESSIBILITY 3
#define OPTIONS_ERRASE_ALL_DATA 4
#define OPTIONS_BACK 5
// pause options
#define PAUSE_CONTINUE 0
#define PAUSE_RESTART 1
#define PAUSE_MAIN_MENU 2
#define PAUSE_EXIT 3
// win menu options
#define WIN_MENU_NEXT_LEVEL 0
#define WIN_MENU_RESTART_LEVEL 1
#define WIN_MENU_MAIN_MENU 2

// images
#define IMAGE_LOGO "images/logo.txt"
// end of awawa

#ifndef MENU_H
#define MENU_H

void inMenuAction(SDL_Event *event);
int getSubmenuOptionsLenght();
void menuOptionSelect();

#endif