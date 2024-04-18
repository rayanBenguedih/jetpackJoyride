/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** create_obstacles_two
*/

#include "jetpack.h"

void create_obstacles(assets_t *assets)
{
    create_fireballs(assets);
    create_coins(assets);
    set_fireball_positions(assets);
    set_coin_positions(assets);
}
