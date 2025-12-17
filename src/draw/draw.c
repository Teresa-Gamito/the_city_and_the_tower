
#include "../../header/draw/draw.h"


int window_width = APP_WIDTH;
int window_height = APP_HEIGHT;

// sprites
// bottom tiles layer
static SDL_Texture *spr_wall_bottom[3];
static SDL_Texture *spr_ground[2][3];
static SDL_Texture *spr_pit[49];
static SDL_Texture *spr_pit1 = NULL;
static SDL_Texture *spr_wall_torch_lit_right = NULL;
static SDL_Texture *spr_wall_torch_lit_left = NULL;
static SDL_Texture *spr_wall_torch_unlit_right = NULL;
static SDL_Texture *spr_wall_torch_unlit_left = NULL;
static SDL_Texture *spr_plank_tile = NULL;
static SDL_Texture *spr_exit = NULL;
// items layer
static SDL_Texture *spr_relic = NULL;
static SDL_Texture *spr_torch = NULL;
static SDL_Texture *spr_plank = NULL;
// player layer
static SDL_Texture *spr_player[2][4];
// top tiles layer
static SDL_Texture *spr_wall_top = NULL;
// light layer
static SDL_Texture *spr_unlit = NULL;
// highlight layer
static SDL_Texture *spr_highlight_green = NULL;
static SDL_Texture *spr_highlight_yellow = NULL;
static SDL_Texture *spr_highlight_red = NULL;


static SDL_Texture *image_starting_screen_background = NULL;
static SDL_Texture *spr_menu_main_main = NULL;
static SDL_Texture *spr_menu_main_level_select = NULL;
static SDL_Texture *spr_menu_main_options = NULL;
static SDL_Texture *spr_menu_main_credits = NULL;
static SDL_Texture *spr_menu_main_pencil = NULL;

static SDL_Texture *spr_menu_pause_main[4];
static SDL_Texture *spr_menu_win_main[3];


static SDL_AudioSpec *snd_menu_main_option_select = NULL;
static SDL_AudioSpec *snd_menu_option_select = NULL;

static SDL_AudioSpec *snd_player_move[2];

static Uint8 *wav_data = NULL;
static Uint32 wav_data_len = 0;


void loadWindowIcon(SDL_Window *window) {

    char * png_path = NULL;

    SDL_Surface *surface = NULL;

    SDL_asprintf(&png_path, "%s%s", SDL_GetBasePath(), SPRITE_PLAYER_EMPTY);

    surface = SDL_LoadPNG(png_path);
    
    SDL_free(png_path);

    SDL_SetWindowIcon(window, surface);

    SDL_DestroySurface(surface);

}


