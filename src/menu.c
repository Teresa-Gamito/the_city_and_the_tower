
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../header/level/menu.h"
#include "../header/tools.h"


void menuTravel(int * level_to_load) {

    int current_menu = MENU_STARTING_SCREEN;
    int current_buttons = 0;

    char * temp_input;
    int input;

    do {
        system("cls");
        menuPrint(current_menu);

        temp_input = getInput();
        input = temp_input[0] - '0';
        
    } while (menuAction(&current_menu, input, level_to_load));
    
}

void menuPrint(int current_menu) {

    switch (current_menu) {

        case MENU_STARTING_SCREEN:
            menuPrintStartingScreen();
            break;


        case MENU_MAIN:
            menuPrintMain();
            break;

        case MENU_LEVELS:
            menuPrintLevel();
            break;


        case MENU_OPTIONS:
            menuPrintOptions();
            break;


        case MENU_CREDITS:
            menuPrintCredits();
            break;
        
        

    }

}

void menuPrintStartingScreen() {

}


void menuPrintMain() {

    printf(" 1 - Start\n 2 - Options\n 3 - Credits\n 4 - Exit\n ");

}

void menuPrintOptions() {

    printf(" 1 - Main sound\n 2 - Sound Effects\n 3 - Music\n 4 - Accessibility\n 5 - Errase all data\n 6 - Back\n ");

}

void menuPrintCredits() {

    printf(" Game made by:\n\n 🦥 Rodrigo Valente\n 🐐 Teresa Gamito\n\n\n Back\n ");

}

void menuPrintLevel() {

    printf(" 1 - Level 1 ()\n 2 - Level 2 ()\n 3 - Level 3 ()\n ");

}


void menuPrintPause() {

}



bool menuAction(int * current_menu, int option, int * level_to_load) {

    switch (*current_menu) {

        case MENU_STARTING_SCREEN:
            menuStartingScreenAction(current_menu);
            break;

        case MENU_MAIN:
            menuMainAction(current_menu, option);
            break;

        case MENU_OPTIONS:
            menuOptionsAction(current_menu, option);
            break;

        case MENU_CREDITS:
            menuCreditsAction(current_menu, option);
            break;

        case MENU_LEVELS:
            if (menuLevelAction(current_menu, option, level_to_load)) return false;
            break;

    }
    return true;

}

void menuStartingScreenAction(int * current_menu) {

    *current_menu = MENU_MAIN;

}

void menuMainAction(int * current_menu, int option) {

    switch (option) {
        case MAIN_MENU_START:
            *current_menu = MENU_LEVELS;
            break;
        
        case MAIN_MENU_OPTIONS:
            *current_menu = MENU_OPTIONS;
            break;

        case MAIN_MENU_CREDITS:
            *current_menu = MENU_CREDITS;
            break;
        
        case MAIN_MENU_QUIT:
            exit(0);
            break;
    }

}

bool menuLevelAction(int * current_menu, int option, int * level_to_load) {

    if (option == 0) {
        *current_menu = MENU_MAIN;
        return false;
    }

    else {
        *level_to_load = option;
        return true;
    }

}

void menuOptionsAction(int * current_menu, int option) {

    switch (option) {
        case OPTIONS_MAIN_SOUND:
            
            break;
        
        case OPTIONS_SOUND_EFFECTS:
            
            break;

        case OPTIONS_MUSIC:
            
            break;
        
        case OPTIONS_ACCESSIBILITY:
            
            break;

        case OPTIONS_ERRASE_ALL_DATA:
            
            break;

        case OPTIONS_BACK:
            *current_menu = MENU_MAIN;
            break;
    }

}

void menuCreditsAction(int * current_menu, int option) {

    *current_menu = MENU_MAIN;

}
