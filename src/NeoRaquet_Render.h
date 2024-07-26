#ifndef NEORAQUET_RENDER_H
#define NEORAQUET_RENDER_H

#include "NeoRaquet_Types.h"
#include "NeoRaquet.h"

extern const Palette PAL0F;
extern const Palette PAL_BLACK;
extern const Palette PAL_WHITE_FULL;
extern const Palette PAL_WHITE_MID;
extern const Palette PAL_WHITE_DARK;
extern const Palette PAL_WHITE_NOR;
extern const Palette PAL_RED_FULL;
extern const Palette PAL_RED_MID;
extern const Palette PAL_RED_DARK;
extern const Palette PAL_RED_NOR;
extern const Palette PAL_ORANGE_FULL;
extern const Palette PAL_ORANGE_MID;
extern const Palette PAL_ORANGE_DARK;
extern const Palette PAL_ORANGE_NOR;
extern const Palette PAL_YELLOW_FULL;
extern const Palette PAL_YELLOW_MID;
extern const Palette PAL_YELLOW_DARK;
extern const Palette PAL_YELLOW_NOR;
extern const Palette PAL_GREEN_FULL;
extern const Palette PAL_GREEN_MID;
extern const Palette PAL_GREEN_DARK;
extern const Palette PAL_GREEN_NOR;
extern const Palette PAL_BLUE_FULL;
extern const Palette PAL_BLUE_MID;
extern const Palette PAL_BLUE_DARK;
extern const Palette PAL_BLUE_NOR;
extern const Palette PAL_PURPLE_FULL;
extern const Palette PAL_PURPLE_MID;
extern const Palette PAL_PURPLE_DARK;
extern const Palette PAL_PURPLE_NOR;

void NeoRaquet_SetPalette(Palette dest[3], Uint32 pal1, Uint32 pal2, Uint32 pal3);
void NeoRaquet_SetDrawColor(Palette pal, int alpha);
void NeoRaquet_Clear(Palette pal);
void NeoRaquet_DrawRectangle(int x1, int y1, int width, int height, Palette pal, int alpha, int fill);
void NeoRaquet_Update();
int LoadPPFBank(PPF_Bank* targetarray, const char* dir);
NeoRaquet_CHR LoadCHR(PPF_Bank ppfbank, int id, Palette palette[3]);
NeoRaquet_Point NeoRaquet_SizeofCHR(NeoRaquet_CHR tex);
void PlaceCHR_ext(NeoRaquet_CHR tex, int x, int y, int xsize, int ysize, double angle, NeoRaquet_Point center, SDL_RendererFlip flip);

#endif
