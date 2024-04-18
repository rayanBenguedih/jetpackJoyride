/*
** EPITECH PROJECT, 2021
** functions relatives to controls
** File description:
** simple_controls
*/

#include "jetpack.h"

void send_fire(bool active, cli_et *client)
{
    if (active)
        client->playerData->jetPack = 1;
    else
        client->playerData->jetPack = 0;
}

void radio_control(sfEvent *event, assets_t *assets) {
    if (event->type == sfEvtKeyReleased &&
    event->key.code == sfKeyRight) {
        assets->audio.radio_piker =
        (assets->audio.radio_piker > 2) ? 0 : assets->audio.radio_piker + 1;
    }
    if (event->type == sfEvtKeyReleased &&
    event->key.code == sfKeyLeft) {
        assets->audio.radio_piker =
        (assets->audio.radio_piker < 0) ? 2 : assets->audio.radio_piker - 1;
    }
}

void simple_controls(sfRenderWindow *window, sfEvent event,
assets_t *assets, cli_et *client)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (assets->sprites.barry.dead)
        return;
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeySpace) {
        if (!assets->sprites.barry.fire) {
            send_fire(true, client);
            assets->sprites.barry.rect.top = 48;
            sfMusic_setVolume(assets->audio.jetpack_hover, 20);
        }
    }
    radio_control(&event, assets);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace) {
        send_fire(false, client);
        sfMusic_setVolume(assets->audio.jetpack_hover, 0);
        assets->sprites.barry.rect.top = 0;
    }
}

void dying_barry_fall(assets_t *assets)
{
    float ratio = assets->sprites.walls.road.track.seconds / 0.0166666;

    assets->sprites.barry.dead = true;
    if (assets->sprites.walls.road.track.seconds >= 0.0166666) {
        sfSprite_rotate(assets->sprites.barry.sprite, 2 * ratio);
        assets->sprites.barry.rect.top = 192;
    }
    if (!assets->audio.scream.played) {
        sfSound_play(assets->audio.scream.sound);
        assets->audio.scream.played = true;
    }
}

void dying_ghost_fall(assets_t *assets)
{
    float ratio = assets->sprites.walls.road.track.seconds / 0.0166666;

    assets->sprites.ghost.dead = true;
    if (assets->sprites.walls.road.track.seconds >= 0.0166666) {
        sfSprite_rotate(assets->sprites.ghost.sprite, 2 * ratio);
        assets->sprites.ghost.rect.top = 192;
    }
    if (!assets->audio.scream.played) {
        sfSound_play(assets->audio.scream.sound);
        assets->audio.scream.played = true;
    }
}
