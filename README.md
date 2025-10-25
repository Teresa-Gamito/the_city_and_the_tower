# The City and the Tower
Game Code

player structure must switch with the 'P' in the map location:
    Find 'P' in map
    Assign 'P' cordinates to structure player position
    Delete 'P'

Level creating conventions:
 - Create a file named lvlXX.txt with "XX" being replaced by the level number
 - The text should be split into the three layers separeated by '-'
 - Levels can be a maximum of 66 tiles wide and 30 tiles in height 
 - All three layers must be the same dimentions

Player and items will be treated as objects:
When the level is started, the program reads the objects layer and converts any item/player into an object, removing them from the map.

Labels for level creation:
    Tiles layer:
        'W' - Wall
        'P' - Pit
        '0' - Empty (Ground)
    Items layer:
        'R' - Relic
        'T' - Torch
        'P' - Player
        'L' - Ladder
    Darkness layer:
        0 - unlit
        1 - lit

What we cant add right now:
 - Animations
 - Keylogger
 - Images
 - Audio
 - Time
 - Following events (we can but they will be processed at the same time)

What we can add:
 - File access to read levels or save data using stdio.h