/*
    This is the main entry file for my C game engine, NeoRaquet.

    NeoRaquet is a simple 2D game engine that uses SDL2 for rendering and input handling.

    Credits to the following resources:
        - Raquet by @sinislosion
        - SDL2
*/

#ifndef NEORAQUET_H
#define NEORAQUET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "NeoRaquet_Types.h"
#include "NeoRaquet_Input.h"
#include "NeoRaquet_Audio.h"
#include "NeoRaquet_Render.h"
#include "NeoRaquet_Actor.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 360
#define SCREEN_SCALE 2
extern const float FRAMERATE_CAP;
#define WINDOW_TITLE "My Neo-Raquet Program"
#define AUDIO_SAMPLE_RATE 44100
#define VSYNC

extern SDL_Window *gWindow;
extern uint8_t gFullscreen;
extern SDL_Renderer *gRenderer;
extern SDL_Rect gRectScrn;
extern SDL_Event e;
extern Camera camera;
extern Uint64 start_tick;

void NeoRaquet_Create();     // User will declare this function in their main.c file
void NeoRaquet_Loop();      // User will declare this function in their main.c file
int NeoRaquet_Init();
void NeoRaquet_MainLoop();

#endif
