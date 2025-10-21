
#include <stdio.h>
#include <stdbool.h>

// Configurations
#define MAP_ROWS 12
#define MAP_COLS 12

// Tile codes
#define TILE_WALL 'W'
#define TILE_FLOOR 'F'
#define TILE_POTION 'P'

// Player structure
struct Player {
    int level , attack , defense;
    int position_x , position_y;
};
struct Player one = {1 , 1 , 1 , 4 , 4};
// Globals (Map and Player)
char map [MAP_ROWS][MAP_COLS] = {
    {'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , 'W' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'F' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'F' , 'F' , 'F' , 'F' , 'F', 'F' , 'P' , 'F' , 'F' , 'F' , 'W'},
    {'W' , 'W' , 'W' , 'W' , 'W' , 'W', 'W' , 'W' , 'W' , 'W' , 'W' , 'W'}
};


// Functions to be implemented
void printMenu(void);
void printMap(void);
void printPlayerStats(void);

char readUserInput(void);
void movePlayer(char dir);

bool isTileWalkable(char t);
int inBounds(int y, int x);

// ====== Main ======
int main(void) {
    while(1) {
        printMap();
        movePlayer(readUserInput());
            printf("\n\n\n\n\n\n");
    }    
    return 0;
    
}

// Implementations
void printMap() {

    for(int x = 0 ; x < MAP_COLS ; x++) {

        for(int y = 0 ; y < MAP_ROWS ; y++) {

            if(x == one.position_x && y == one.position_y)
                printf("%c ", '&');

            else if(map[x][y] == 'W')
                printf("%c ", 'N');

            else if(map[x][y] == 'F')
                printf("%c ", '.');
                
            else if(map[x][y] == 'P')
                printf("%c ", 'P');

        }
        printf("\n");

    }

}

char readUserInput() {
    char input;
    scanf("%c", &input);
    return input;
}

void movePlayer(char dir) {

    if(dir == 'w') {
        if(isTileWalkable(map[one.position_x-1][one.position_y]))
            one.position_x --;
    }   

    else if(dir == 's') {
        if(isTileWalkable(map[one.position_x+1][one.position_y]))
            one.position_x ++;
    }

    else if(dir == 'a') {
        if(isTileWalkable(map[one.position_x][one.position_y-1]))
            one.position_y --;
    }

    else if(dir == 'd') {
        if(isTileWalkable(map[one.position_x][one.position_y+1]))
            one.position_y ++;
    }

}

bool isTileWalkable(char t) {
    if(t != 'W')
        return 1;
    else return 0;

}
