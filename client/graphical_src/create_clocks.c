/*
** EPITECH PROJECT, 2021
** fonctions relatives to clocks
** File description:
** create_clocks
*/

#include "jetpack.h"

void create_clocks(assets_t *assets)
{
    assets->sprites.walls.road.track.timer = sfClock_create();
    assets->sprites.walls.wall_1.track.timer = sfClock_create();
    assets->sprites.walls.wall_2.track.timer = sfClock_create();
    assets->sprites.barry.track.timer = sfClock_create();
    assets->sprites.ghost.track.timer = sfClock_create();
    assets->sprites.pos_update.timer = sfClock_create();
    assets->map.obstacles.fireballs_track.timer = sfClock_create();
    assets->map.obstacles.coins_track.timer = sfClock_create();
    assets->stats.track.timer = sfClock_create();
}
