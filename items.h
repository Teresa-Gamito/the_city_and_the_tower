#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 20

#define TORCH_RADIUS 3

typedef struct {
   int pos_x;
   int pos_y;
   char type;
      // T - torch; R - Relic; L - Plank
} Item;

// items will be removed from the map and turned into objects
// items will be held in the stack
extern Item item_stack[STACK_SIZE];

void getItemsFromLevel(); // removes the items from the level and adds them to the stack

// stack related functions
void swap(int pos1, int pos2); // swap positions within the stack
Item pop(int pos_x, int pos_y); // search and remove an item from the stack
void push(Item item); // put an item in the stack