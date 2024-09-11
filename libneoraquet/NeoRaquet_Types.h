#ifndef NEORAQUET_TYPES_H
#define NEORAQUET_TYPES_H

#include <SDL2/SDL.h>

typedef Uint32 Palette;
typedef SDL_Texture* NeoRaquet_CHR;
typedef SDL_Point NeoRaquet_Point;
typedef char* PPF_Bank;

extern const unsigned char PPFHEADER[8];
extern const unsigned int ppfbitmask[8];

typedef struct Camera {
    int x;
    int y;
    int newx;
    int newy;
    int8_t shift;
    int8_t movedelay_time;
    int8_t movedelay;
    uint8_t ismoved: 1;
} Camera;

typedef struct NeoRaquet_BoundingBox {
    int x1;
    int y1;
    int x2;
    int y2;
} NeoRaquet_BoundingBox;

typedef enum {
    ACTOR_TYPE_DEFAULT,
    ACTOR_TYPE_PLAYER,
    ACTOR_TYPE_ENEMY,
    ACTOR_TYPE_NPC
} ActorType;

typedef struct Actor {
    int x;
    int y;
    NeoRaquet_CHR cur_image;
    NeoRaquet_Point origin;
    int width;
    int height;
    int angle;
    Palette color;
    NeoRaquet_BoundingBox bbox;
    SDL_RendererFlip flip;
    ActorType type;
    void (*update)(struct Actor* self);
} Actor;

typedef struct ReActor {
  int x;
  int y;
  NeoRaquet_CHR cur_image;
  NeoRaquet_Point origin;
  int width;
  int height;
  int angle;
  Palette color;
  NeoRaquet_BoundingBox bbox;
  SDL_RendererFlip flip;
} ReActor;

typedef struct NeoRaquet_Sprite {
    NeoRaquet_CHR chr;
    NeoRaquet_Point origin;
    int width;
    int height;
    Palette color;
    SDL_RendererFlip flip;
} NeoRaquet_Sprite;

typedef struct NeoRaquet_SpriteSheet {
    NeoRaquet_CHR chr;
    NeoRaquet_Point origin;
    int width;
    int height;
    Palette color;
    SDL_RendererFlip flip;
    int num_frames;
    int frame_width;
    int frame_height;
    int frame_delay;
    int cur_frame;
    int cur_frame_delay;
} NeoRaquet_SpriteSheet;

#endif
