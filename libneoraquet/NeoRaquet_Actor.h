#ifndef NEORAQUET_ACTOR_H
#define NEORAQUET_ACTOR_H

#include "NeoRaquet_Types.h"

Actor* NeoRaquet_AllocateActor();
void NeoRaquet_CreateActor(Actor* act, NeoRaquet_CHR tex, ActorType type, void (*updateFunc)(struct Actor*));
void NeoRaquet_DestroyActor(Actor* act);
void NeoRaquet_DrawActor(Actor* act);
int NeoRaquet_ActorColliding(int x, int y, Actor* act1, Actor* act2);
void NeoRaquet_UpdateActor(Actor* act);

#endif
