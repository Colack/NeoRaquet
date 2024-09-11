#ifndef NEORAQUET_AUDIO_H
#define NEORAQUET_AUDIO_H

#include <SDL2/SDL_mixer.h>

typedef Mix_Chunk* NeoRaquet_Sound;
typedef Mix_Music* NeoRaquet_BGM;

NeoRaquet_Sound NeoRaquet_LoadSound(const char* file);
void NeoRaquet_PlaySound(NeoRaquet_Sound wav, int loops);
void NeoRaquet_DestroySound(NeoRaquet_Sound wav);

#endif 
