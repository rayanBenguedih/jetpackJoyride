/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** scenes
*/

#include "jetpack.h"

bool wait_screen(assets_t *assets, cli_et *client)
{
    bool close = false;
    sfRenderWindow *winwait = create_renderwindow(1920, 1080, 32, "Jetpack");
    sfEvent control;

    sfRenderWindow_setFramerateLimit(winwait, 60);
    create_assets(assets);
    assets->screens.current = WAITING;
    while (sfRenderWindow_isOpen(winwait)) {
        sfRenderWindow_display(winwait);
        sfRenderWindow_clear(winwait,
        sfColor_fromRGB(assets->screens.wait_color.r,
        assets->screens.wait_color.g, assets->screens.wait_color.b));
        spin_loading(assets);
        sfRenderWindow_drawSprite(winwait,
        assets->screens.wait_screen.sprite, NULL);
        set_scene_music(assets);
        close = wait_screen_control(&control, winwait, client);
    }
    return close;
}

void main_game(assets_t *assets, cli_et *client)
{
    sfRenderWindow *wingame = create_renderwindow(1920, 1080, 32, "jetpack");
    sfEvent control;

    sfRenderWindow_setFramerateLimit(wingame, 60);
    assets->map.spacing = 820 / client->map_h;
    assets->map.x_max = client->map_w;
    assets->map.y_max = client->map_h;
    assets->screens.current = GAME;
    init_map(assets, client->map);
    create_obstacles(assets);
    while (sfRenderWindow_isOpen(wingame)) {
        set_rects(assets, client);
        sfRenderWindow_display(wingame);
        control_window(wingame, control, assets, client);
        if (!client->running)
            sfRenderWindow_close(wingame);
    }
}

void end_game_displayer(assets_t *assets, sfRenderWindow *endgame,
cli_et *client)
{
    sfRenderWindow_display(endgame);
    sfRenderWindow_clear(endgame, sfBlack);
    sfRenderWindow_drawSprite(endgame,
    assets->screens.end_screen.sprite, NULL);
    sfRenderWindow_drawSprite(endgame,
    assets->screens.end_screen.sprite, NULL);
    sfRenderWindow_drawSprite(endgame,
    assets->sprites.barry.sprite, NULL);
    sfRenderWindow_drawSprite(endgame,
    assets->sprites.ghost.sprite, NULL);
    if (!client->playerData->win)
        dying_barry_fall(assets);
    if (!client->opponentData->win)
        dying_ghost_fall(assets);
}

void end_game(assets_t *assets, cli_et *client)
{
    sfRenderWindow *endgame = create_renderwindow(1920, 1080, 32, "jetpack");
    sfEvent control;

    sfMusic_setVolume(assets->audio.jetpack_hover, 0);
    sfRenderWindow_setFramerateLimit(endgame, 60);
    assets->screens.current = END;
    sfSprite_setPosition(assets->sprites.barry.sprite,
    (sfVector2f) {1920 / 5 * 2, 700});
    sfSprite_setPosition(assets->sprites.ghost.sprite,
    (sfVector2f) {1920 / 5 * 3, 700});
    while (sfRenderWindow_isOpen(endgame)) {
        end_game_displayer(assets, endgame, client);
        end_screen_control(endgame, &control);
        set_barry_rect(assets);
        set_ghost_rect(assets, client);
        set_scene_music(assets);
    }
}

void central(void *vclient)
{
    cli_et *client = (cli_et *) vclient;
    assets_t assets;

    if (wait_screen(&assets, client))
        return;
    main_game(&assets, client);
    end_game(&assets, client);
    destroyer(&assets);
}
