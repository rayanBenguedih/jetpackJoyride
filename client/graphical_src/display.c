/*
** EPITECH PROJECT, 2020
** central functions for window display
** File description:
** as abov
*/

#include "jetpack.h"

sfRenderWindow *create_renderwindow(unsigned int x,
unsigned int y, unsigned int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};

    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}

void illustrator(sfRenderWindow *window, assets_t *assets)
{
    sfRenderWindow_drawSprite(window,
    assets->sprites.walls.wall_3.sprite, NULL);
    sfRenderWindow_drawSprite(window,
    assets->sprites.walls.wall_2.sprite, NULL);
    sfRenderWindow_drawSprite(window,
    assets->sprites.walls.wall_1.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->sprites.walls.road.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->sprites.ghost.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->sprites.barry.sprite, NULL);
    sfRenderWindow_drawText(window, assets->stats.score.text, NULL);
    for (size_t i = 0; i < assets->map.nb_coins; i++)
        sfRenderWindow_drawSprite(window,
        assets->map.obstacles.coins[i].sprite, NULL);
    for (size_t i = 0; i < assets->map.nb_fireballs; i++)
        sfRenderWindow_drawSprite(window,
        assets->map.obstacles.fireballs[i].sprite, NULL);
}

void control_window(sfRenderWindow *window, sfEvent event,
assets_t *assets, cli_et *client)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        simple_controls(window, event, assets, client);
    }
    sfRenderWindow_clear(window, sfBlack);
    illustrator(window, assets);
}
