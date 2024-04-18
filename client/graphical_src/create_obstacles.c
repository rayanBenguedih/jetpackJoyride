/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** create_obstacles
*/

#include "jetpack.h"

void create_fireball_instance(assets_t *assets, size_t i)
{
    assets->map.obstacles.fireballs[i].sprite = sfSprite_create();
    assets->map.obstacles.fireballs[i].texture =
    sfTexture_createFromFile("client/assets/Textures/fireball.png", NULL);
    assets->map.obstacles.fireballs[i].rect.height = 94;
    assets->map.obstacles.fireballs[i].rect.width = 100;
    assets->map.obstacles.fireballs[i].rect.top = 0;
    assets->map.obstacles.fireballs[i].rect.left = 0;
    sfSprite_setTexture(assets->map.obstacles.fireballs[i].sprite,
    assets->map.obstacles.fireballs[i].texture, sfFalse);
    sfSprite_setTextureRect(assets->map.obstacles.fireballs[i].sprite,
    assets->map.obstacles.fireballs[i].rect);
    sfSprite_setOrigin(assets->map.obstacles.fireballs[i].sprite,
    (sfVector2f) {50, 47});
    sfSprite_setScale(assets->map.obstacles.fireballs[i].sprite,
    (sfVector2f) {1.4, 1.4});
    assets->map.obstacles.fireballs[i].pos = (sfVector2f) {-200, -200};
}

int get_obstacle_nb(assets_t *assets, char obstacle)
{
    int obslb = 0;

    if (!assets->map.level)
        return 0;
    for (size_t y = 0; y < assets->map.y_max; y++) {
        for (size_t x = 0; x < assets->map.x_max; x++) {
            obslb = (assets->map.level[y][x] == obstacle) ? obslb + 1 : obslb;
        }
    }
    return obslb;
}

void create_fireballs(assets_t *assets)
{
    assets->map.nb_fireballs = get_obstacle_nb(assets, 'e');
    assets->map.obstacles.fireballs =
    malloc(sizeof(asset_obstacle_t) * assets->map.nb_fireballs);
    for (size_t i = 0; i < assets->map.nb_fireballs; i++) {
        create_fireball_instance(assets, i);
        assets->map.obstacles.fireballs[i].picked = false;
    }
}

void create_coin_instance(assets_t *assets, size_t i)
{
    assets->map.obstacles.coins[i].sprite = sfSprite_create();
    assets->map.obstacles.coins[i].texture =
    sfTexture_createFromFile("client/assets/Textures/coin.png", NULL);
    assets->map.obstacles.coins[i].rect.height = 133;
    assets->map.obstacles.coins[i].rect.width = 134;
    assets->map.obstacles.coins[i].rect.top = 0;
    assets->map.obstacles.coins[i].rect.left = 0;
    sfSprite_setTexture(assets->map.obstacles.coins[i].sprite,
    assets->map.obstacles.coins[i].texture, sfFalse);
    sfSprite_setTextureRect(assets->map.obstacles.coins[i].sprite,
    assets->map.obstacles.coins[i].rect);
    sfSprite_setOrigin(assets->map.obstacles.coins[i].sprite,
    (sfVector2f) {67, 66});
    sfSprite_setScale(assets->map.obstacles.coins[i].sprite,
    (sfVector2f) {0.3, 0.3});
    assets->map.obstacles.coins[i].pos = (sfVector2f) {-200, -200};
}

void create_coins(assets_t *assets)
{
    assets->map.nb_coins = get_obstacle_nb(assets, 'c');
    assets->map.obstacles.coins =
    malloc(sizeof(asset_obstacle_t) * assets->map.nb_coins);
    for (size_t i = 0; i < assets->map.nb_coins; i++) {
        create_coin_instance(assets, i);
        assets->map.obstacles.coins[i].picked = false;
    }
}
