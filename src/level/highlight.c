
#include "../../header/level/highlight.h"


Highlight highlight = {0, 0, 0};
SDL_TimerID timer_id;

void highlightSpawn() {

    highlight.pos_x = player.pos_x;
    highlight.pos_y = player.pos_y;
    highlight.is_on = 1;

    logPrint("Spawned highlight\n");

}

void highlightDespawn() {

    highlight.is_on = 0;
    
    logPrint("Despawned highlight\n");

}

void highlightMove(int pos_x, int pos_y) {

    highlight.pos_x = pos_x;
    highlight.pos_y = pos_y;

}

void highlightAction(int input) {

    switch (input) {

    case HIGHLIGHT_RESET:
        timer_id = SDL_AddTimer(DELAY_HIGHLIGHT_RESET_POSITION, highlightResetPosition, NULL);
        break;

    case HIGHLIGHT_MOVE_UP:
        highlightMove(player.pos_x, player.pos_y - 1);
        break;

    case HIGHLIGHT_MOVE_DOWN:
        highlightMove(player.pos_x, player.pos_y + 1);
        break;

    case HIGHLIGHT_MOVE_LEFT:
        highlightMove(player.pos_x - 1, player.pos_y);
        break;

    case HIGHLIGHT_MOVE_RIGHT:
        highlightMove(player.pos_x + 1, player.pos_y);
        break;

    }
}

Uint32 highlightResetPosition(void *userdata, SDL_TimerID timerID, Uint32 interval) {

        highlightMove(player.pos_x, player.pos_y);

        return 0;

}