void loadTextures(SDL_Renderer * renderer) {

    spr_wall_bottom[0] = loadTextureFromPNG(renderer, SPRITE_WALL_BOTTOM_1);
    spr_wall_bottom[1] = loadTextureFromPNG(renderer, SPRITE_WALL_BOTTOM_2);
    spr_wall_bottom[2] = loadTextureFromPNG(renderer, SPRITE_WALL_BOTTOM_3);
    spr_ground[0][0] = loadTextureFromPNG(renderer, SPRITE_GROUND_1_1);
    spr_ground[0][1] = loadTextureFromPNG(renderer, SPRITE_GROUND_1_2);
    spr_ground[0][2] = loadTextureFromPNG(renderer, SPRITE_GROUND_1_3);
    spr_ground[1][0] = loadTextureFromPNG(renderer, SPRITE_GROUND_2_1);
    spr_ground[1][1] = loadTextureFromPNG(renderer, SPRITE_GROUND_2_2);
    spr_ground[1][2] = loadTextureFromPNG(renderer, SPRITE_GROUND_2_3);
    spr_pit1 = loadTextureFromPNG(renderer, SPRITE_PIT);
    spr_wall_torch_lit_right = loadTextureFromPNG(renderer,SPRITE_WALL_TORCH_LIT_RIGHT);
    spr_wall_torch_lit_left = loadTextureFromPNG(renderer,SPRITE_WALL_TORCH_LIT_LEFT);
    spr_wall_torch_unlit_right = loadTextureFromPNG(renderer, SPRITE_WALL_TORCH_UNLIT_RIGHT);
    spr_wall_torch_unlit_left = loadTextureFromPNG(renderer, SPRITE_WALL_TORCH_UNLIT_LEFT);
    spr_plank_tile = loadTextureFromPNG(renderer,SPRITE_PLANK_TILE);
    spr_exit = loadTextureFromPNG(renderer, SPRITE_EXIT);

    spr_relic = loadTextureFromPNG(renderer, SPRITE_RELIC);
    spr_torch = loadTextureFromPNG(renderer, SPRITE_TORCH);
    spr_plank = loadTextureFromPNG(renderer, SPRITE_PLANK);

    spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_NONE] = loadTextureFromPNG(renderer, SPRITE_PLAYER_EMPTY);
    spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_TORCH] = loadTextureFromPNG(renderer, SPRITE_PLAYER_TORCH);
    spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_PLANK] = loadTextureFromPNG(renderer, SPRITE_PLAYER_PLANK);
    spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_RELIC] = loadTextureFromPNG(renderer, SPRITE_PLAYER_RELIC);
    spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_NONE] = loadTextureFromPNG(renderer, SPRITE_PLAYER_EMPTY);
    spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_TORCH] = loadTextureFromPNG(renderer, SPRITE_PLAYER_TORCH);
    spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_PLANK] = loadTextureFromPNG(renderer, SPRITE_PLAYER_PLANK);
    spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_RELIC] = loadTextureFromPNG(renderer, SPRITE_PLAYER_RELIC);

    spr_wall_top = loadTextureFromPNG(renderer, SPRITE_WALL_TOP);
    
    spr_unlit = loadTextureFromPNG(renderer, SPRITE_UNLIT);

    spr_highlight_green = loadTextureFromPNG(renderer, SPRITE_HIGHLIGHT_GREEN);
    spr_highlight_yellow = loadTextureFromPNG(renderer, SPRITE_HIGHLIGHT_YELLOW);
    spr_highlight_red = loadTextureFromPNG(renderer, SPRITE_HIGHLIGHT_RED);


    image_starting_screen_background = loadTextureFromPNG(renderer, SPRITE_MENU_MAIN_BACKGROUND);
    spr_menu_main_main = loadTextureFromPNG(renderer, SPRITE_MENU_MAIN_MAIN);
    spr_menu_main_level_select = loadTextureFromPNG(renderer, SPRITE_MENU_MAIN_LEVEL_SELECT);
    spr_menu_main_options = loadTextureFromPNG(renderer, SPRITE_MENU_MAIN_OPTIONS);
    spr_menu_main_credits = loadTextureFromPNG(renderer, SPRITE_MENU_MAIN_CREDITS);
    spr_menu_main_pencil = loadTextureFromPNG(renderer, SPRITE_MENU_MAIN_PENCIL);
    
    spr_menu_pause_main[0] = loadTextureFromPNG(renderer, SPRITE_MENU_PAUSE_1);
    spr_menu_pause_main[1] = loadTextureFromPNG(renderer, SPRITE_MENU_PAUSE_2);
    spr_menu_pause_main[2] = loadTextureFromPNG(renderer, SPRITE_MENU_PAUSE_3);
    spr_menu_pause_main[3] = loadTextureFromPNG(renderer, SPRITE_MENU_PAUSE_4);

    spr_menu_win_main[0] = loadTextureFromPNG(renderer, SPRITE_MENU_WIN_1);
    spr_menu_win_main[1] = loadTextureFromPNG(renderer, SPRITE_MENU_WIN_2);
    spr_menu_win_main[2] = loadTextureFromPNG(renderer, SPRITE_MENU_WIN_3);

}

