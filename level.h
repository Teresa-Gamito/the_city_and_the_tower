#include <stdio.h>
#include <stdbool.h>

#define MAX_WIDTH 60
#define MAX_HIGHT 33

struct Level {
    char tiles[MAX_HIGHT][MAX_WIDTH];
    char items[MAX_HIGHT][MAX_WIDTH];
    int darkness[MAX_HIGHT][MAX_WIDTH];
};

void level_print(Level level);
