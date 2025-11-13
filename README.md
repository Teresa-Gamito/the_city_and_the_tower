# The City and the Tower
Game Code

gcc main.c player.c level.c draw.c item.c highlight.c debug.c light.c menu.c tools.c -o game && game.exe

Level creating conventions:
 - Create a file in the "level" folder named lvlXX.txt with "XX" being replaced by the level number
 - The text should be split into the three layers separeated by '-'
 - Levels can be a maximum of 66 tiles wide and 30 tiles in height 
 - All three layers must be the same dimentions

Labels for level creation:
    Tiles layer:
        'W' - Wall
        'V' - Pit
        'G' - Empty (Ground)
        'I' - Wall Torch Lit
        'O' - Wall Torch Unlit
    Items layer:
        'R' - Relic
        'T' - Torch
        'P' - Player
        'L' - Plank
    Darkness layer:
        '0' - Unlit
        '1' - Lit
    Highlight
        'H' - Highlight