void loadTexturesTilesetPit(SDL_Renderer * renderer) {

    

}

SDL_Texture * loadTextureFromPNG(SDL_Renderer * renderer, const char * path) {

    char * png_path = NULL;

    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;

    SDL_asprintf(&png_path, "%s%s", SDL_GetBasePath(), path);

    surface = SDL_LoadPNG(png_path);
    
    SDL_free(png_path);

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    SDL_DestroySurface(surface);
    
    return texture;

}


void renderLevel(SDL_Renderer * renderer, SDL_Window * window) {

    SDL_GetWindowSize(window, &window_width, &window_height);

    double sprite_scale = window_width / ((double)NUM_TILES_WIDTH * (double)SPRITE_SIZE);
    int pos_x = ((window_width / 2/ sprite_scale) - (level_active.width / 2 * SPRITE_SIZE) - (SPRITE_SIZE/2)) ;
    int pos_y = ((window_height / 2/ sprite_scale) - (level_active.height / 2 * SPRITE_SIZE) - (SPRITE_SIZE/2));


    SDL_SetRenderDrawColor(renderer, 0x1a, 0x1e, 0x2b, SDL_ALPHA_OPAQUE_FLOAT);
    SDL_RenderClear(renderer);

    renderLayerTilesBottom(renderer, pos_x, pos_y);
    renderLayerTilesMiddle(renderer, pos_x, pos_y);
    renderLayerItems(renderer, pos_x, pos_y + OFFSET_PIXELS_LAYER_ITEMS);
    renderLayerPLayer(renderer, pos_x, pos_y + OFFSET_PIXELS_LAYER_PLAYER);
    renderLayerTilesTop(renderer, pos_x, pos_y + OFFSET_PIXELS_LAYER_TILES_TOP);
    renderLayerLight(renderer, pos_x, pos_y);
    if (highlight.is_on) renderLayerHighlight(renderer, pos_x, pos_y);

    SDL_SetRenderScale(renderer, sprite_scale, sprite_scale);

    rendererPresent(renderer);

}

void rendererPresent(SDL_Renderer * renderer) {

    SDL_RenderPresent(renderer);

}


SDL_Texture * getTextureFromChar(char tile, int layer, int pos_x, int pos_y) {

    if (level_active.light[pos_y][pos_x] == CHAR_UNLIT) return NULL;

    int rand_num = (pos_x + pos_y) % 3;
    int chekered_pos = (pos_x + pos_y) % 2;

    switch (layer) {

    case LAYER_TILES_BOTTOM:

        switch (tile) {

        case CHAR_WALL:
            return spr_wall_bottom[rand_num];
            break;

        case CHAR_GROUND:
        case CHAR_WALL_TORCH_LIT:
        case CHAR_WALL_TORCH_UNLIT:
        case CHAR_EXIT:
            return spr_ground[chekered_pos][rand_num];
            break;

        case CHAR_PIT:
        case CHAR_PLANK_TILE:
            return spr_pit1;
            break;
        
        }
        break;

    case LAYER_TILES_MIDDLE:

        switch (tile) {

        case CHAR_PLANK_TILE:
            return spr_plank_tile;
            break;

        case CHAR_EXIT:
            return spr_exit;
            break;
        
        }
        break;
    

    case LAYER_ITEMS:

        switch (tile) {

        case CHAR_RELIC:
            return spr_relic;
            break;
            
        case CHAR_TORCH:
            return spr_torch;
            break;
            
        case CHAR_PLANK:
            return spr_plank;
            break;

        }
        break;
            
    case LAYER_PLAYER:

        switch (tile) {

        case CHAR_PLAYER:

            switch (player.item) {
            
            case CHAR_EMPTY:
                if (player.sprite_direction) return spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_NONE];
                else return spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_NONE];
                break;

            case CHAR_TORCH:
                if (player.sprite_direction) return spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_TORCH];
                else return spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_TORCH];
                break;
            
            case CHAR_PLANK:
                if (player.sprite_direction) return spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_PLANK];
                else return spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_PLANK];
                break;
                
            case CHAR_RELIC:
                if (player.sprite_direction) return spr_player[PLAYER_SPRITE_DIRECTION_RIGHT][PLAYER_SPRITE_ITEM_RELIC];
                else return spr_player[PLAYER_SPRITE_DIRECTION_LEFT][PLAYER_SPRITE_ITEM_RELIC];
                break;

            }
            break;
            
        }
        break;
    
    case LAYER_TILES_TOP:
        switch (tile) {
            
        case CHAR_WALL_TORCH_LIT:
            return getTextureWallTorchLit(pos_x, pos_y);
            break;

        case CHAR_WALL_TORCH_UNLIT:
            return getTextureWallTorchUnlit(pos_x, pos_y);
            break;
        
        case CHAR_WALL:
            return spr_wall_top;
            break;
        }
        break;
    
    case LAYER_LIGHT:
        if (tile == CHAR_UNLIT) return spr_unlit;
        break;

    case LAYER_HIGHLIGHT:
        switch (tile) {

        case CHAR_HIGHLIGHT_GREEN:
            return spr_highlight_green;
            break;
        
        case CHAR_HIGHLIGHT_YELLOW:
            return spr_highlight_yellow;
            break;

        case CHAR_HIGHLIGHT_RED:
            return spr_highlight_red;
            break;
        }
        break;

    }
}

