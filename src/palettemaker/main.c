/*
    Palette Maker

    This is a program that allows you to create and modify color palettes, then save them to a .pal file, which can be used in NeoRaquet.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

typedef struct Color {
    Uint8 r; // Red
    Uint8 g; // Green
    Uint8 b; // Blue
    Uint8 a; // Alpha
} Color;