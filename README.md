# The City and the Tower

Compiling command:

cmake --build build && cd build && game.exe && cd..

gcc src/main.c src/tools.c src/debug.c src/draw/draw.c src/draw/menu.c src/level/level.c src/level/highlight.c src/level/light.c src/level/objects/player.c src/level/objects/item.c -o game -I "C:\SDL3-3.2.26\x86_64-w64-mingw32\include" -L "C:\SDL3-3.2.26\x86_64-w64-mingw32\lib" -lSDL3 && game.exe

TODO:
if we have time:
    add algorithm for planks


Presentation Parts:
    Trailer (Thursday 18th):
        60 sec max fullHD 30fps
        Include uni logo and studio logo / names
        Focus on narrative and gameplay (interlocked maybe)
        no menus and generic screen
        engaging and avoid spoilers
        mention it is a game for windows pc    
    Presentation:
        present vertical slice
        5-min time limit
        trailer doesnt count to time
        Same structure as prototype presentation
        Update
        The trailer already shows context
        use screenshots and gifs from the game
        "Now for the demonstration" slide
    Live Demonstration:
        dont avoid spoilers
        cover basic mechanics and move to the interesting situations
        use cheats
        narrate as a team
        go back to the thank you slide
After:
    Playtesting and assessment
    Bring laptop
    take notes from observations and feedback







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