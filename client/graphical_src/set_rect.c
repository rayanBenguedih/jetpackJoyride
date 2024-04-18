/*
** EPITECH PROJECT, 2021
** fonction relatives to rects
** File description:
** set_rect
*/

#include "jetpack.h"

void set_wall_2_rect(assets_t *assets)
{
    float ratio;

    assets->sprites.walls.wall_2.track.time =
    sfClock_getElapsedTime(assets->sprites.walls.wall_2.track.timer);
    assets->sprites.walls.wall_2.track.seconds =
    assets->sprites.walls.wall_2.track.time.microseconds / 1000000.0;
    ratio = assets->sprites.walls.wall_2.track.seconds / 0.0333333;
    if (assets->sprites.walls.wall_2.track.seconds >= 0.0333333) {
        assets->sprites.walls.wall_2.rect.left +=
        (50 / 100) * ratio;
        assets->sprites.walls.wall_2.rect.left =
        (assets->sprites.walls.wall_2.rect.left >= 640 ||
        assets->sprites.walls.wall_2.rect.left < 0) ?
        0 : assets->sprites.walls.wall_2.rect.left;
        sfClock_restart(assets->sprites.walls.wall_2.track.timer);
    }
    sfSprite_setTextureRect(assets->sprites.walls.wall_2.sprite,
    assets->sprites.walls.wall_2.rect);
}

void set_wall_1_rect(assets_t *assets)
{
    float ratio;

    assets->sprites.walls.wall_1.track.time =
    sfClock_getElapsedTime(assets->sprites.walls.wall_1.track.timer);
    assets->sprites.walls.wall_1.track.seconds =
    assets->sprites.walls.wall_1.track.time.microseconds / 1000000.0;
    ratio = assets->sprites.walls.wall_1.track.seconds / 0.0333333;
    if (assets->sprites.walls.wall_1.track.seconds >= 0.0333333) {
        assets->sprites.walls.wall_1.rect.left +=
        (50 / 35) * ratio;
        assets->sprites.walls.wall_1.rect.left =
        (assets->sprites.walls.wall_1.rect.left >= 1280 ||
        assets->sprites.walls.wall_1.rect.left < 0) ?
        0 : assets->sprites.walls.wall_1.rect.left;
        sfClock_restart(assets->sprites.walls.wall_1.track.timer);
    }
    sfSprite_setTextureRect(assets->sprites.walls.wall_1.sprite,
    assets->sprites.walls.wall_1.rect);
}

void set_route_rect(assets_t *assets)
{
    float ratio;

    assets->sprites.walls.road.track.time =
    sfClock_getElapsedTime(assets->sprites.walls.road.track.timer);
    assets->sprites.walls.road.track.seconds =
    assets->sprites.walls.road.track.time.microseconds / 1000000.0;
    ratio = assets->sprites.walls.road.track.seconds / 0.0333333;
    if (assets->sprites.walls.road.track.seconds >= 0.0333333) {
        assets->sprites.walls.road.rect.left +=
        (50 / 25) * ratio;
        assets->sprites.walls.road.rect.left =
        (assets->sprites.walls.road.rect.left >= 2560 ||
        assets->sprites.walls.road.rect.left < 0) ?
        0 : assets->sprites.walls.road.rect.left;
        sfClock_restart(assets->sprites.walls.road.track.timer);
    }
    sfSprite_setTextureRect(assets->sprites.walls.road.sprite,
    assets->sprites.walls.road.rect);
}

void update_players_positions(assets_t *assets, cli_et *client)
{
    assets->sprites.walls.road.track.time =
    sfClock_getElapsedTime(assets->sprites.walls.road.track.timer);
    assets->sprites.walls.road.track.seconds =
    assets->sprites.walls.road.track.time.microseconds / 1000000.0;
    if (assets->sprites.walls.road.track.seconds >= 0.0333333) {
        assets->sprites.barry.pos.x = client->playerData->posX *
        assets->map.spacing;
        assets->sprites.barry.pos.y = (client->playerData->posY *
        assets->map.spacing);
        sfSprite_setPosition(assets->sprites.barry.sprite,
        (sfVector2f){assets->map.spacing, assets->sprites.barry.pos.y});
        assets->sprites.ghost.pos.x = client->opponentData->posX *
        assets->map.spacing;
        assets->sprites.ghost.pos.y = (client->opponentData->posY *
        assets->map.spacing);
        sfSprite_setPosition(assets->sprites.ghost.sprite,
        (sfVector2f){assets->map.spacing, assets->sprites.ghost.pos.y});
        sfClock_restart(assets->sprites.pos_update.timer);
    }
}

void set_rects(assets_t *assets, cli_et *client)
{
    update_players_positions(assets, client);
    set_barry_rect(assets);
    set_ghost_rect(assets, client);
    set_route_rect(assets);
    set_wall_1_rect(assets);
    set_wall_2_rect(assets);
    set_coin_positions(assets);
    set_coins_rects(assets);
    set_fireball_positions(assets);
    set_fireballs_rects(assets);
    update_coins(assets, client);
    set_scene_music(assets);
}
