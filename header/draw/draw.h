
// ========================================
// Printing functions
// Prints the current level
// works with audio
// ========================================

#pragma once

#include <stdio.h>

#include <SDL3/SDL.h>

#include "menu.h"
#include "../debug.h"
#include "../tools.h"
#include "../level/level.h"
#include "../level/highlight.h"
#include "../level/light.h"
#include "../level/objects/item.h"
#include "../level/objects/player.h"

// app info
#define APP_NAME "The City and The Tower"
#define APP_VERSION "0.0.1"
#define APP_IDENTIFIER "com.notlabeled.thecityandthetower"

// window default configuration
#define APP_WIDTH 1920
#define APP_HEIGHT 1080
#define APP_WINDOW_RESIZABLE SDL_WINDOW_FULLSCREEN

// layer draw order
#define LAYER_TILES_BOTTOM   0
#define LAYER_TILES_MIDDLE   1
#define LAYER_ITEMS          2
#define LAYER_PLAYER         3
#define LAYER_TILES_TOP      4
#define LAYER_LIGHT          5
#define LAYER_HIGHLIGHT      6

// size values
#define SPRITE_SIZE 32
#define NUM_TILES_WIDTH 30
#define NUM_TEILES_HEIGHT 16
#define WIDTH_MENU_MAIN 247
#define HEIGHT_MENU_MAIN 319
#define WIDTH_MENU_MAIN_PENCIL 194
#define HEIGHT_MENU_MAIN_PENCIL 126

// offsets
#define OFFSET_PIXELS_LAYER_TILES_TOP -20
#define OFFSET_PIXELS_LAYER_PLAYER -15
#define OFFSET_PIXELS_LAYER_ITEMS -15
#define OFFSET_MENU_MAIN_X 712
#define OFFSET_MENU_MAIN_Y 16

// menus
// main
// main
#define OFFSET_OPTION_MENU_MAIN_MAIN_LEVEL_SELECT_X 95
#define OFFSET_OPTION_MENU_MAIN_MAIN_LEVEL_SELECT_Y 112
#define OFFSET_OPTION_MENU_MAIN_MAIN_OPTIONS_X 102
#define OFFSET_OPTION_MENU_MAIN_MAIN_OPTIONS_Y 147
#define OFFSET_OPTION_MENU_MAIN_MAIN_CREDITS_X 106
#define OFFSET_OPTION_MENU_MAIN_MAIN_CREDITS_Y 184
#define OFFSET_OPTION_MENU_MAIN_MAIN_EXIT_X 81
#define OFFSET_OPTION_MENU_MAIN_MAIN_EXIT_Y 222
// options
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MAIN_SOUND_X 140
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MAIN_SOUND_Y 153
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_SFX_X 67
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_SFX_Y 176
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MUSIC_X 85
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MUSIC_Y 200
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_BACK_X 89
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_BACK_Y 224
// credits
#define OFFSET_OPTION_MENU_MAIN_CREDITS_BACK_X 97
#define OFFSET_OPTION_MENU_MAIN_CREDITS_BACK_Y 221
// level select
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_1_X 53
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_1_Y 153
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_2_X 53
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_2_Y 184
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_3_X 53
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_3_Y 213
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_4_X 53
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_4_Y 241
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_5_X 53
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_5_Y 277
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_6_X 167
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_6_Y 152
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_7_X 167
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_7_Y 180
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_8_X 167
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_8_Y 207
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_9_X 167
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_9_Y 240
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_10_X 167
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_10_Y 271
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_BACK_X 165
#define OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_BACK_Y 305


// sprites path
// game