SDL_Texture * getTextureWallTorchUnlit(int pos_x, int pos_y) {

    if (level_active.tiles[pos_y][pos_x + 1] == CHAR_WALL) return spr_wall_torch_unlit_right;
    else return spr_wall_torch_unlit_left;

}

SDL_Texture * getTextureWallTorchLit(int pos_x, int pos_y) {

    if (level_active.tiles[pos_y][pos_x + 1] == CHAR_WALL) return spr_wall_torch_lit_right;
    else return spr_wall_torch_lit_left;

}

void renderSprite(SDL_Renderer * renderer, SDL_Texture * texture, int pos_x , int pos_y) {
    
    SDL_FRect sprite = {
        pos_x,
        pos_y,
        SPRITE_SIZE,
        SPRITE_SIZE
    };

    SDL_RenderTexture(renderer, texture, NULL, &sprite);
}



void renderLayerTilesBottom(SDL_Renderer * renderer, int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height - 1; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            if (!(level_active.light[i + 1][j] == CHAR_UNLIT && level_active.tiles[i][j] == CHAR_WALL))

                renderSprite(
                    renderer, 
                    getTextureFromChar(level_active.tiles[i][j], LAYER_TILES_BOTTOM, j, i), 
                    pos_x + (j * SPRITE_SIZE), 
                    pos_y + (i * SPRITE_SIZE)
                );

        }
    }
}

void renderLayerTilesMiddle(SDL_Renderer * renderer, int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height - 1; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            renderSprite(
                renderer, 
                getTextureFromChar(level_active.tiles[i][j], LAYER_TILES_MIDDLE, j, i), 
                pos_x + (j * SPRITE_SIZE), 
                pos_y + (i * SPRITE_SIZE)
            );

        }
    }

}

void renderLayerItems(SDL_Renderer * renderer, int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            renderSprite(
                renderer, 
                getTextureFromChar(level_active.objects[i][j], LAYER_ITEMS, j, i), 
                pos_x + (j * SPRITE_SIZE), 
                pos_y + (i * SPRITE_SIZE)
            );

        }
    }

}

