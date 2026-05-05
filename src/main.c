// ==============================
// Main
// ==============================


#include "../header/main.h"
#include <SDL3/SDL_timer.h>

#define SDL_MAIN_USE_CALLBACKS 1 // uses SDL callbacks
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_AudioDeviceID audio_device = 0;

Gamestate gamestate = {SCREEN_MENU, MENU_MAIN, SUBMENU_MAIN_STARTING_SCREEN, 0, 1, 1, 1};


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {


    logOpen();
    logPrint("Game start\n\n");

    SDL_SetAppMetadata(APP_NAME, APP_VERSION, APP_IDENTIFIER);

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        logPrint("Couldn't initialize SDL: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(APP_NAME, APP_WIDTH, APP_HEIGHT, APP_WINDOW_RESIZABLE, &window, &renderer)) {
        logPrint("Couldn't create window/renderer: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    audio_device = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);

    SDL_SetDefaultTextureScaleMode(renderer, SDL_SCALEMODE_NEAREST);


    SDL_SetRenderLogicalPresentation(renderer, APP_WIDTH, APP_HEIGHT, SDL_LOGICAL_PRESENTATION_DISABLED);

    loadWindowIcon(window);

    loadSounds(audio_device);

    loadTextures(renderer);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    else if (event->type == SDL_EVENT_KEY_DOWN || event->type == SDL_EVENT_KEY_UP) {
        switch (gamestate.current_screen) {
        case SCREEN_MENU:
            inMenuAction(event);
            break;
        
        case SCREEN_LEVEL:
            inLevelAction(event);
            debugCommand(event);
            break;
        }
    }
    
    return SDL_APP_CONTINUE;

}

SDL_AppResult SDL_AppIterate(void *appstate) {

    SDL_Delay(16);
    gameUpdate();
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {

    SDL_CloseAudioDevice(audio_device);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    logClose();
    exit(0);

}

void game_quit() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    logClose();
    exit(0);
    
}

void gameUpdate() {
    switch (gamestate.current_screen) {
        
    case SCREEN_MENU:
        renderMenu(renderer, window);
        break;
    case SCREEN_LEVEL:
        lightPorcessLayers();
        renderLevel(renderer, window);
        break;
    }

    if (gamestate.current_screen == SCREEN_LEVEL) {
        if (gamestate.volume_music && gamestate.volume_main) {
            if (SDL_GetAudioStreamQueued(msc_main.stream) < ((int) msc_main.wav_data_lenght)) {
                SDL_PutAudioStreamData(msc_main.stream, msc_main.wav_data, msc_main.wav_data_lenght);
            }
        }
        else SDL_PauseAudioStreamDevice(msc_main.stream);
    }

}
