/*
** EPITECH PROJECT, 2022
** srv
** File description:
** checkers
*/

#include "my.h"

void check_blocks(client_t *player, block_t *blocks, data_t *serv_data)
{
    while (blocks) {
        if (same_coords(player->posX, player->posY,
        blocks->posX, blocks->posY) == 1) {
            take_actions(blocks, player, serv_data);
        }
        blocks = blocks->next;
    }
}

void check_collision(data_t *serv_data)
{
    client_t *tmp = serv_data->client_list;
    block_t *tmp_blk = serv_data->game->blocks;

    while (tmp) {
        check_blocks(tmp, tmp_blk, serv_data);
        tmp_blk = serv_data->game->blocks;
        tmp = tmp->next;
    }
}

void fire_one(data_t *sr_dt, int sckt)
{
    client_t *tmp = sr_dt->client_list;

    while (tmp) {
        if (tmp->fld == sckt) {
            tmp->jetPack = -1;
            break;
        }
        tmp = tmp->next;
    }
}

void fire_zero(data_t *sr_dt, int sckt)
{
    client_t *tmp = sr_dt->client_list;

    while (tmp) {
        if (tmp->fld == sckt) {
            tmp->jetPack = 1;
            break;
        }
        tmp = tmp->next;
    }
}

void process_commands(data_t *serv_data)
{
    char *commands[3] = {"FIRE 1", "MAP", "FIRE 0"};
    void (*fct_ptr[3])(data_t *sr_dt, int sckt) = {fire_one,
    send_map, fire_zero};
    int i = 0;

    for (; i < 3; i++) {
        if (strncmp(commands[i], serv_data->buffer,
            strlen(commands[i])) == 0) {
            fct_ptr[i](serv_data, serv_data->tmp_skt);
            break;
        }
    }
}