void renderLayerPLayer(SDL_Renderer * renderer, int pos_x, int pos_y) {

    int x = pos_x + (player.pos_x * SPRITE_SIZE);
    int y = pos_y + (player.pos_y * SPRITE_SIZE);

    renderSprite(
        renderer, 
        getTextureFromChar(CHAR_PLAYER, LAYER_PLAYER, player.pos_x, player.pos_y), 
        x, 
        y
    );

}

void renderLayerTilesTop(SDL_Renderer * renderer, int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            renderSprite(
                renderer,
                getTextureFromChar(level_active.tiles[i][j], LAYER_TILES_TOP, j, i), 
                pos_x + (j * SPRITE_SIZE), 
                pos_y + (i * SPRITE_SIZE)
            );

        }
    }
}

void renderLayerLight(SDL_Renderer * renderer, int pos_x, int pos_y) {

    for(int i = 0 ; i < level_active.height; i++) {
        for(int j = 0 ; j < level_active.width; j++) {

            if (level_active.tiles[i][j] == CHAR_WALL && level_active.light[i][j] == CHAR_UNLIT)

                renderSprite(
                    renderer, 
                    spr_unlit, 
                    pos_x + (j * SPRITE_SIZE), 
                    pos_y + (i * SPRITE_SIZE) + OFFSET_PIXELS_LAYER_TILES_TOP
                );

        }
    }

}

void renderLayerHighlight(SDL_Renderer * renderer, int pos_x, int pos_y) {

    char highlight_status;

    int x = pos_x + (highlight.pos_x * SPRITE_SIZE);
    int y = pos_y + (highlight.pos_y * SPRITE_SIZE);

    if (itemCanBeDropped(highlight.pos_x, highlight.pos_y) && playerHasItem()) 
        highlight_status = CHAR_HIGHLIGHT_YELLOW;

    else if (!itemCanBeDropped(highlight.pos_x, highlight.pos_y) && playerHasItem()) 
        highlight_status = CHAR_HIGHLIGHT_RED;
    
    else highlight_status = CHAR_HIGHLIGHT_GREEN;

    renderSprite(
        renderer, 
        getTextureFromChar(highlight_status, LAYER_HIGHLIGHT, highlight.pos_x, highlight.pos_y), 
        x, 
        y
    );

}





void renderMenu(SDL_Renderer *renderer, SDL_Window *window, int menu, int submenu, int option) {

    SDL_GetWindowSize(window, &window_width, &window_height);

    double scale = window_width / ((double)NUM_TILES_WIDTH * (double)SPRITE_SIZE);

    switch (menu) {

    case MENU_MAIN:
        SDL_SetRenderDrawColor(renderer, 0x1a, 0x1e, 0x2b, SDL_ALPHA_OPAQUE_FLOAT);
        SDL_RenderClear(renderer);
        renderMenuMain(renderer, submenu, option, scale);  
        break;
    
    case MENU_PAUSE:
        renderMenuPause(renderer, submenu, option, scale);
        break;

    case MENU_WIN:
        renderMenuWin(renderer, submenu, option, scale);
        break;

    }

    SDL_SetRenderScale(renderer, scale, scale);

    rendererPresent(renderer);
}

