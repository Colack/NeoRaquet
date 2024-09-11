#include "../libneoraquet/NeoRaquet.h"
#include "../libneoraquet/NeoRaquet_Math.h"

Actor* player;
Actor* enemy;

NeoRaquet_CHR loadExampleTexture() {
    PPF_Bank ppfBank;
    if (!LoadPPFBank(&ppfBank, "example.ppf")) {
        printf("Failed to load PPF Bank\n");
        return NULL;
    }

    Palette palette[3] = {PAL_WHITE_FULL, PAL_RED_FULL, PAL_BLUE_FULL};
    return LoadCHR(ppfBank, 0, palette);
}

void updatePlayer(Actor* self) {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    int moveSpeed = 5;

    if (state[SDL_SCANCODE_UP]) {
        self->y -= moveSpeed;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        self->y += moveSpeed;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        self->x -= moveSpeed;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        self->x += moveSpeed;
    }
}

void updateEnemy(Actor* self) {
    static int direction = 1;
    int moveSpeed = 2;
    self->x += moveSpeed * direction;
    if (self->x < 50 || self->x > SCREEN_WIDTH - 50) {
        direction = -direction;
    }
}

void NeoRaquet_Create() {
    NeoRaquet_CHR exampleTexture = loadExampleTexture();
    if (!exampleTexture) {
        printf("Failed to load texture\n");
        return;
    }

    player = NeoRaquet_AllocateActor();
    NeoRaquet_CreateActor(player, exampleTexture, ACTOR_TYPE_PLAYER, updatePlayer);
    player->x = SCREEN_WIDTH / 2;
    player->y = SCREEN_HEIGHT / 2;

    enemy = NeoRaquet_AllocateActor();
    NeoRaquet_CreateActor(enemy, exampleTexture, ACTOR_TYPE_ENEMY, updateEnemy);
    enemy->x = SCREEN_WIDTH / 4;
    enemy->y = SCREEN_HEIGHT / 4;
}

void NeoRaquet_Loop() {
    NeoRaquet_Clear(PAL_BLACK);

    NeoRaquet_UpdateActor(player);
    NeoRaquet_DrawActor(player);

    NeoRaquet_UpdateActor(enemy);
    NeoRaquet_DrawActor(enemy);

    NeoRaquet_Update();
}

int main(int argc, char* argv[]) {
    NeoRaquet_MainLoop();
    return 0;
}