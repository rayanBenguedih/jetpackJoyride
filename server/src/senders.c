/*
** EPITECH PROJECT, 2022
** srv
** File description:
** senders
*/

#include "my.h"

void send_playing(data_t *serv_data)
{
    client_t *tmp = serv_data->client_list;

    if (serv_data->sendPos == 1) {
        dprintf(tmp->fld, "PLAYER %d %0.1f %0.1f\n", tmp->id_sc,
        tmp->posX, tmp->posY);
        dprintf(tmp->fld, "PLAYER %d %0.1f %0.1f\n", tmp->next->id_sc,
        tmp->next->posX, tmp->next->posY);
        dprintf(tmp->next->fld, "PLAYER %d %0.1f %0.1f\n",
        tmp->id_sc, tmp->posX, tmp->posY);
        dprintf(tmp->next->fld, "PLAYER %d %0.1f %0.1f\n",
        tmp->next->id_sc, tmp->next->posX, tmp->next->posY);
    }
    if (serv_data->sendPos == 0) {
        while (tmp) {
            dprintf(tmp->fld, "PLAYER %d %0.1f %0.1f\n", tmp->id_sc,
            tmp->posX, tmp->posY);
            tmp = tmp->next;
        }
    }
    serv_data->sendPos = 0;
}

void play_game(data_t *serv_data)
{
    client_t *tmp = serv_data->client_list;
    clock_t now = clock();

    process_commands(serv_data);
    while (tmp && serv_data->saidStart == 0) {
        dprintf(tmp->fld, "START\n");
        tmp->posY = serv_data->game->height / 2;
        tmp = tmp->next;
    }
    serv_data->saidStart = 1;
    move_char(serv_data, now);
    check_collision(serv_data);
    send_playing(serv_data);
}

int not_started_yet(data_t *serv_data)
{
    if (serv_data->readiers != 2)
        return (1);
    return (0);
}

int get_unique_id(client_t *list)
{
    client_t *tmp = list;
    int val = rand() % 100;

    while (tmp) {
        if (tmp->id_sc == val)
            return (get_unique_id(list));
        tmp = tmp->next;
    }
    return (val);
}

void id_fill(data_t *serv_data, int sckt)
{
    client_t *tmp = serv_data->client_list;

    while (tmp) {
        if (tmp->fld == sckt && tmp->gotId == 0) {
            tmp->id_sc = get_unique_id(serv_data->client_list);
            dprintf(sckt, "ID %d\n", tmp->id_sc);
            tmp->gotId = 1;
            break;
        }
        tmp = tmp->next;
    }
}
