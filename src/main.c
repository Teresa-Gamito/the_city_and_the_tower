
// ==============================
// Main
// ==============================

/* #include <stdio.h>
#include <stdbool.h> */

#define SDL_MAIN_USE_CALLBACKS 1 // uses SDL callbacks
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/* #include "../header/level/objects/item.h"
#include "../header/level/objects/player.h"
#include "../header/level/level.h"
#include "../header/level/highlight.h"
#include "../header/level/light.h"
#include "../header/draw/menu.h"
#include "../header/draw/draw.h"
#include "../header/tools.h" */
#include "../header/debug.h"

// app info
#define APP_NAME "The City and The Tower"
#define APP_VERSION "0.0.1"
#define APP_IDENTIFIER "com.notlabeled.thecityandthetower"

// window configuration
#define APP_WIDTH 640
#define APP_HEIGHT 480
#define APP_WINDOW_RESIZABLE SDL_WINDOW_RESIZABLE


/* void actionFromInput(char * input); // action center

// game structure movement
void goToMainMenu();
void gotoLevel(int level_num);

bool runLevel(); // loops the game */



static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {

    logOpen();
    logPrint("Game start\n\n");



    SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        logPrint("Couldn't initialize SDL: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(APP_NAME, APP_WIDTH, APP_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        logPrint("Couldn't create window/renderer: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    //SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);


    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;

}

SDL_AppResult SDL_AppIterate(void *appstate) {

    SDL_SetRenderDrawColorFloat(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE_FLOAT);



    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {

    logClose();

}


/* int main() {

    

    while (true) {
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColorFloat(renderer, 40, 20, 20, SDL_ALPHA_OPAQUE_FLOAT);

        SDL_RenderPresent(renderer);
    }
    

    

    goToMainMenu();

    return 0;
}


void goToMainMenu() {

    int level_to_load;

    while (true) {

        menuTravelMain(&level_to_load);

        gotoLevel(level_to_load);
    }

}

void gotoLevel(int level_num) {

    levelLoad(level_num, 1, PLAYER_SPAWN_FROM_FILE, PLAYER_SPAWN_FROM_FILE, CHAR_EMPTY);

    while (runLevel());

    level_active.level_exit = false;

}


bool runLevel() {

    drawLevel();

    actionFromInput(getInput());

    return !level_active.level_exit;

}


void actionFromInput(char * input) {

    if (input[1] == '\0') {
        if (highlight.is_on) {
            highlightAction(input[0]);
        }
        else {
            playerAction(input[0]);
        }
    }
    else debugCommand(input);
    
} */