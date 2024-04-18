/*
** EPITECH PROJECT, 2020
** h file
** File description:
** wow
*/

#pragma once

#include "jetpack_struct.h"
#include "client_structs.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define _README_ "resources/read_me.txt"

void simple_controls(sfRenderWindow *window, sfEvent mouse_clic,
assets_t *assets, cli_et *client);
void control_window(sfRenderWindow *window, sfEvent mouse_clic,
assets_t *assets, cli_et *client);
void central(void *client);
sfRenderWindow *create_renderwindow(unsigned int x,
unsigned int y, unsigned int bpp, char *title);
bool wait_screen_control(sfEvent *control, sfRenderWindow *window,
cli_et *client);
void end_screen_control(sfRenderWindow *endgame, sfEvent *control);

//assets creation
void read_file(char *filepath);
void create_assets(assets_t *assets);
void create_rects(assets_t *assets);
void create_clocks(assets_t *assets);
void create_barry_rect(assets_t *assets);
void create_ghost_rect(assets_t *assets);
void create_fireballs(assets_t *assets);
void create_coins(assets_t *assets);
void create_obstacles(assets_t *assets);
void create_music(assets_t *assets);
void create_sounds(assets_t *assets);
void create_score_font(assets_t *assets);
void set_fireball_positions(assets_t *assets);
void set_coin_positions(assets_t *assets);
void init_map(assets_t *assets, char *newmap);
void create_menus_texts(assets_t *assets);

//assets update
void set_rects(assets_t *assets, cli_et *client);
void set_barry_rect(assets_t *assets);
void set_ghost_rect(assets_t *assets, cli_et *client);
void set_coins_pos(assets_t *assets);
void set_fireballs_pos(assets_t *assets);
void set_fireballs_rects(assets_t *assets);
void set_coins_rects(assets_t *assets);
void set_scene_music(assets_t *assets);
void set_score(assets_t *assets);
bool fireball_hit(assets_t *assets);
void coin_hit(assets_t *assets);
void destroyer(assets_t *assets);
void update_coins(assets_t *assets, cli_et *client);
void dying_barry_fall(assets_t *assets);
void dying_ghost_fall(assets_t *assets);
void spin_loading(assets_t *assets);

//practical functions
void open_file(char *filepath, assets_t *assets);
int get_obstacle_nb(assets_t *assets, char obstacle);
int my_int_len(int nb);
void jump(assets_t *assets);
char *my_itoa(int n);
char *my_revstr(char *str);
char *concat(const char *s1, const char *s2);