void renderMenuMain(SDL_Renderer *renderer, int submenu, int option, int scale) {

    int pencil_x, pencil_y;
    renderPNG(
        renderer, 
        image_starting_screen_background, 
        0, 
        0, 
        window_width / scale, 
        window_height / scale
    );

    switch (submenu) {
    case SUBMENU_MAIN_MAIN:
        renderPNG(
            renderer, 
            spr_menu_main_main, 
            OFFSET_MENU_MAIN_X, 
            OFFSET_MENU_MAIN_Y, 
            WIDTH_MENU_MAIN, 
            HEIGHT_MENU_MAIN
        );
        switch (gamestate.current_option) {
        case OPTION_MAIN_MAIN_LEVEL_SELECT:
            pencil_x = OFFSET_OPTION_MENU_MAIN_MAIN_LEVEL_SELECT_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_MAIN_LEVEL_SELECT_Y;
            break;

        case OPTION_MAIN_MAIN_OPTIONS:
            pencil_x = OFFSET_OPTION_MENU_MAIN_MAIN_OPTIONS_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_MAIN_OPTIONS_Y;
            break;

        case OPTION_MAIN_MAIN_CREDITS:
            pencil_x = OFFSET_OPTION_MENU_MAIN_MAIN_CREDITS_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_MAIN_CREDITS_Y;
            break;

        case OPTION_MAIN_MAIN_EXIT:
            pencil_x = OFFSET_OPTION_MENU_MAIN_MAIN_EXIT_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_MAIN_EXIT_Y;
            break;
        }
        renderPNG(
            renderer, 
            spr_menu_main_pencil, 
            OFFSET_MENU_MAIN_X + pencil_x, 
            OFFSET_MENU_MAIN_Y + pencil_y, 
            WIDTH_MENU_MAIN_PENCIL, 
            HEIGHT_MENU_MAIN_PENCIL
        );
        break;
    
    case SUBMENU_MAIN_LEVEL_SELECT:
        renderPNG(
            renderer, 
            spr_menu_main_level_select, 
            OFFSET_MENU_MAIN_X, 
            OFFSET_MENU_MAIN_Y, 
            WIDTH_MENU_MAIN, 
            HEIGHT_MENU_MAIN
        );
        switch (gamestate.current_option) {
        case 1:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_1_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_1_Y;
            break;

        case 2:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_2_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_2_Y;
            break;

        case 3:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_3_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_3_Y;
            break;

        case 4:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_4_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_4_Y;
            break;

        case 5:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_5_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_5_Y;
            break;

        case 6:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_6_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_6_Y;
            break;

        case 7:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_7_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_7_Y;
            break;

        case 8:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_8_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_8_Y;
            break;

        case 9:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_9_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_9_Y;
            break;

        case 10:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_10_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_10_Y;
            break;

        case OPTION_MAIN_CREDITS_BACK:
            pencil_x = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_BACK_X;
            pencil_y = OFFSET_OPTION_MENU_MAIN_LEVEL_SELECT_BACK_Y;
            break;
        }
        renderPNG(
            renderer, 
            spr_menu_main_pencil, 
            OFFSET_MENU_MAIN_X + pencil_x, 
            OFFSET_MENU_MAIN_Y + pencil_y, 
            WIDTH_MENU_MAIN_PENCIL, 
            HEIGHT_MENU_MAIN_PENCIL
        );
        break;
    
    case SUBMENU_MAIN_OPTIONS:
        renderPNG(
            renderer, 
            spr_menu_main_options, 
            OFFSET_MENU_MAIN_X, 
            OFFSET_MENU_MAIN_Y, 
            WIDTH_MENU_MAIN, 
            HEIGHT_MENU_MAIN
        );
        switch (gamestate.current_option) {
        case OPTION_MAIN_OPTIONS_MAIN_SOUND:
            renderPNG(
                renderer, 
                spr_menu_main_pencil, 
                OFFSET_MENU_MAIN_X + OFFSET_OPTION_MENU_MAIN_OPTIONS_MAIN_SOUND_X, 
                OFFSET_MENU_MAIN_Y + OFFSET_OPTION_MENU_MAIN_OPTIONS_MAIN_SOUND_Y, 
                WIDTH_MENU_MAIN_PENCIL, 
                HEIGHT_MENU_MAIN_PENCIL
            );
            break;

        case OPTION_MAIN_OPTIONS_SFX:
            renderPNG(
                renderer, 
                spr_menu_main_pencil, 
                OFFSET_MENU_MAIN_X + OFFSET_OPTION_MENU_MAIN_OPTIONS_SFX_X, 
                OFFSET_MENU_MAIN_Y + OFFSET_OPTION_MENU_MAIN_OPTIONS_SFX_Y, 
                WIDTH_MENU_MAIN_PENCIL, 
                HEIGHT_MENU_MAIN_PENCIL
            );
            break;

        case OPTION_MAIN_OPTIONS_MUSIC:
            renderPNG(
                renderer, 
                spr_menu_main_pencil, 
                OFFSET_MENU_MAIN_X + OFFSET_OPTION_MENU_MAIN_OPTIONS_MUSIC_X, 
                OFFSET_MENU_MAIN_Y + OFFSET_OPTION_MENU_MAIN_OPTIONS_MUSIC_Y, 
                WIDTH_MENU_MAIN_PENCIL, 
                HEIGHT_MENU_MAIN_PENCIL
            );
            break;

        case OPTION_MAIN_OPTIONS_BACK:
            renderPNG(
                renderer, 
                spr_menu_main_pencil, 
                OFFSET_MENU_MAIN_X + OFFSET_OPTION_MENU_MAIN_OPTIONS_BACK_X, 
                OFFSET_MENU_MAIN_Y + OFFSET_OPTION_MENU_MAIN_OPTIONS_BACK_Y, 
                WIDTH_MENU_MAIN_PENCIL, 
                HEIGHT_MENU_MAIN_PENCIL
            );
            break;
        }
        break;
    
    case SUBMENU_MAIN_CREDITS:
        renderPNG(
            renderer, 
            spr_menu_main_credits, 
            OFFSET_MENU_MAIN_X, 
            OFFSET_MENU_MAIN_Y, 
            WIDTH_MENU_MAIN, 
            HEIGHT_MENU_MAIN
        );
        renderPNG(
            renderer, 
            spr_menu_main_pencil, 
            OFFSET_MENU_MAIN_X + OFFSET_OPTION_MENU_MAIN_CREDITS_BACK_X, 
            OFFSET_MENU_MAIN_Y + OFFSET_OPTION_MENU_MAIN_CREDITS_BACK_Y, 
            WIDTH_MENU_MAIN_PENCIL, 
            HEIGHT_MENU_MAIN_PENCIL
        );
        break;

    }  
}

