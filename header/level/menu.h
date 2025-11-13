
#include <stdbool.h>

#define MENU_STARTING_SCREEN 0
#define MENU_MAIN 1
#define MENU_LEVELS 2
#define MENU_OPTIONS 3
#define MENU_CREDITS 4


// main menu options
#define MAIN_MENU_START 1
#define MAIN_MENU_OPTIONS 2
#define MAIN_MENU_CREDITS 3
#define MAIN_MENU_QUIT 4

// options options
#define OPTIONS_MAIN_SOUND 1
#define OPTIONS_SOUND_EFFECTS 2
#define OPTIONS_MUSIC 3
#define OPTIONS_ACCESSIBILITY 4
#define OPTIONS_ERRASE_ALL_DATA 5
#define OPTIONS_BACK 6


#define MENU_MAIN_MAX_BUTTONS 4
#define MENU_OPTIONS_MAX_BUTTONS 6


#ifndef MENU_H
#define MENU_H

void menuTravel(int * level_to_load); // menu structure

void menuPrintStartingScreen(); // print the starting cutsceene

// print menus
void menuPrint(int current_menu); // print current menu
// specific menus
void menuPrintMain();
void menuPrintOptions();
void menuPrintCredits();
void menuPrintLevel();

void menuPrintPause();

// travel menus
bool menuAction(int * current_menu, int option, int * level_to_load);
void menuStartingScreenAction(int * current_menu);
void menuMainAction(int * current_menu, int option);
bool menuLevelAction(int * current_menu, int option, int * level_to_load);
void menuOptionsAction(int * current_menu, int option);
void menuCreditsAction(int * current_menu, int option);


#endif