// level
// tiles
#define SPRITE_WALL_BOTTOM_1 "assets/sprites/tiles/wall/spr_wall_bot_1.png"
#define SPRITE_WALL_BOTTOM_2 "assets/sprites/tiles/wall/spr_wall_bot_2.png"
#define SPRITE_WALL_BOTTOM_3 "assets/sprites/tiles/wall/spr_wall_bot_3.png"
#define SPRITE_GROUND_1_1 "assets/sprites/tiles/ground/spr_ground_1_1.png"
#define SPRITE_GROUND_1_2 "assets/sprites/tiles/ground/spr_ground_1_2.png"
#define SPRITE_GROUND_1_3 "assets/sprites/tiles/ground/spr_ground_1_3.png"
#define SPRITE_GROUND_2_1 "assets/sprites/tiles/ground/spr_ground_2_1.png"
#define SPRITE_GROUND_2_2 "assets/sprites/tiles/ground/spr_ground_2_2.png"
#define SPRITE_GROUND_2_3 "assets/sprites/tiles/ground/spr_ground_2_3.png"
#define SPRITE_PIT "assets/sprites/tiles/pit/spr_pit_1_1.png"
#define SPRITE_WALL_TORCH_LIT_RIGHT  "assets/sprites/tiles/wall_torch_lit/spr_wall_torch_lit_right_1.png"
#define SPRITE_WALL_TORCH_LIT_LEFT  "assets/sprites/tiles/wall_torch_lit/spr_wall_torch_lit_left_1.png"
#define SPRITE_WALL_TORCH_UNLIT_RIGHT "assets/sprites/tiles/wall_torch_unlit/spr_wall_torch_unlit_right_1.png"
#define SPRITE_WALL_TORCH_UNLIT_LEFT "assets/sprites/tiles/wall_torch_unlit/spr_wall_torch_unlit_left_1.png"
#define SPRITE_PLANK_TILE "assets/sprites/tiles/plank_tile/spr_plank_tile_3.png"
#define SPRITE_EXIT ""
// items
#define SPRITE_RELIC "assets/sprites/items/relic/spr_relic_1.png"
#define SPRITE_TORCH "assets/sprites/items/torch/spr_torch_1.png"
#define SPRITE_PLANK "assets/sprites/items/plank/spr_plank_1.png"
// player
#define SPRITE_PLAYER_EMPTY "assets/sprites/player/spr_player_empty_1.png"
#define SPRITE_PLAYER_TORCH "assets/sprites/player/spr_player_torch_1.png"
#define SPRITE_PLAYER_PLANK "assets/sprites/player/spr_player_plank_1.png"
#define SPRITE_PLAYER_RELIC "assets/sprites/player/spr_player_relic_1.png"
// tiles
#define SPRITE_WALL_TOP "assets/sprites/tiles/wall/spr_wall_top_1.png"
// light
#define SPRITE_UNLIT "assets/sprites/light/spr_unlit.png"
// highlight
#define SPRITE_HIGHLIGHT_GREEN "assets/sprites/ui/highlight/spr_highlight_green.png"
#define SPRITE_HIGHLIGHT_YELLOW "assets/sprites/ui/highlight/spr_highlight_yellow.png"
#define SPRITE_HIGHLIGHT_RED "assets/sprites/ui/highlight/spr_highlight_red.png"
// spritesheets
#define SPRITESHEET_PIT "assets/sprites/tiles/pit/spritesheet_pit.png"

// menus
// main
#define SPRITE_MENU_MAIN_BACKGROUND "assets/sprites/menus/main/spr_starting_cutscene.png"
#define SPRITE_MENU_MAIN_MAIN "assets/sprites/menus/main/main/spr_menu_main_main.png"
#define SPRITE_MENU_MAIN_LEVEL_SELECT "assets/sprites/menus/main/level/spr_menu_main_level_select.png"
#define SPRITE_MENU_MAIN_OPTIONS "assets/sprites/menus/main/options/spr_menu_main_options.png"
#define SPRITE_MENU_MAIN_CREDITS "assets/sprites/menus/main/credits/spr_menu_main_credits.png"
#define SPRITE_MENU_MAIN_PENCIL "assets/sprites/menus/main/spr_menu_main_pencil.png"
// pause
#define SPRITE_MENU_PAUSE_1 "assets/sprites/menus/pause/main/spr_menu_pause_1.png"
#define SPRITE_MENU_PAUSE_2 "assets/sprites/menus/pause/main/spr_menu_pause_2.png"
#define SPRITE_MENU_PAUSE_3 "assets/sprites/menus/pause/main/spr_menu_pause_3.png"
#define SPRITE_MENU_PAUSE_4 "assets/sprites/menus/pause/main/spr_menu_pause_4.png"
// menu
#define SPRITE_MENU_WIN_1 "assets/sprites/menus/win/main/spr_menu_win_1.png"
#define SPRITE_MENU_WIN_2 "assets/sprites/menus/win/main/spr_menu_win_2.png"
#define SPRITE_MENU_WIN_3 "assets/sprites/menus/win/main/spr_menu_win_3.png"