void renderMenuPause(SDL_Renderer *renderer, int submenu, int option, int scale) {

    float w,h;

    SDL_GetTextureSize(spr_menu_pause_main[option], &w, &h);

    int pos_x = window_width / 4 - w /2;
    int pos_y = window_height / 4 - h /2;

    renderPNG(renderer, spr_menu_pause_main[option], pos_x, pos_y, w, h);
}

void renderMenuWin(SDL_Renderer *renderer, int submenu, int option, int scale) {

    float w,h;

    SDL_GetTextureSize(spr_menu_win_main[option], &w, &h);

    int pos_x = window_width / 4 - w / 2;
    int pos_y = window_height / 4 - h / 2;

    renderPNG(renderer, spr_menu_win_main[option], pos_x, pos_y, w, h);

}



void renderPNG(SDL_Renderer *renderer, SDL_Texture *texture, int pos_x, int pos_y, int width, int height) {

    SDL_FRect image;

    image.x = pos_x;
    image.y = pos_y;
    image.w = width;
    image.h = height;

    SDL_RenderTexture(renderer, texture, NULL, &image);


}



void loadSounds() {

    /* snd_menu_main_option_select = SDL_LoadWAV(SOUND_MENU_MAIN_OPTION_SELECT, );
    snd_menu_option_select = SDL_LoadWAV(SOUND_MENU_OPTION_SELECT);

    snd_player_move[0] = SDL_LoadWAV(SOUND_PLAYER_MOVE_1);
    snd_player_move[1] = SDL_LoadWAV(SOUND_PLAYER_MOVE_2); */

}

SDL_AudioSpec loadSoundFromWAV(const char *file_path) {

    char *snd_path = NULL;

    SDL_asprintf(&snd_path, "%s%s", SDL_GetBasePath(), file_path);

    //SDL_LoadWAV();

}
