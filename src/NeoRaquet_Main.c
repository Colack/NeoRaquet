#include "NeoRaquet.h"

SDL_Window *gWindow;
uint8_t gFullscreen = -1;
SDL_Renderer *gRenderer;
SDL_Rect gRectScrn = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
SDL_Event e;
Camera camera;
const float FRAMERATE_CAP = 60.0f;
const unsigned char PPFHEADER[8] = {0x50, 0x50, 0x46, 0x76, 0x01, 0x00, 0x00, 0x00};
const unsigned int ppfbitmask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
Uint64 start_tick = 0;

int initsdl() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("FAILED TO INITIALIZE SDL VIDEO.\n");
        return 0;
    } else {
        if (Mix_OpenAudio(AUDIO_SAMPLE_RATE, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            printf("FAILED TO INITIALIZE SDL MIXER.\n");
            return 0;
        }
        gWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCREEN_SCALE, SCREEN_HEIGHT * SCREEN_SCALE, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (gWindow == NULL) {
            printf("FAILED TO CREATE SDL WINDOW.\n");
            return 0;
        } else {
            printf("SDL Initialized\n");
            fflush(stdout);
#ifdef VSYNC
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
#else
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
#endif
            SDL_RenderSetViewport(gRenderer, NULL);
            SDL_RenderSetLogicalSize(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);

#ifdef VSYNC
            if (SDL_GL_SetSwapInterval(-1) < 0) {
                SDL_GL_SetSwapInterval(1);
            }
#endif

            SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
        }
    }
    return 1;
}

int NeoRaquet_Init() {
    sdlkeys = SDL_GetKeyboardState(NULL);
    if (!initsdl()) {
        printf("Failed to Initialize SDL\n");
        return 0;
    }
    return 1;
}

void NeoRaquet_MainLoop() {
    if (!NeoRaquet_Init()) {
        printf("Failed to Initialize NeoRaquet\n");
        return;
    } else {
        printf("NeoRaquet Initialized\n");
        fflush(stdout);
        createthedog();

        while (1) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    return;
                }
            }

            #ifdef ALLOW_FULLSCREEN
            if (NeoRaquet_KeyCheck_Pressed(SDL_SCANCODE_F11)) {
                gFullscreen = -gFullscreen;
            }
            if (gFullscreen == 1) {
                SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
            } else {
                SDL_SetWindowFullscreen(gWindow, 0);
            }
            #endif

            sdlmouse = SDL_GetMouseState(NULL, NULL);
            start_tick = SDL_GetTicks64();
            gameLoop();
            if ((1000.0f / FRAMERATE_CAP) > SDL_GetTicks64() - start_tick) {
                SDL_Delay(1000.0f / FRAMERATE_CAP - (SDL_GetTicks64() - start_tick));
            }
            memcpy(prevkeys, sdlkeys, sizeof(prevkeys));
            prevmouse = sdlmouse;
        }
    }
}