#define SOUND_MENU_MAIN_OPTION_SELECT "assets/audio/menu/snd_menu_main_option_select.wav"
#define SOUND_MENU_OPTION_SELECT "assets/audio/menu/snd_menu_option_select.wav"
#define SOUND_PLAYER_MOVE_1 "assets/audio/player/snd_player_move_1.wav"
#define SOUND_PLAYER_MOVE_2 "assets/audio/player/snd_player_move_2.wav"



#ifndef DRAW_H
#define DRAW_H

// ===== sprites =====
// bottom tiles layer
/* extern SDL_Texture *spr_wall_bottom[3];
extern SDL_Texture *spr_ground[2][3];
extern SDL_Texture *spr_pit[49];
extern SDL_Texture *spr_pit1;
extern SDL_Texture *spr_wall_torch_lit_right;
extern SDL_Texture *spr_wall_torch_lit_left;
extern SDL_Texture *spr_wall_torch_unlit_right;
extern SDL_Texture *spr_wall_torch_unlit_left;
extern SDL_Texture *spr_plank_tile;
extern SDL_Texture *spr_exit;
// items layer
extern SDL_Texture *spr_relic;
extern SDL_Texture *spr_torch;
extern SDL_Texture *spr_plank;
// player layer
extern SDL_Texture *spr_player[2][4];
// top tiles layer
extern SDL_Texture *spr_wall_top;
// light layer
extern SDL_Texture *spr_unlit;
// highlight layer
extern SDL_Texture *spr_highlight_green;
extern SDL_Texture *spr_highlight_yellow;
extern SDL_Texture *spr_highlight_red;

// menus
extern SDL_Texture *image_starting_screen_background;
extern SDL_Texture *spr_menu_main_main;
extern SDL_Texture *spr_menu_main_level_select;
extern SDL_Texture *spr_menu_main_options;
extern SDL_Texture *spr_menu_main_credits;
extern SDL_Texture *spr_menu_main_pencil;

extern SDL_Texture *spr_menu_pause_main[4];
extern SDL_Texture *spr_menu_win_main[3]; */


// window properties
extern int window_width, window_height;

void loadWindowIcon(SDL_Window *window);

// ===== level =====
void renderLevel(SDL_Renderer *renderer, SDL_Window *window);

SDL_Renderer * rendererCreate(); // create renderer
void rendererPresent(SDL_Renderer *renderer); // present renderer

// load textures into memory
void loadTextures(SDL_Renderer *renderer);
SDL_Texture * loadTextureFromPNG(SDL_Renderer *renderer, const char * path);
// get textures
SDL_Texture * getTextureFromChar(char tile, int layer, int pos_x, int pos_y);
SDL_Texture * getTextureWallTorchLit(int pos_x, int pos_y);
SDL_Texture * getTextureWallTorchUnlit(int pos_x, int pos_y);
SDL_Texture * getTexturePitTile(int pos_x, int pos_y);

// render action for specific sprites
void renderSprite(SDL_Renderer *renderer, SDL_Texture * texture, int pos_x, int pos_y);

// render sprites
void renderLayerTilesBottom(SDL_Renderer *renderer, int pos_x, int pos_y);
void renderLayerTilesMiddle(SDL_Renderer * renderer, int pos_x, int pos_y);
void renderLayerTilesTop(SDL_Renderer *renderer, int pos_x, int pos_y);
void renderLayerItems(SDL_Renderer *renderer, int pos_x, int pos_y);
void renderLayerLight(SDL_Renderer *renderer, int pos_x, int pos_y);
void renderLayerPLayer(SDL_Renderer *renderer, int pos_x, int pos_y);
void renderLayerHighlight(SDL_Renderer *renderer, int pos_x, int pos_y);


// ===== menus =====

void renderMenu(SDL_Renderer *renderer, SDL_Window *window, int menu, int submenu, int option);

void renderMenuMain(SDL_Renderer *renderer, int submenu, int option, int scale);
void renderMenuPause(SDL_Renderer *renderer, int submenu, int option, int scale);
void renderMenuWin(SDL_Renderer *renderer, int submenu, int option, int scale);

void renderPNG(SDL_Renderer *renderer, SDL_Texture *texture, int pos_x, int pos_y, int width, int height);


// sounds

void loadSounds();
SDL_AudioSpec loadSoundFromWAV(const char *file_path);






#endif