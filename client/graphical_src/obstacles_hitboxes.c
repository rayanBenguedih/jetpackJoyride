/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** obstacles_hitboxes
*/

#include "jetpack.h"

void update_coins(assets_t *assets, cli_et *client)
{
    if (!client->playerData->scoreup) {
        return;
    }
    for (size_t i = 0; i < assets->map.nb_coins; i++) {
        if (assets->map.obstacles.coins[i].map_pos.x == client->coinX &&
            assets->map.obstacles.coins[i].map_pos.y == client->coinY &&
            !assets->map.obstacles.coins[i].picked) {
            assets->map.obstacles.coins[i].pos.y = -1000;
            assets->stats.score.value += 1;
            sfSound_play(assets->audio.coin_pickup.sound);
            assets->map.obstacles.coins[i].picked = true;
            client->playerData->scoreup = false;
            sfSprite_setPosition(assets->map.obstacles.coins[i].sprite,
            assets->map.obstacles.coins[i].pos);
            set_score(assets);
        }
    }
}
