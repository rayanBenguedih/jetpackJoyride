/*
** EPITECH PROJECT, 2020
** structures for hunter
** File description:
** hunter_struct
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum escenes {
    WAITING = 0,
    GAME = 1,
    END = 2
} escenes_t;

typedef struct {
    sfClock* timer;
    sfTime time;
    float seconds;
} timestruct_t;

typedef struct {
    sfSprite *sprite;
    sfTexture* texture;
    sfIntRect rect;
    timestruct_t track;
} asset_sptex_t;

typedef struct {
    sfSprite *sprite;
    sfTexture* sprite_texture;
    sfIntRect rect;
    int stat;
    timestruct_t track;
} asset_sptexstat_t;

typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
    bool played;
} sound_struct_t;

typedef struct {
    sfSprite *sprite;
    sfTexture* texture;
    sfIntRect rect;
    timestruct_t track;
} asset_wall_t;

typedef struct {
    sfSprite *sprite;
    sfTexture* texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f map_pos;
    bool picked;
} asset_obstacle_t;

typedef struct {
    asset_wall_t road;
    asset_wall_t wall_1;
    asset_wall_t wall_2;
    asset_wall_t wall_3;
} assets_wall_group_track_t;

typedef struct {
    sfSprite *sprite;
    sfTexture* texture;
    sfIntRect rect;
    sfVector2f pos;
    timestruct_t jump_track;
    timestruct_t track;
    bool fire;
    bool dead;
} asset_sprite_track_t;

typedef struct {
    sfFont *s_font;
    sfText *text;
    unsigned long value;
} score_t;

typedef struct {
    sfSprite *sprite;
    sfTexture* texture;
} screen_t;

typedef struct {
    sfMusic *wait_music;
    sfMusic *game_music;
    sfMusic *end_music;
    sfMusic *jetpack_hover;
    int radio_piker;
    sound_struct_t scream;
    sound_struct_t coin_pickup;
} sound_assets_t;

typedef struct {
    asset_obstacle_t *fireballs;
    asset_obstacle_t *coins;
    timestruct_t fireballs_track;
    timestruct_t coins_track;
} asset_sprite_group_t;

typedef struct {
    asset_sprite_track_t barry;
    asset_sprite_track_t ghost;
    timestruct_t pos_update;
    assets_wall_group_track_t walls;
} graphical_assets_t;

typedef struct {
    char **level;
    size_t nb_fireballs;
    size_t nb_coins;
    asset_sprite_group_t obstacles;
    size_t x_max;
    size_t y_max;
    float spacing;
} map_data_t;

typedef struct {
    score_t score;
    timestruct_t track;
} stats_t;

typedef struct {
    sfInt8 r;
    sfInt8 g;
    sfInt8 b;
    bool loop;
} rgb_t;

typedef struct {
    screen_t wait_screen;
    screen_t end_screen;
    rgb_t wait_color;
    escenes_t current;
} scenes_t;

typedef struct {
    float pos_x;
    float pos_y;
    bool updated;
    bool dead;
} player_pos_t;

typedef struct {
    sound_assets_t audio;
    graphical_assets_t sprites;
    map_data_t map;
    stats_t stats;
    scenes_t screens;
} assets_t;
