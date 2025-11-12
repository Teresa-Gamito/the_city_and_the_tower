
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "../header/level/level.h"
#include "../header/level/light.h"
#include "../header/objects/player.h"
#include "../header/debug.h"
#include "../header/tools.h"

#define SIGN(x) x < 0 ? -1 : x > 0 ? 1 : 0

void lightReset() {

    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {

            level_active.light[i][j] = level_active.starting_light[i][j];

        }
    }

}

void lightPorcessLayers() {

    logPrint("Processing light\n");

    lightReset();
    
    for (int i = 0; i < level_active.height; i++) {
        for (int j = 0; j < level_active.width; j++) {

            if (level_active.objects[i][j] == CHAR_TORCH) {
                lightProcess(j, i, LIGHT_RADIUS_TORCH);
            }
            else if (level_active.tiles[i][j] == CHAR_WALL_TORCH_LIT) {
                lightProcess(j, i, LIGHT_RADIUS_WALL_TORCH);
            }

        }
    }
    if (player.item == CHAR_TORCH) {
        lightProcess(player.pos_x, player.pos_y, LIGHT_RADIUS_TORCH);
        logPrint("Processing player light\n");
    }
    logPrint("\n");
}

void lightProcess(int pos_x, int pos_y, double light_radius) {

    logPrint("Light source at position x:%d y:%d\n", pos_x, pos_y);

    for (int i = -light_radius; i <= light_radius; i++) {
        for (int j = -light_radius; j <= light_radius; j++) {

            if (getDistance(0, 0, j, i) <= light_radius)
                if (!lightHasCollision(pos_x, pos_y, pos_x + i, pos_y + j))
                    level_active.light[pos_y + i][pos_x + j] = CHAR_LIT; 

        }
    }
}

bool lightHasCollision(int pos_source_x, int pos_source_y, int pos_final_x, int pos_final_y) {
    
    double distance = getDistance(pos_source_x, pos_source_y, pos_final_x, pos_final_y);
    double angle = atan2(pos_final_y - pos_source_y, pos_final_x - pos_source_x);

    double increment = 0.1;

    int x, y;

    for (double d = 0; d < distance; d += increment) {

        x = pos_source_x + round(d * sin(angle));
        y = pos_source_y + round(d * cos(angle));

        if (tileBlocksLight(x, y)) {
            level_active.light[y][x] = CHAR_LIT; 
            return 1;
        }
    }
    return 0;
}
