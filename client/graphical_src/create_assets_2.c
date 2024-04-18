/*
** EPITECH PROJECT, 2021
** functions to create assets part 2
** File description:
** create_assets_2
*/

#include "jetpack.h"

void create_sounds(assets_t *assets)
{
    assets->audio.scream.buffer =
    sfSoundBuffer_createFromFile("client/assets/Sounds/scream.ogg");
    assets->audio.scream.sound = sfSound_create();
    sfSound_setBuffer(assets->audio.scream.sound,
    assets->audio.scream.buffer);
    sfSound_setVolume(assets->audio.scream.sound, 20);
    assets->audio.scream.played = false;
    assets->audio.coin_pickup.buffer =
    sfSoundBuffer_createFromFile("client/assets/Sounds/coin_pickup.ogg");
    assets->audio.coin_pickup.sound = sfSound_create();
    sfSound_setBuffer(assets->audio.coin_pickup.sound,
    assets->audio.coin_pickup.buffer);
    sfSound_setVolume(assets->audio.coin_pickup.sound, 20);
    assets->audio.coin_pickup.played = false;
    assets->audio.jetpack_hover =
    sfMusic_createFromFile("client/assets/Sounds/jetpack_hover.ogg");
    sfMusic_setLoop(assets->audio.jetpack_hover, sfTrue);
    sfMusic_setVolume(assets->audio.jetpack_hover, 0);
    sfMusic_play(assets->audio.jetpack_hover);
}

void create_score_font(assets_t *assets)
{
    sfVector2f score_pos = {50, 10};

    assets->stats.score.value = 0;
    assets->stats.score.s_font =
    sfFont_createFromFile("client/assets/Fonts/font.TTF");
    assets->stats.score.text = sfText_create();
    sfText_setFont(assets->stats.score.text,
    assets->stats.score.s_font);
    sfText_setPosition(assets->stats.score.text, score_pos);
    sfText_setString(assets->stats.score.text,
    concat("Score: ", my_itoa(assets->stats.score.value)));
}

void create_music(assets_t *assets)
{
    assets->audio.wait_music =
    sfMusic_createFromFile("client/assets/Sounds/wait_music.ogg");
    sfMusic_setLoop(assets->audio.wait_music, sfTrue);
    sfMusic_setVolume(assets->audio.wait_music, 0);
    sfMusic_play(assets->audio.wait_music);
    assets->audio.game_music =
    sfMusic_createFromFile("client/assets/Sounds/subway_ost.ogg");
    sfMusic_setVolume(assets->audio.game_music, 0);
    sfMusic_play(assets->audio.game_music);
    sfMusic_setLoop(assets->audio.game_music, sfTrue);
    assets->audio.end_music =
    sfMusic_createFromFile("client/assets/Sounds/end_music.ogg");
    sfMusic_setVolume(assets->audio.end_music, 0);
    sfMusic_play(assets->audio.end_music);
    sfMusic_setLoop(assets->audio.end_music, sfTrue);
}
