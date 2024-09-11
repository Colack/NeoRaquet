#include "NeoRaquet_Input.h"

const Uint8* sdlkeys;
uint8_t sdlmouse;
uint8_t prevmouse;

const uint8_t NEORAQUET_MOUSE_RIGHT = 4;
const uint8_t NEORAQUET_MOUSE_LEFT = 1;
const uint8_t NEORAQUET_MOUSE_MIDDLE = 2;

Uint8 prevkeys[322];

int NeoRaquet_KeyCheck(SDL_Scancode nkey) {
    return sdlkeys[nkey];
}

int NeoRaquet_KeyCheck_Pressed(SDL_Scancode nkey) {
    return (prevkeys[nkey] != sdlkeys[nkey] && sdlkeys[nkey] != 0);
}

int NeoRaquet_KeyCheck_Released(SDL_Scancode nkey) {
    return (prevkeys[nkey] != sdlkeys[nkey] && sdlkeys[nkey] != 1);
}

int NeoRaquet_MouseCheck(int sdlbutton) {
    return sdlbutton & sdlmouse;
}

int NeoRaquet_MouseCheck_Pressed(int sdlbutton) {
    return ((prevmouse & sdlbutton) != (sdlmouse & sdlbutton) && (sdlmouse & sdlbutton) != 0);
}

int NeoRaquet_MouseCheck_Released(int sdlbutton) {
    return ((prevmouse & sdlbutton) != (sdlmouse & sdlbutton) && (sdlmouse & sdlbutton) != 1);
}
