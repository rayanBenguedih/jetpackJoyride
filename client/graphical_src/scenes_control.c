/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** scenes_control
*/

#include "jetpack.h"

bool wait_screen_control(sfEvent *control, sfRenderWindow *window,
cli_et *client)
{
    bool close = false;

    if (client->start == 1)
        sfRenderWindow_close(window);
    while (sfRenderWindow_pollEvent(window, control)) {
        if ((control->type == sfEvtKeyReleased &&
        control->key.code == sfKeyEscape)
        || control->type == sfEvtClosed) {
            close = true;
            sfRenderWindow_close(window);
        }
    }
    return (close);
}

void end_screen_control(sfRenderWindow *endgame, sfEvent *control)
{
    while (sfRenderWindow_pollEvent(endgame, control)) {
        if ((control->type == sfEvtKeyReleased &&
        control->key.code == sfKeyEscape)
        || control->type == sfEvtClosed) {
            sfRenderWindow_close(endgame);
        }
    }
}

void wait_color_shift(assets_t *assets)
{
    if (assets->screens.wait_color.b <= 50)
        assets->screens.wait_color.loop = true;
    else if (assets->screens.wait_color.b >= 100)
        assets->screens.wait_color.loop = false;
    if (assets->screens.wait_color.b > (sfInt8)50 &&
    !assets->screens.wait_color.loop) {
        assets->screens.wait_color.r -= 1;
        assets->screens.wait_color.g -= 1;
        assets->screens.wait_color.b -= 1;
    } else {
        assets->screens.wait_color.r += 1;
        assets->screens.wait_color.g += 1;
        assets->screens.wait_color.b += 1;
    }
}

void spin_loading(assets_t *assets)
{
    float ratio;

    assets->sprites.walls.road.track.time =
    sfClock_getElapsedTime(assets->sprites.walls.road.track.timer);
    assets->sprites.walls.road.track.seconds =
    assets->sprites.walls.road.track.time.microseconds / 1000000.0;
    ratio = assets->sprites.walls.road.track.seconds / 0.05;
    if (assets->sprites.walls.road.track.seconds >= 0.05) {
        sfSprite_rotate(assets->screens.wait_screen.sprite, 4 * ratio);
        wait_color_shift(assets);
        sfClock_restart(assets->sprites.walls.road.track.timer);
    }
}
