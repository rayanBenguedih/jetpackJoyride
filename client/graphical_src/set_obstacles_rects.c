/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** set_obstacles_rects
*/

#include "jetpack.h"

void set_fireballs_rects(assets_t *assets)
{
    int ratio;

    assets->map.obstacles.fireballs_track.time =
    sfClock_getElapsedTime(assets->map.obstacles.fireballs_track.timer);
    assets->map.obstacles.fireballs_track.seconds =
    assets->map.obstacles.fireballs_track.time.microseconds / 1000000.0;
    ratio = assets->map.obstacles.fireballs_track.seconds / 0.0333333;
    if (assets->map.obstacles.fireballs_track.seconds >= 0.0333333) {
        for (size_t i = 0; i < assets->map.nb_fireballs; i++) {
            assets->map.obstacles.fireballs[i].rect.left += 100 * ratio;
            assets->map.obstacles.fireballs[i].rect.left =
            (assets->map.obstacles.fireballs[i].rect.left >= 600) ? 0 :
            assets->map.obstacles.fireballs[i].rect.left;
        }
        sfClock_restart(assets->map.obstacles.fireballs_track.timer);
    }
    for (size_t i = 0; i < assets->map.nb_fireballs; i++) {
        sfSprite_setTextureRect(assets->map.obstacles.fireballs[i].sprite,
        assets->map.obstacles.fireballs[i].rect);
    }
}

void set_coins_rects(assets_t *assets)
{
    int ratio;

    assets->map.obstacles.coins_track.time =
    sfClock_getElapsedTime(assets->map.obstacles.coins_track.timer);
    assets->map.obstacles.coins_track.seconds =
    assets->map.obstacles.coins_track.time.microseconds / 1000000.0;
    ratio = assets->map.obstacles.coins_track.seconds / 0.0333333;
    if (assets->map.obstacles.coins_track.seconds >= 0.0333333) {
        for (size_t i = 0; i < assets->map.nb_coins; i++) {
            assets->map.obstacles.coins[i].rect.left += 134 * ratio;
            assets->map.obstacles.coins[i].rect.left =
            (assets->map.obstacles.coins[i].rect.left >= 1339) ? 0 :
            assets->map.obstacles.coins[i].rect.left;
        }
        sfClock_restart(assets->map.obstacles.coins_track.timer);
    }
    for (size_t i = 0; i < assets->map.nb_coins; i++) {
        sfSprite_setTextureRect(assets->map.obstacles.coins[i].sprite,
        assets->map.obstacles.coins[i].rect);
    }
}

void set_fireballs_pos(assets_t *assets)
{
    float ratio;

    ratio = assets->sprites.walls.road.track.seconds / 0.0333333;
    if (assets->sprites.walls.road.track.seconds >= 0.0333333) {
        for (size_t i = 0; i < assets->map.nb_fireballs; ++i) {
            assets->map.obstacles.fireballs[i].pos.x -=
            (50 / 25) * ratio * 3;
        }
    }
    for (size_t i = 0; i < assets->map.nb_fireballs; ++i) {
        sfSprite_setPosition(assets->map.obstacles.fireballs[i].sprite,
        assets->map.obstacles.fireballs[i].pos);
    }
}

void set_coins_pos(assets_t *assets)
{
    float ratio;

    ratio = assets->sprites.walls.road.track.seconds / 0.0333333;
    if (assets->sprites.walls.road.track.seconds >= 0.0333333) {
        for (size_t i = 0; i < assets->map.nb_coins; ++i) {
            assets->map.obstacles.coins[i].pos.x -=
            (50 / 25) * ratio * 3;
        }
    }
    for (size_t i = 0; i < assets->map.nb_coins; ++i) {
        sfSprite_setPosition(assets->map.obstacles.coins[i].sprite,
        assets->map.obstacles.coins[i].pos);
    }
}
