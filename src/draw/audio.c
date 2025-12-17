
#include "../../header/draw/audio.h"

Sound msc_main;

Sound snd_player_move_ground[2];

Sound snd_item_pick_up;
Sound snd_item_drop;

Sound snd_wall_torch_lit;
Sound snd_wall_torch_unlit;

Sound snd_menu_main_option_select;
Sound snd_menu_option_select;



void loadSounds(SDL_AudioDeviceID audio_device) {

    logPrint("loading sounds\n");

    msc_main = loadSoundFromWAV(audio_device, MUSIC_MAIN);

    snd_player_move_ground[0] = loadSoundFromWAV(audio_device, SOUND_PLAYER_MOVE_GROUND_1);
    snd_player_move_ground[1] = loadSoundFromWAV(audio_device, SOUND_PLAYER_MOVE_GROUND_2);
    
    snd_item_pick_up = loadSoundFromWAV(audio_device, SOUND_ITEM_PICK_UP);
    snd_item_drop = loadSoundFromWAV(audio_device, SOUND_ITEM_DROP);

    snd_wall_torch_lit = loadSoundFromWAV(audio_device, SOUND_WALL_TORCH_LIT);
    snd_wall_torch_unlit = loadSoundFromWAV(audio_device, SOUND_WALL_TORCH_UNLIT);
    
    snd_menu_main_option_select = loadSoundFromWAV(audio_device, SOUND_MENU_MAIN_OPTION_SELECT);
    snd_menu_option_select = loadSoundFromWAV(audio_device, SOUND_MENU_OPTION_SELECT);

    logPrint("Sounds loaded\n");


}

Sound loadSoundFromWAV(SDL_AudioDeviceID audio_device, const char *file_path) {

    char *snd_path = NULL;

    Sound sound;
    SDL_AudioSpec spec;

    SDL_asprintf(&snd_path, "%s%s", SDL_GetBasePath(), file_path);

    SDL_LoadWAV(snd_path, &spec, &sound.wav_data, &sound.wav_data_lenght);

    sound.stream = SDL_CreateAudioStream(&spec, NULL);

    SDL_BindAudioStream(audio_device, sound.stream);

    SDL_free(snd_path);

    return sound;

}

void soundPlay(Sound sound) {

    SDL_ClearAudioStream(sound.stream);

    if (gamestate.volume_main && gamestate.volume_sfx) SDL_PutAudioStreamData(sound.stream, sound.wav_data, (int) sound.wav_data_lenght);

}