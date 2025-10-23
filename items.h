#include <stdio.h>
#include <stdbool.h>

#define TORCH_RADIUS 3

typedef struct Torch {
   int radius;
   int pos_x;
   int pos_y;
} Torch;

typedef struct Plank {
   int pos_x;
   int pos_y;
} Plank;

typedef struct Relic {
   int pos_x;
   int pos_y;
   bool wasPickedUp;
} Relic;