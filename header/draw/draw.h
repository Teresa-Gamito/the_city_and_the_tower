
// ========================================
// Printing functions
// Prints the current level
// works with audio
// ========================================

#pragma once

#include <stdio.h>

#include <SDL3/SDL.h>

#include "menu.h"
#include "../main.h"
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
#define WIDTH_MENU_PAUSE 376
#define HEIGHT_MENU_PAUSE 395
#define WIDTH_MENU_PAUSE_CHECKMARK 23
#define HEIGHT_MENU_PAUSE_CHECKMARK 39
#define WIDTH_MENU_PAUSE_CROSS 26
#define HEIGHT_MENU_PAUSE_CROSS 34
#define WIDTH_MENU_MAIN_CHECKMARK 18
#define HEIGHT_MENU_MAIN_CHECKMARK 17
#define WIDTH_MENU_MAIN_CROSS 16
#define HEIGHT_MENU_MAIN_CROSS 16

// offsets
#define OFFSET_PIXELS_LAYER_TILES_TOP -20
#define OFFSET_PIXELS_LAYER_PLAYER -15
#define OFFSET_PIXELS_LAYER_ITEMS -15
#define OFFSET_MENU_MAIN_X 712
#define OFFSET_MENU_MAIN_Y 16
#define OFFSET_MENU_PAUSE_X APP_WIDTH / 4 - WIDTH_MENU_PAUSE / 2
#define OFFSET_MENU_PAUSE_Y APP_HEIGHT / 4 - HEIGHT_MENU_PAUSE / 2

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
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MAIN_SOUND_X 156
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MAIN_SOUND_Y 153
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_SFX_X 83
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_SFX_Y 176
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MUSIC_X 101
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_MUSIC_Y 200
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_BACK_X 89
#define OFFSET_OPTION_MENU_MAIN_OPTIONS_BACK_Y 224
// credits
#define OFFSET_OPTION_MENU_MAIN_CREDITS_BACK_X 98
#define OFFSET_OPTION_MENU_MAIN_CREDITS_BACK_Y 289
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

// main checkmarks
#define OFFSET_MENU_MAIN_MAIN_SOUND_CHECKMARK_X 137
#define OFFSET_MENU_MAIN_MAIN_SOUND_CHECKMARK_Y 141
#define OFFSET_MENU_MAIN_MUSIC_CHECKMARK_X 82
#define OFFSET_MENU_MAIN_MUSIC_CHECKMARK_Y 196
#define OFFSET_MENU_MAIN_SFX_CHECKMARK_X 66
#define OFFSET_MENU_MAIN_SFX_CHECKMARK_Y 168
// pause checkmarks
#define OFFSET_MENU_PAUSE_MAIN_SOUND_CHECKMARK_X 268
#define OFFSET_MENU_PAUSE_MAIN_SOUND_CHECKMARK_Y 129
#define OFFSET_MENU_PAUSE_MUSIC_CHECKMARK_X 219
#define OFFSET_MENU_PAUSE_MUSIC_CHECKMARK_Y 190
#define OFFSET_MENU_PAUSE_SFX_CHECKMARK_X 193
#define OFFSET_MENU_PAUSE_SFX_CHECKMARK_Y 238


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
#define SPRITE_EXIT "assets/sprites/tiles/exit/spr_exit.png"
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
#define SPRITE_MENU_MAIN_OPTIONS_CHECKMARK "assets/sprites/menus/main/spr_menu_checkmark.png"
#define SPRITE_MENU_MAIN_OPTIONS_CROSS "assets/sprites/menus/main/spr_menu_cross.png"

// pause
// main
#define SPRITE_MENU_PAUSE_MAIN_1 "assets/sprites/menus/pause/main/spr_menu_pause_main_1.png"
#define SPRITE_MENU_PAUSE_MAIN_2 "assets/sprites/menus/pause/main/spr_menu_pause_main_2.png"
#define SPRITE_MENU_PAUSE_MAIN_3 "assets/sprites/menus/pause/main/spr_menu_pause_main_3.png"
#define SPRITE_MENU_PAUSE_MAIN_4 "assets/sprites/menus/pause/main/spr_menu_pause_main_4.png"
#define SPRITE_MENU_PAUSE_MAIN_5 "assets/sprites/menus/pause/main/spr_menu_pause_main_5.png"
// options
#define SPRITE_MENU_PAUSE_OPTIONS_1 "assets/sprites/menus/pause/options/spr_menu_pause_options_1.png"
#define SPRITE_MENU_PAUSE_OPTIONS_2 "assets/sprites/menus/pause/options/spr_menu_pause_options_2.png"
#define SPRITE_MENU_PAUSE_OPTIONS_3 "assets/sprites/menus/pause/options/spr_menu_pause_options_3.png"
#define SPRITE_MENU_PAUSE_OPTIONS_4 "assets/sprites/menus/pause/options/spr_menu_pause_options_4.png"
// confirm
#define SPRITE_MENU_PAUSE_CONFIRM_1 "assets/sprites/menus/pause/confirm/spr_menu_pause_confirm_1.png"
#define SPRITE_MENU_PAUSE_CONFIRM_2 "assets/sprites/menus/pause/confirm/spr_menu_pause_confirm_2.png"
// checkmearks
#define SPRITE_MENU_PAUSE_OPTIONS_CHECKMARK "assets/sprites/menus/pause/options/spr_menu_checkmark.png"
#define SPRITE_MENU_PAUSE_OPTIONS_CROSS "assets/sprites/menus/pause/options/spr_menu_cross.png"
// menu
#define SPRITE_MENU_WIN_1 "assets/sprites/menus/win/main/spr_menu_win_1.png"
#define SPRITE_MENU_WIN_2 "assets/sprites/menus/win/main/spr_menu_win_2.png"
#define SPRITE_MENU_WIN_3 "assets/sprites/menus/win/main/spr_menu_win_3.png"




#ifndef DRAW_H
#define DRAW_H


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

void renderMenu(SDL_Renderer *renderer, SDL_Window *window);

void renderMenuMain(SDL_Renderer *renderer, int scale);
void renderMenuPause(SDL_Renderer *renderer, int scale);
void renderMenuWin(SDL_Renderer *renderer, int scale);

void renderPNG(SDL_Renderer *renderer, SDL_Texture *texture, int pos_x, int pos_y, int width, int height);




#endif