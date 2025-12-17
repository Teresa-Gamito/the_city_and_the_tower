cmake_minimum_required(VERSION 3.16)
project(game)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

include_directories(header)

# Create your game executable target as usual
add_executable(game WIN32 
    header/main.h
    header/debug.h
    header/tools.h
    header/level/level.h
    header/level/highlight.h
    header/level/light.h
    header/level/highlight.h
    header/level/objects/player.h
    header/level/objects/item.h
    header/draw/draw.h
    header/draw/menu.h
    src/main.c
    src/debug.c
    src/tools.c
    src/level/level.c
    src/level/highlight.c
    src/level/light.c
    src/level/highlight.c
    src/level/objects/player.c
    src/level/objects/item.c
    src/draw/draw.c
    src/draw/menu.c
)

# Link to the actual SDL3 library.
target_link_libraries(game PRIVATE SDL3::SDL3)