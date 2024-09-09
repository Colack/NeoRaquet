#include "NeoRaquet_Render.h"

const Palette PAL0F = 0x00000000;
const Palette PAL_BLACK = 0x000000FF;
const Palette PAL_WHITE_FULL = 0xDFDFDFFF;
const Palette PAL_WHITE_MID = 0x8F8F8FFF;
const Palette PAL_WHITE_DARK = 0x4F4F4FFF;
const Palette PAL_WHITE_NOR = 0x2F2F2FFF;
const Palette PAL_RED_FULL = 0xDF0000FF;
const Palette PAL_RED_MID = 0x8F0000FF;
const Palette PAL_RED_DARK = 0x4F0000FF;
const Palette PAL_RED_NOR = 0x2F0000FF;
const Palette PAL_ORANGE_FULL = 0xDF8F00FF;
const Palette PAL_ORANGE_MID = 0x8F4F00FF;
const Palette PAL_ORANGE_DARK = 0x4F2F00FF;
const Palette PAL_ORANGE_NOR = 0x2F0F00FF;
const Palette PAL_YELLOW_FULL = 0xDFDF00FF;
const Palette PAL_YELLOW_MID = 0x8F8F00FF;
const Palette PAL_YELLOW_DARK = 0x4F4F00FF;
const Palette PAL_YELLOW_NOR = 0x2F2F00FF;
const Palette PAL_GREEN_FULL = 0x00DF00FF;
const Palette PAL_GREEN_MID = 0x008F00FF;
const Palette PAL_GREEN_DARK = 0x004F00FF;
const Palette PAL_GREEN_NOR = 0x002F00FF;
const Palette PAL_BLUE_FULL = 0x0000DFFF;
const Palette PAL_BLUE_MID = 0x00008FFF;
const Palette PAL_BLUE_DARK = 0x00004FFF;
const Palette PAL_BLUE_NOR = 0x00002FFF;
const Palette PAL_PURPLE_FULL = 0xDF00DFFF;
const Palette PAL_PURPLE_MID = 0x8F008FFF;
const Palette PAL_PURPLE_DARK = 0x4F004FFF;
const Palette PAL_PURPLE_NOR = 0x2F002FFF;

void NeoRaquet_SetPalette(Palette dest[3], Uint32 pal1, Uint32 pal2, Uint32 pal3) {
    dest[0] = pal1;
    dest[1] = pal2;
    dest[2] = pal3;
}

void NeoRaquet_SetDrawColor(Palette pal, int alpha) {
    Uint32 palr = (pal >> 24) & 0x000000FF;
    Uint32 palg = (pal >> 16) & 0x000000FF;
    Uint32 palb = (pal >> 8) & 0x000000FF;
    SDL_SetRenderDrawColor(gRenderer, palr, palg, palb, alpha);
}

void NeoRaquet_Clear(Palette pal) {
    NeoRaquet_SetDrawColor(pal, 255);
    SDL_RenderFillRect(gRenderer, NULL);
}

void NeoRaquet_DrawRectangle(int x1, int y1, int width, int height, Palette pal, int alpha, int fill) {
    SDL_Rect rect = {x1, y1, width, height};
    NeoRaquet_SetDrawColor(pal, alpha);
    if (fill) {
        SDL_RenderFillRect(gRenderer, &rect);
    } else {
        SDL_RenderDrawRect(gRenderer, &rect);
    }
}

void NeoRaquet_Update() {
    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);
}

int LoadPPFBank(PPF_Bank* targetarray, const char* dir) {
    SDL_RWops* ppfdata = SDL_RWFromFile(dir, "rb");
    if (ppfdata != NULL) {
        long long sizeoffile = SDL_RWseek(ppfdata, 0, RW_SEEK_END);
        SDL_RWseek(ppfdata, 0, RW_SEEK_SET);
        *targetarray = (char*)malloc(sizeoffile * sizeof(char));
        SDL_RWread(ppfdata, *targetarray, sizeoffile, 1);

        for (int i = 0; i < 8; i++) {
            if ((*targetarray)[i] != PPFHEADER[i]) {
                printf("WARNING HEADER DATA DOES NOT MATCH\n");
                fflush(stdout);
            }
        }
        SDL_RWclose(ppfdata);
        printf("Loaded PPF Data at: %s successfully\n", dir);
        fflush(stdout);
        return 1;
    } else {
        printf("Failed to load PPF at: %s\n", dir);
        fflush(stdout);
        return 0;
    }
}

NeoRaquet_CHR LoadCHR(PPF_Bank ppfbank, int id, Palette palette[3]) {
    SDL_Texture* tex = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 8, 8);
    Uint32 pixels[64];

    if (id == -1) {
        memset(pixels, 0x00000000, sizeof(pixels));
        SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
        SDL_UpdateTexture(tex, NULL, pixels, 8 * sizeof(Palette));
        return tex;
    }

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            int dest = x + (y * 8);
            int index = y + 8 + (id * 16);
            int index2 = y + 16 + (id * 16);

            int check1 = (ppfbank[index] & ppfbitmask[x]) > 0;
            int check2 = (ppfbank[index2] & ppfbitmask[x]) > 0;
            int place = check1 + check2;

            if (place == 0) {
                pixels[dest] = PAL0F;
            } else if (place == 1) {
                pixels[dest] = check1 ? palette[0] : palette[1];
            } else {
                pixels[dest] = palette[2];
            }
        }
    }

    SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
    SDL_UpdateTexture(tex, NULL, pixels, 8 * sizeof(Palette));
    return tex;
}

NeoRaquet_Point NeoRaquet_SizeofCHR(NeoRaquet_CHR tex) {
    NeoRaquet_Point size;
    SDL_QueryTexture(tex, NULL, NULL, &size.x, &size.y);
    return size;
}

void PlaceCHR_ext(NeoRaquet_CHR tex, int x, int y, int xsize, int ysize, double angle, NeoRaquet_Point center, SDL_RendererFlip flip) {
    SDL_Rect dstrect = {x - center.x, y - center.y, xsize, ysize};
    SDL_RenderCopyEx(gRenderer, tex, NULL, &dstrect, angle, &center, flip);
}
