#include "NeoRaquet_Actor.h"
#include "NeoRaquet_Render.h"

Actor* NeoRaquet_AllocateActor() {
    return (Actor*)malloc(sizeof(Actor));
}

void NeoRaquet_CreateActor(Actor* act, NeoRaquet_CHR tex, ActorType type, void (*updateFunc)(struct Actor*)) {
    act->x = 0;
    act->y = 0;
    act->origin.x = 0;
    act->origin.y = 0;
    act->angle = 0;
    act->flip = SDL_FLIP_NONE;
    act->type = type;
    act->update = updateFunc;
    if (tex != NULL) {
        NeoRaquet_Point size = NeoRaquet_SizeofCHR(tex);
        act->cur_image = tex;
        act->width = size.x;
        act->height = size.y;
        act->bbox.x1 = 0;
        act->bbox.y1 = 0;
        act->bbox.x2 = size.x;
        act->bbox.y2 = size.y;
    }
}

void NeoRaquet_DestroyActor(Actor* act) {
    free(act);
}

void NeoRaquet_DrawActor(Actor* act) {
    extern Camera camera;
    PlaceCHR_ext(act->cur_image, act->x - camera.x, act->y - camera.y, act->width, act->height, act->angle, act->origin, act->flip);
}

int NeoRaquet_ActorColliding(int x, int y, Actor* act1, Actor* act2) {
    return (x - act1->origin.x + act1->bbox.x2 > act2->x - act2->origin.x + act2->bbox.x1) &&
           (x - act1->origin.x + act1->bbox.x1 < act2->x - act2->origin.x + act2->bbox.x2) &&
           (y - act1->origin.y + act1->bbox.y2 > act2->y - act2->origin.y + act2->bbox.y1) &&
           (y - act1->origin.y + act1->bbox.y1 < act2->y - act2->origin.y + act2->bbox.y2);
}

void NeoRaquet_UpdateActor(Actor* act) {
    if (act->update) {
        act->update(act);
    }
}
