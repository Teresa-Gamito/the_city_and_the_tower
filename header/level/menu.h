
#include <stdbool.h>

#define MENU_STARTING_SCREEN 0
#define MENU_MAIN 1
#define MENU_LEVELS 2
#define MENU_OPTIONS 3
#define MENU_CREDITS 4
#define MENU_PAUSE 5
#define MENU_WIN 6


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

// pause options
#define PAUSE_CONTINUE 1
#define PAUSE_OPTIONS 2
#define PAUSE_RESTART 3
#define PAUSE_MAIN_MENU 4
#define PAUSE_EXIT 5

// win menu options
#define WIN_MENU_NEXT_LEVEL 1
#define WIN_MENU_RESTART_LEVEL 2
#define WIN_MENU_MAIN_MENU 3
#define WIN_MENU_EXIT_GAME 4



#define MENU_MAIN_MAX_BUTTONS 4
#define MENU_OPTIONS_MAX_BUTTONS 6


#define IMAGE_LOGO "../images/logo.txt"


#ifndef MENU_H
#define MENU_H


// -----------------------
void menuPrint(int current_menu); // print current menu
// -----------------------


// -----------------------
// print menus
// specific menus
void menuPrintMain();
void menuPrintOptions();
void menuPrintCredits();
void menuPrintLevel();
// -----------------------


// -----------------------
void menuTravelMain(int * level_to_load); // menu structure


void menuPrintStartingScreen(); // print the starting cutsceene

// travel menus
bool menuAction(int * current_menu, int option, int * level_to_load);
void menuStartingScreenAction(int * current_menu);
void menuMainAction(int * current_menu, int option);
bool menuLevelAction(int * current_menu, int option, int * level_to_load);
void menuOptionsAction(int * current_menu, int option);
void menuCreditsAction(int * current_menu, int option);
// -----------------------


// -----------------------
void menuTravelWin();

bool menuWinAction(int option);

void menuPrintWin();
// -----------------------


// -----------------------
void menuTravelPause();

bool menuPauseAction(int option);

void menuPrintPause();
// -----------------------


#endif