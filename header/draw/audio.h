
// ==============================
// Functions related to sound
// ==============================

#pragma once

#include <SDL3/SDL.h>

#include "../debug.h"

// paths
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

typedef struct Sound {
    Uint8 *wav_data;
    Uint32 wav_data_lenght;
    SDL_AudioStream *stream;
} Sound;

// sounds
// player
extern Sound snd_player_move_ground[2];
extern Sound snd_player_move_plank;
// items
extern Sound snd_item_pick_up;
extern Sound snd_item_drop;
extern Sound snd_item_relic_pick_up;
// wall torch
extern Sound snd_wall_torch_lit;
extern Sound snd_wall_torch_unlit;
// menu
extern Sound snd_menu_main_option_select;
extern Sound snd_menu_option_select;

#ifndef AUDIO_H
#define AUDIO_H



// sounds

void loadSounds(SDL_AudioDeviceID audio_device); // loads all sounds into memory to be accessed later
Sound loadSoundFromWAV(SDL_AudioDeviceID audio_device, const char *file_path); // loads a specific sound from a .wav file

void soundPlay(Sound sound); // plays a sound that was already laoded into memory


#endif