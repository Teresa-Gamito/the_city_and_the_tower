# The City and the Tower
Game Code

Compiling command:
gcc src/main.c src/tools.c src/debug.c src/draw/draw.c src/draw/menu.c src/level/level.c src/level/highlight.c src/level/light.c src/level/objects/player.c src/level/objects/item.c -o game -I "C:\SDL3-3.2.26\x86_64-w64-mingw32\include" -L "C:\SDL3-3.2.26\x86_64-w64-mingw32\lib" -lSDL3 && game.exe

TODO: (in order)
images
player input
menus




Level creating conventions:
 - Create a file in the "level" folder named lvlXX-Y.txt with "XX" being replaced by the level number and "Y" the phase number
 - The text should be split into the three layers separeated by '-'
 - Levels can be a maximum of 60 tiles wide and 33 tiles in height 
 - All three layers must have the same dimentions

Labels for level creation:
    Tiles layer:
        'W' - Wall
        'G' - Ground
        'V' - Pit
        'I' - Wall Torch Lit
        'O' - Wall Torch Unlit
        'Y' - Plank Tile
        'E' - Exit
    Items layer:
        'R' - Relic
        'T' - Torch
        'P' - Player
        'L' - Plank
        '0' - Empty
    Darkness layer:
        '0' - Unlit
        '1' - Lit
    Highlight
        'H' - Highlight