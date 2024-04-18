/*
** EPITECH PROJECT, 2021
** functions to set the rects part 2
** File description:
** set_rect2
*/

#include "jetpack.h"

void set_barry_rect(assets_t *assets)
{
    int ratio;

    assets->sprites.barry.track.time =
    sfClock_getElapsedTime(assets->sprites.barry.track.timer);
    assets->sprites.barry.track.seconds =
    assets->sprites.barry.track.time.microseconds / 1000000.0;
    ratio = assets->sprites.barry.track.seconds / 0.125;
    if (assets->sprites.barry.track.seconds >= 0.125) {
        assets->sprites.barry.rect.left += 50 * ratio;
        assets->sprites.barry.rect.left =
        (assets->sprites.barry.rect.left >= 200) ? 0 :
        assets->sprites.barry.rect.left;
        sfClock_restart(assets->sprites.barry.track.timer);
    }
    sfSprite_setTextureRect(assets->sprites.barry.sprite,
    assets->sprites.barry.rect);
}

void set_ghost_rect(assets_t *assets, cli_et *client)
{
    int ratio;

    assets->sprites.ghost.track.time =
    sfClock_getElapsedTime(assets->sprites.ghost.track.timer);
    assets->sprites.ghost.track.seconds =
    assets->sprites.ghost.track.time.microseconds / 1000000.0;
    ratio = assets->sprites.ghost.track.seconds / 0.125;
    if (assets->sprites.ghost.track.seconds >= 0.125) {
        assets->sprites.ghost.rect.top =
        (client->opponentData->jetPack == 1) ? 48 : 0;
        assets->sprites.ghost.rect.top = (assets->sprites.ghost.dead) ?
        192 : assets->sprites.ghost.rect.top;
        assets->sprites.ghost.rect.left += 50 * ratio;
        assets->sprites.ghost.rect.left =
        (assets->sprites.ghost.rect.left >= 200) ? 0 :
        assets->sprites.ghost.rect.left;
        sfClock_restart(assets->sprites.ghost.track.timer);
    }
    sfSprite_setTextureRect(assets->sprites.ghost.sprite,
    assets->sprites.ghost.rect);
}

void set_score(assets_t *assets)
{
    assets->stats.track.time =
    sfClock_getElapsedTime(assets->stats.track.timer);
    assets->stats.track.seconds =
    assets->stats.track.time.microseconds / 1000000.0;
    if (assets->stats.track.seconds >= 0.125) {
        sfText_setString(assets->stats.score.text,
        concat("Score: ", my_itoa(assets->stats.score.value)));
        sfClock_restart(assets->stats.track.timer);
    }
}

void set_scene_music(assets_t *assets)
{
    switch (assets->screens.current) {
        case WAITING:
            sfMusic_setVolume(assets->audio.wait_music, 20);
            sfMusic_setVolume(assets->audio.game_music, 0);
            sfMusic_setVolume(assets->audio.end_music, 0);
            break;
        case GAME:
            sfMusic_setVolume(assets->audio.wait_music, 0);
            sfMusic_setVolume(assets->audio.game_music, 20);
            sfMusic_setVolume(assets->audio.end_music, 0);
            break;
        case END:
            sfMusic_setVolume(assets->audio.wait_music, 0);
            sfMusic_setVolume(assets->audio.game_music, 0);
            sfMusic_setVolume(assets->audio.end_music, 20);
            break;
        default:
            break;
    }
}
