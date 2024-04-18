/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** create_screens_texts
*/

#include "jetpack.h"

// assets->sprites.walls.road.sprite = sfSprite_create();
// assets->sprites.walls.road.texture =
// sfTexture_createFromFile("client/assets/Textures/route.png", NULL);
// assets->sprites.walls.road.rect.height = 360;
// assets->sprites.walls.road.rect.width = 640;
// assets->sprites.walls.road.rect.top = 0;
// assets->sprites.walls.road.rect.left = 0;
// sfSprite_setTexture(assets->sprites.walls.road.sprite,
// assets->sprites.walls.road.texture, sfFalse);
// sfSprite_setTextureRect(assets->sprites.walls.road.sprite,
// assets->sprites.walls.road.rect);
// sfSprite_setScale(assets->sprites.walls.road.sprite, scale);

void create_wait_screen(assets_t *assets)
{
    assets->screens.wait_screen.sprite = sfSprite_create();
    assets->screens.wait_screen.texture =
    sfTexture_createFromFile("client/assets/Textures/loading.png", NULL);
    sfSprite_setTexture(assets->screens.wait_screen.sprite,
    assets->screens.wait_screen.texture, sfFalse);
    sfSprite_setOrigin(assets->screens.wait_screen.sprite,
    (sfVector2f){320 / 2, 320 / 2});
    sfSprite_setPosition(assets->screens.wait_screen.sprite,
    (sfVector2f){1920 / 2, 1080 / 2});
    assets->screens.wait_color = (rgb_t) {100, 100, 100, false};
}

void create_end_menu_text(assets_t *assets)
{
    assets->screens.end_screen.sprite = sfSprite_create();
    assets->screens.end_screen.texture =
    sfTexture_createFromFile("client/assets/Textures/end_screen.png", NULL);
    sfSprite_setTexture(assets->screens.end_screen.sprite,
    assets->screens.end_screen.texture, sfFalse);
    sfSprite_setOrigin(assets->screens.end_screen.sprite,
    (sfVector2f){512 / 2, 512 / 2});
    sfSprite_setPosition(assets->screens.end_screen.sprite,
    (sfVector2f){1920 / 2, 1080 / 2});
}

void create_menus_texts(assets_t *assets)
{
    create_wait_screen(assets);
    create_end_menu_text(assets);
}
