/*
** EPITECH PROJECT, 2022
** srv
** File description:
** firer
*/

#include "my.h"

void move_char(data_t *serv_data, clock_t now)
{
    client_t *tmp = serv_data->client_list;

    serv_data->sendPos = 0;
    if ((now - serv_data->before) * 100 / CLOCKS_PER_SEC < 2)
        return;
    serv_data->sendPos = 1;
    while (tmp) {
        if (tmp->posX + 0.1 < serv_data->game->width)
            tmp->posX += 0.1;
        else
            end_of_game(serv_data, 3, tmp);
        if (tmp->posY + 0.1 * tmp->jetPack < serv_data->game->height
        && tmp->posY + 0.1 * tmp->jetPack > 0)
            tmp->posY += 0.1 * tmp->jetPack;
        tmp = tmp->next;
    }
    serv_data->before = now;
}

void send_coin_pickup(client_t *pl, data_t *serv, block_t *blk)
{
    client_t *tmp = serv->client_list;

    while (tmp) {
        blk->score = 0;
        dprintf(tmp->fld, "COIN %d %.0f %.0f\n", pl->id_sc,
        blk->posX, blk->posY);
        tmp = tmp->next;
    }
}

void take_actions(block_t *block, client_t *player, data_t *serv_data)
{
    if (block->type == 'e') {
        end_of_game(serv_data, 1, player);
    } else {
        if (block->score != 0) {
            player->score += block->score;
            serv_data->sendPos = 3;
            send_coin_pickup(player, serv_data, block);
            block->score = 0;
        }
    }
}

void send_map(data_t *serv_data, int sckt)
{
    client_t *tmp = serv_data->client_list;

    while (tmp) {
        if (tmp->fld == sckt) {
            dprintf(sckt,"MAP %d %d %s\n", serv_data->game->width,
            serv_data->game->height, serv_data->game->map);
            tmp->gotMap = 1;
            break;
        }
        tmp = tmp->next;
    }
}

int same_coords(float Px, float Py, float Bx, float By)
{
    if (Px - Bx < 1 && Px - Bx > -1 && Py - By < 1 && Py - By > -1)
        return (1);
    return (0);
}
