#ifndef NEORAQUET_PALETTE_H
#define NEORAQUET_PALETTE_H

/*
    This is the Palette file. It contains color palette functions
    and the global color palette.
*/

#include <SDL2/SDL.h>

typedef struct Color {
    Uint8 r; // Red
    Uint8 g; // Green
    Uint8 b; // Blue
    Uint8 a; // Alpha
} Color;

/*
    Palettes contains 8 colors, which can be modified.
*/
typedef struct Palette {
    Color colors[8];    // The actual colors
    char name[32];      // The name of the palette.
} Palette;

#endif