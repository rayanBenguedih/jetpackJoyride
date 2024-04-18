/*
** EPITECH PROJECT, 2022
** srv
** File description:
** deplacer
*/

#include "my.h"

void clear_input_taken(int new_socket, data_t *serv_data)
{
    do {
        serv_data->val_read = read(new_socket, serv_data->buffer, 4096);
    } while (serv_data->val_read <= 2 || serv_data->buffer[0] < 0);
    for (int i = 0; serv_data->buffer[i] != '\0'; i++) {
        if (serv_data->buffer[i] == '\n' || serv_data->buffer[i] == 13) {
            serv_data->buffer[i] = '\0';
            break;
        }
    }
}

void liberate(data_t *serv_data)
{
    client_t *tmp = serv_data->client_list;
    block_t *tmp2 = serv_data->game->blocks;

    free(serv_data->buffer);
    free(serv_data->game->map);
    while (tmp) {
        tmp = tmp->next;
        free(serv_data->client_list);
        serv_data->client_list = tmp;
    }
    while (tmp2) {
        tmp2 = tmp2->next;
        free(serv_data->game->blocks);
        serv_data->game->blocks = tmp2;
    }
    free(serv_data->game);
    free(serv_data->client_list);
    free(serv_data);
}

int get_victor(data_t *serv_data, client_t *winner)
{
    client_t *tmp = serv_data->client_list;
    int bestP = winner->score;
    int winID = winner->id_sc;

    if (tmp->score == tmp->next->score)
        return (-1);
    while (tmp) {
        if (tmp->score > bestP) {
            bestP = tmp->score;
            winID = winner->id_sc;
        }
        tmp = tmp->next;
    }
    return (winID);
}

int get_loser(data_t *serv_data, client_t *winner)
{
    client_t *tmp = serv_data->client_list;
    int winnerID = -1;

    while (tmp) {
        if (tmp->fld != winner->fld) {
            winnerID = tmp->id_sc;
        }
        tmp = tmp->next;
    }
    return (winnerID);
}

int end_of_game(data_t *serv_data, int type, client_t *winner)
{
    int winID = -1;
    client_t *tmp = serv_data->client_list;

    if (type == 3)
        winID = get_victor(serv_data, winner);
    else if (type == 1) {
        winID = get_loser(serv_data, winner);
    }
    while (tmp) {
        dprintf(tmp->fld, "FINISH %d\n", winID);
        tmp = tmp->next;
    }
    liberate(serv_data);
    exit(0);
}
