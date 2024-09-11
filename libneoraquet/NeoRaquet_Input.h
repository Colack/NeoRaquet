#ifndef NEORAQUET_INPUT_H
#define NEORAQUET_INPUT_H

#include <SDL2/SDL.h>

extern const Uint8* sdlkeys;
extern uint8_t sdlmouse;
extern uint8_t prevmouse;

extern const uint8_t NEORAQUET_MOUSE_RIGHT;
extern const uint8_t NEORAQUET_MOUSE_LEFT;
extern const uint8_t NEORAQUET_MOUSE_MIDDLE;

extern Uint8 prevkeys[322];

int NeoRaquet_KeyCheck(SDL_Scancode nkey);
int NeoRaquet_KeyCheck_Pressed(SDL_Scancode nkey);
int NeoRaquet_KeyCheck_Released(SDL_Scancode nkey);
int NeoRaquet_MouseCheck(int sdlbutton);
int NeoRaquet_MouseCheck_Pressed(int sdlbutton);
int NeoRaquet_MouseCheck_Released(int sdlbutton);

#endif
