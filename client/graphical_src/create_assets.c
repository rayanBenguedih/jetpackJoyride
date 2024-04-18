/*
** EPITECH PROJECT, 2020
** assets creation
** File description:
** create_assets
*/

#include "jetpack.h"

void create_wall_2_rect(assets_t *assets)
{
    sfVector2f scale = {3, 3};

    assets->sprites.walls.wall_2.sprite = sfSprite_create();
    assets->sprites.walls.wall_2.texture =
    sfTexture_createFromFile("client/assets/Textures/wall_2.png", NULL);
    assets->sprites.walls.wall_2.rect.height = 360;
    assets->sprites.walls.wall_2.rect.width = 640;
    assets->sprites.walls.wall_2.rect.top = 0;
    assets->sprites.walls.wall_2.rect.left = 0;
    sfSprite_setTexture(assets->sprites.walls.wall_2.sprite,
    assets->sprites.walls.wall_2.texture, sfFalse);
    sfSprite_setTextureRect(assets->sprites.walls.wall_2.sprite,
    assets->sprites.walls.wall_2.rect);
    sfSprite_setScale(assets->sprites.walls.wall_2.sprite, scale);
    assets->sprites.walls.wall_3.sprite = sfSprite_create();
    assets->sprites.walls.wall_3.texture =
    sfTexture_createFromFile("client/assets/Textures/wall_3.png", NULL);
    sfSprite_setTexture(assets->sprites.walls.wall_3.sprite,
    assets->sprites.walls.wall_3.texture, sfFalse);
    sfSprite_setScale(assets->sprites.walls.wall_3.sprite, scale);
}

void create_wall_1_rect(assets_t *assets)
{
    sfVector2f scale = {3, 3};

    assets->sprites.walls.wall_1.sprite = sfSprite_create();
    assets->sprites.walls.wall_1.texture =
    sfTexture_createFromFile("client/assets/Textures/wall_1.png", NULL);
    assets->sprites.walls.wall_1.rect.height = 360;
    assets->sprites.walls.wall_1.rect.width = 640;
    assets->sprites.walls.wall_1.rect.top = 0;
    assets->sprites.walls.wall_1.rect.left = 0;
    sfSprite_setTexture(assets->sprites.walls.wall_1.sprite,
    assets->sprites.walls.wall_1.texture, sfFalse);
    sfSprite_setTextureRect(assets->sprites.walls.wall_1.sprite,
    assets->sprites.walls.wall_1.rect);
    sfSprite_setScale(assets->sprites.walls.wall_1.sprite, scale);
}

void create_route_rect(assets_t *assets)
{
    sfVector2f scale = {3, 3};

    assets->sprites.walls.road.sprite = sfSprite_create();
    assets->sprites.walls.road.texture =
    sfTexture_createFromFile("client/assets/Textures/route.png", NULL);
    assets->sprites.walls.road.rect.height = 360;
    assets->sprites.walls.road.rect.width = 640;
    assets->sprites.walls.road.rect.top = 0;
    assets->sprites.walls.road.rect.left = 0;
    sfSprite_setTexture(assets->sprites.walls.road.sprite,
    assets->sprites.walls.road.texture, sfFalse);
    sfSprite_setTextureRect(assets->sprites.walls.road.sprite,
    assets->sprites.walls.road.rect);
    sfSprite_setScale(assets->sprites.walls.road.sprite, scale);
}

void create_rects(assets_t *assets)
{
    create_route_rect(assets);
    create_wall_1_rect(assets);
    create_wall_2_rect(assets);
    create_barry_rect(assets);
    create_ghost_rect(assets);
}

void create_assets(assets_t *assets)
{
    create_clocks(assets);
    create_rects(assets);
    create_score_font(assets);
    create_music(assets);
    create_sounds(assets);
    create_menus_texts(assets);
}
