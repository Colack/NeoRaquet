#include "NeoRaquet_Audio.h"

NeoRaquet_Sound NeoRaquet_LoadSound(const char* file) {
    return Mix_LoadWAV(file);
}

void NeoRaquet_PlaySound(NeoRaquet_Sound wav, int loops) {
    Mix_PlayChannel(-1, wav, loops);
}

void NeoRaquet_DestroySound(NeoRaquet_Sound wav) {
    Mix_FreeChunk(wav);
}
