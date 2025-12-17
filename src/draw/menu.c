 
#include "../../header/draw/menu.h"


void inMenuAction(SDL_Event *event) {
    
    if (event->type == SDL_EVENT_KEY_DOWN) {

        switch (event->key.scancode) {
            
        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_UP:
            gamestate.current_option--;
            if (gamestate.current_option < 0) 
                gamestate.current_option = getSubmenuOptionsLenght() - 1;
            break;

        case SDL_SCANCODE_RIGHT:
        case SDL_SCANCODE_DOWN:
            gamestate.current_option++;
            if (gamestate.current_option >= getSubmenuOptionsLenght()) gamestate.current_option = 0;
            break;

        case SDL_SCANCODE_Z:
        case SDL_SCANCODE_SPACE:
        case SDL_SCANCODE_RETURN:
            menuOptionSelect();
            break;

        case SDL_SCANCODE_ESCAPE:
            if (gamestate.current_menu == MENU_PAUSE) {
                gamestate.current_option = 0;
                gamestate.current_screen = SCREEN_LEVEL;
            }
            break;

        }

        
    }
}

int getSubmenuOptionsLenght() {

    switch (gamestate.current_menu) {

    case MENU_MAIN:
        switch (gamestate.current_submenu) {

        case SUBMENU_MAIN_STARTING_SCREEN:
            return LENGHT_OPTIONS_MAIN_STARTING_SCREEN;
            break;
        case SUBMENU_MAIN_MAIN:
            return LENGHT_OPTIONS_MAIN_MAIN;
            break;
        case SUBMENU_MAIN_LEVEL_SELECT:
            return LENGHT_OPTIONS_MAIN_LEVEL_SELECT;
            break;
        case SUBMENU_MAIN_OPTIONS:
            return LENGHT_OPTIONS_MAIN_OPTIONS;
            break;
        case SUBMENU_MAIN_CREDITS:
            return LENGHT_OPTIONS_MAIN_CREDITS;
            break;

        }
        break;

    case MENU_PAUSE:
        switch (gamestate.current_submenu) {
        case SUBMENU_PAUSE_MAIN:
            return LENGHT_OPTIONS_PAUSE_MAIN;
            break;

        case SUBMENU_PAUSE_OPTIONS:
            return LENGHT_OPTIONS_PAUSE_OPTIONS;
            break;

        case SUBMENU_PAUSE_CONFIRM_EXIT:
            return LENGHT_OPTIONS_PAUSE_EXIT_CONFIRM;
            break;
            
        case SUBMENU_PAUSE_CONFIRM_MAIN_MENU:
            return LENGHT_OPTIONS_PAUSE_MAIN_MENU_CONFIRM;
            break;
        }
        break;

    case MENU_WIN:
        return LENGHT_OPTIONS_WIN_MAIN;
        break;
    }
}

void menuOptionSelect() {

    switch (gamestate.current_menu) {

    case MENU_MAIN:
        menuOptionSelectMain();
        break;

    case MENU_PAUSE:
        menuOptionSelectPause();
        break;

    case MENU_WIN:
        menuOptionSelectWin();
        break;
    }
}

void menuOptionSelectMain() {
    switch (gamestate.current_submenu) {

    case SUBMENU_MAIN_STARTING_SCREEN:
        gamestate.current_option = 0;
        gamestate.current_submenu = SUBMENU_MAIN_MAIN;
        break;
    case SUBMENU_MAIN_MAIN:
        switch (gamestate.current_option) {
            case OPTION_MAIN_MAIN_LEVEL_SELECT:
                gamestate.current_submenu = SUBMENU_MAIN_LEVEL_SELECT;
                break;
            case OPTION_MAIN_MAIN_OPTIONS:
                gamestate.current_option = 0;
                gamestate.current_submenu = SUBMENU_MAIN_OPTIONS;
                break;
            case OPTION_MAIN_MAIN_CREDITS:
                gamestate.current_option = 0;
                gamestate.current_submenu = SUBMENU_MAIN_CREDITS;
                break;
            case OPTION_MAIN_MAIN_EXIT:
                game_quit();
                break;
        }
        break;
    case SUBMENU_MAIN_LEVEL_SELECT:
        if (gamestate.current_option == 0) {
            gamestate.current_option = 0;
            gamestate.current_submenu = SUBMENU_MAIN_MAIN;
        }
        else if (gamestate.current_option > 0 || gamestate.current_option <= 9) {
            levelLoad(
                gamestate.current_option,
                1,
                PLAYER_SPAWN_FROM_FILE,
                PLAYER_SPAWN_FROM_FILE,
                PLAYER_NO_ITEM
            );
            gamestate.current_option = 0;
            gamestate.current_screen = SCREEN_LEVEL;
        }
        break;
    case SUBMENU_MAIN_OPTIONS:
        switch (gamestate.current_option) {
            case OPTION_MAIN_OPTIONS_MAIN_SOUND:
                gamestate.volume_main = !gamestate.volume_main;
                break;
            case OPTION_MAIN_OPTIONS_MUSIC:
                gamestate.volume_music = !gamestate.volume_music;
                break;
            case OPTION_MAIN_OPTIONS_SFX:
                gamestate.volume_sfx = !gamestate.volume_sfx;
                break;
            case OPTION_MAIN_OPTIONS_BACK:
                gamestate.current_option = 0;
                gamestate.current_submenu = SUBMENU_MAIN_MAIN;
                break;
        }
        break;
    case SUBMENU_MAIN_CREDITS:
        gamestate.current_option = 0;
        gamestate.current_submenu = SUBMENU_MAIN_MAIN;
        break;

    }
    soundPlay(snd_menu_main_option_select);
}

