/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** map
*/

#include "jetpack.h"

bool set_fireball_positionsxy(assets_t *assets, size_t x, size_t y, int i)
{
    if (assets->map.level[y][x] == 'e') {
        assets->map.obstacles.fireballs[i].map_pos.x = x;
        assets->map.obstacles.fireballs[i].map_pos.y = y;
        assets->map.obstacles.fireballs[i].pos =
        (sfVector2f)
        {x * assets->map.spacing - assets->sprites.barry.pos.x,
        (assets->map.obstacles.fireballs[i].pos.y == -1000) ?
        -1000 : ((int)y * assets->map.spacing) + 24};
        return true;
    }
    return false;
}

void set_fireball_positions(assets_t *assets)
{
    int i = 0;

    for (size_t y = 0; y < assets->map.y_max; y++) {
        for (size_t x = 0; x < assets->map.x_max ; x++) {
            i = (set_fireball_positionsxy(assets, x, y, i)) ? i + 1 : i;
        }
    }
    for (size_t j = 0; j < assets->map.nb_fireballs; j++) {
        sfSprite_setPosition(assets->map.obstacles.fireballs[j].sprite,
        assets->map.obstacles.fireballs[j].pos);
    }
}

bool set_coin_positionsxy(assets_t *assets, size_t x, size_t y, int i)
{
    if (assets->map.level[y][x] == 'c') {
        assets->map.obstacles.coins[i].map_pos.x = x;
        assets->map.obstacles.coins[i].map_pos.y = y;
        assets->map.obstacles.coins[i].pos =
        (sfVector2f) {x * assets->map.spacing - (assets->sprites.barry.pos.x),
        (assets->map.obstacles.coins[i].pos.y == -1000) ?
        -1000 : ((int)y * assets->map.spacing) + 24};
        return true;
    }
    return false;
}

void set_coin_positions(assets_t *assets)
{
    int i = 0;

    for (size_t y = 0; y < assets->map.y_max ; y++) {
        for (size_t x = 0; x < assets->map.x_max ; x++) {
            i = (set_coin_positionsxy(assets, x, y, i)) ? i + 1 : i;
        }
    }
    for (size_t j = 0; j < assets->map.nb_coins; j++) {
        sfSprite_setPosition(assets->map.obstacles.coins[j].sprite,
        assets->map.obstacles.coins[j].pos);
    }
}
