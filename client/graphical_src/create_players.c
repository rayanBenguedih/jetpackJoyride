/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** create_players
*/

#include "jetpack.h"

void set_barry_pos(assets_t *assets)
{
    assets->sprites.barry.pos.x = 1;
    assets->sprites.barry.pos.y = 1;
    assets->sprites.barry.fire = false;
    sfSprite_setPosition(assets->sprites.barry.sprite,
    (sfVector2f) {200, 820});
    assets->sprites.barry.dead = false;
}

void create_barry_rect(assets_t *assets)
{
    sfVector2f origin;

    assets->sprites.barry.sprite = sfSprite_create();
    assets->sprites.barry.texture =
    sfTexture_createFromFile("client/assets/Textures/barrySprites.png", NULL);
    assets->sprites.barry.rect.left = 0;
    assets->sprites.barry.rect.top = 0;
    assets->sprites.barry.rect.height = 48;
    assets->sprites.barry.rect.width = 50;
    sfSprite_scale(assets->sprites.barry.sprite, (sfVector2f) {2, 2});
    sfSprite_setTexture(assets->sprites.barry.sprite,
    assets->sprites.barry.texture, sfFalse);
    sfSprite_setTextureRect(assets->sprites.barry.sprite,
    assets->sprites.barry.rect);
    origin = sfSprite_getOrigin(assets->sprites.barry.sprite);
    origin.x += 25;
    origin.y += 24;
    sfSprite_setOrigin(assets->sprites.barry.sprite, origin);
    set_barry_pos(assets);
}

void set_ghost_pos(assets_t *assets)
{
    assets->sprites.ghost.pos.x = 1;
    assets->sprites.ghost.pos.y = 1;
    assets->sprites.ghost.fire = false;
    sfSprite_setPosition(assets->sprites.ghost.sprite,
    (sfVector2f) {200, 820});
    assets->sprites.ghost.dead = false;
}

void create_ghost_rect(assets_t *assets)
{
    sfVector2f origin;

    assets->sprites.ghost.sprite = sfSprite_create();
    assets->sprites.ghost.texture =
    sfTexture_createFromFile("client/assets/Textures/ghostSprites.png", NULL);
    assets->sprites.ghost.rect.left = 0;
    assets->sprites.ghost.rect.top = 0;
    assets->sprites.ghost.rect.height = 48;
    assets->sprites.ghost.rect.width = 50;
    sfSprite_scale(assets->sprites.ghost.sprite, (sfVector2f) {2, 2});
    sfSprite_setTexture(assets->sprites.ghost.sprite,
    assets->sprites.ghost.texture, sfFalse);
    sfSprite_setTextureRect(assets->sprites.ghost.sprite,
    assets->sprites.ghost.rect);
    origin = sfSprite_getOrigin(assets->sprites.ghost.sprite);
    origin.x += 25;
    origin.y += 24;
    sfSprite_setOrigin(assets->sprites.ghost.sprite, origin);
    set_ghost_pos(assets);
}