void menuOptionSelectPause() {
    switch (gamestate.current_submenu) {
    case SUBMENU_PAUSE_MAIN:
        switch (gamestate.current_option) {
        case OPTION_PAUSE_CONTINUE:
            gamestate.current_option = 0;
            gamestate.current_screen = SCREEN_LEVEL;
            break;
        case OPTION_PAUSE_RESTART:
            levelRestart();
            gamestate.current_option = 0;
            gamestate.current_screen = SCREEN_LEVEL;
            break;
        case OPTION_PAUSE_OPTIONS:
            gamestate.current_option = 0;
            gamestate.current_submenu = SUBMENU_PAUSE_OPTIONS;
            break;
        case OPTION_PAUSE_MAIN_MENU:
            gamestate.current_option = 1;
            gamestate.current_submenu = SUBMENU_PAUSE_CONFIRM_MAIN_MENU;
            break;
        case OPTION_PAUSE_QUIT:
            gamestate.current_option = 1;
            gamestate.current_submenu = SUBMENU_PAUSE_CONFIRM_EXIT;
            break;
        }
        break;
    case SUBMENU_PAUSE_OPTIONS:
        switch (gamestate.current_option) {
        case OPTION_PAUSE_OPTIONS_MAIN_SOUND:
            gamestate.volume_main = !gamestate.volume_main;
            break;
        case OPTION_PAUSE_OPTIONS_MUSIC:
            gamestate.volume_music = !gamestate.volume_music;
            break;
        case OPTION_PAUSE_OPTIONS_SFX:
            gamestate.volume_sfx = !gamestate.volume_sfx;
            break;
        case OPTION_PAUSE_OPTIONS_BACK:
            gamestate.current_option = 0;
            gamestate.current_submenu = SUBMENU_PAUSE_MAIN;
            break;
        }
        break;
    case SUBMENU_PAUSE_CONFIRM_MAIN_MENU:
        switch (gamestate.current_option) {
        case OPTION_PAUSE_CONFIRM_MAIN_MENU_EXIT:
            gamestate.current_option = 0;
            gamestate.current_submenu = SUBMENU_MAIN_MAIN;
            gamestate.current_menu = MENU_MAIN;
            break;
        case OPTION_PAUSE_CONFIRM_MAIN_MENU_BACK:
            gamestate.current_option = 0;
            gamestate.current_submenu = SUBMENU_PAUSE_MAIN;
            break;
        }
        break;
    case SUBMENU_PAUSE_CONFIRM_EXIT:
        switch (gamestate.current_option) {
        case OPTION_PAUSE_CONFIRM_MAIN_MENU_EXIT:
            game_quit();
            break;
        case OPTION_PAUSE_CONFIRM_EXIT_BACK:
            gamestate.current_option = 0;
            gamestate.current_submenu = SUBMENU_PAUSE_MAIN;
            break;
        }
        break;
    }
    soundPlay(snd_menu_option_select);
}

void menuOptionSelectWin() {
    switch (gamestate.current_option) {
    case OPTION_WIN_NEXT_LEVEL:
        levelGoToNext();
        gamestate.current_option = 0;
        gamestate.current_screen = SCREEN_LEVEL;
        break;
    case OPTION_WIN_RESTART:
        levelRestart();
        gamestate.current_option = 0;
        gamestate.current_screen = SCREEN_LEVEL;
        break;
    case OPTION_WIN_MAIN_MENU:
        gamestate.current_option = 0;
        gamestate.current_submenu = SUBMENU_MAIN_MAIN;
        gamestate.current_menu = MENU_MAIN;
        break;
    }
    soundPlay(snd_menu_option_select);
}