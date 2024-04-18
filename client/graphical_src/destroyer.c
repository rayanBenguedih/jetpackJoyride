/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** destroyer
*/

#include "jetpack.h"

void texture_destroyer(assets_t *assets)
{
    sfTexture_destroy(assets->sprites.walls.road.texture);
    sfTexture_destroy(assets->sprites.walls.wall_1.texture);
    sfTexture_destroy(assets->sprites.walls.wall_2.texture);
    sfTexture_destroy(assets->sprites.walls.wall_3.texture);
    sfTexture_destroy(assets->sprites.barry.texture);
    sfTexture_destroy(assets->sprites.ghost.texture);
    for (size_t i = 0; i < assets->map.nb_coins; ++i)
        sfTexture_destroy(assets->map.obstacles.coins[i].texture);
    for (size_t i = 0; i < assets->map.nb_fireballs; ++i)
        sfTexture_destroy(assets->map.obstacles.fireballs[i].texture);
}

void sprite_destroyer(assets_t *assets)
{
    sfSprite_destroy(assets->sprites.walls.road.sprite);
    sfSprite_destroy(assets->sprites.walls.wall_1.sprite);
    sfSprite_destroy(assets->sprites.walls.wall_2.sprite);
    sfSprite_destroy(assets->sprites.walls.wall_3.sprite);
    sfSprite_destroy(assets->sprites.barry.sprite);
    sfSprite_destroy(assets->sprites.ghost.sprite);
    for (size_t i = 0; i < assets->map.nb_coins; ++i)
        sfSprite_destroy(assets->map.obstacles.coins[i].sprite);
    for (size_t i = 0; i < assets->map.nb_fireballs; ++i)
        sfSprite_destroy(assets->map.obstacles.fireballs[i].sprite);
}

void clock_destroyer(assets_t *assets)
{
    sfClock_destroy(assets->sprites.walls.road.track.timer);
    sfClock_destroy(assets->sprites.walls.wall_1.track.timer);
    sfClock_destroy(assets->sprites.walls.wall_2.track.timer);
    sfClock_destroy(assets->sprites.barry.track.timer);
    sfClock_destroy(assets->sprites.ghost.track.timer);
    sfClock_destroy(assets->sprites.pos_update.timer);
    sfClock_destroy(assets->map.obstacles.fireballs_track.timer);
    sfClock_destroy(assets->map.obstacles.coins_track.timer);
    sfClock_destroy(assets->stats.track.timer);
}

void sound_destroyer(assets_t *assets)
{
    sfMusic_stop(assets->audio.wait_music);
    sfMusic_stop(assets->audio.game_music);
    sfMusic_stop(assets->audio.end_music);
    sfMusic_stop(assets->audio.jetpack_hover);
    sfSound_stop(assets->audio.scream.sound);
    sfSound_stop(assets->audio.coin_pickup.sound);
    sfMusic_destroy(assets->audio.wait_music);
    sfMusic_destroy(assets->audio.game_music);
    sfMusic_destroy(assets->audio.end_music);
    sfMusic_destroy(assets->audio.jetpack_hover);
    sfSound_destroy(assets->audio.scream.sound);
    sfSoundBuffer_destroy(assets->audio.scream.buffer);
    sfSound_destroy(assets->audio.coin_pickup.sound);
    sfSoundBuffer_destroy(assets->audio.coin_pickup.buffer);
    sfText_destroy(assets->stats.score.text);
}

void destroyer(assets_t *assets)
{
    sprite_destroyer(assets);
    texture_destroyer(assets);
    clock_destroyer(assets);
    sound_destroyer(assets);
}
