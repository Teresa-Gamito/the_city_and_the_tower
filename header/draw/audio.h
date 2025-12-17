
// ==============================
// Functions related to sound
// ==============================

#pragma once

#include <SDL3/SDL.h>

#include "../debug.h"

// paths
// music
#define MUSIC_MAIN "assets/audio/music/msc_main.wav"
// player move
#define SOUND_PLAYER_MOVE_GROUND_1 "assets/audio/player/snd_player_move_ground_1.wav"
#define SOUND_PLAYER_MOVE_GROUND_2 "assets/audio/player/snd_player_move_ground_2.wav"
// items 
#define SOUND_ITEM_PICK_UP "assets/audio/item/snd_item_pick_up.wav"
#define SOUND_ITEM_DROP "assets/audio/item/snd_item_drop.wav"
// wall torch
#define SOUND_WALL_TORCH_LIT "assets/audio/wall_torch/snd_wall_torch_lit.wav"
#define SOUND_WALL_TORCH_UNLIT "assets/audio/wall_torch/snd_wall_torch_unlit.wav"
// menu
#define SOUND_MENU_MAIN_OPTION_SELECT "assets/audio/menu/snd_menu_main_option_select.wav"
#define SOUND_MENU_OPTION_SELECT "assets/audio/menu/snd_menu_option_select.wav"

// audio structure, holds the information of a sound asset
typedef struct Sound {
    Uint8 *wav_data;
    Uint32 wav_data_lenght;
    SDL_AudioStream *stream;
} Sound;


// music
extern Sound msc_main;                      // main soundtrack that plays in the level
// sound effects
// player
extern Sound snd_player_move_ground[2];     // plays when the player is moving
// items
extern Sound snd_item_pick_up;              // plays when the player picks up an item
extern Sound snd_item_drop;                 // plays when the player drops an item
// wall torch
extern Sound snd_wall_torch_lit;            // plays when an wall torch gets lit
extern Sound snd_wall_torch_unlit;          // plays when an wall torch gets unlit
// menu
extern Sound snd_menu_main_option_select;   //plays when selecting an option on the main menu
extern Sound snd_menu_option_select;        //plays when selecting an option on either the pause or win menus

#ifndef AUDIO_H
#define AUDIO_H



// sounds

// loads all sounds into memory to be accessed later
// \param audio_device the currently active audio device
void loadSounds(SDL_AudioDeviceID audio_device); 
// loads a specific sound from a .wav file
// \param audio_device the currently active audio device
// \param *file_path the path of the audio file to load
Sound loadSoundFromWAV(SDL_AudioDeviceID audio_device, const char *file_path); 
// plays a sound that was already laoded into memory
// \param sound sound to load
void soundPlay(Sound sound); 


#endif