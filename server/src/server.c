/*
** EPITECH PROJECT, 2022
** srv
** File description:
** server
*/

#include "my.h"

void readyer(data_t *serv_data, int sckt)
{
    client_t *tmp = serv_data->client_list;

    if (serv_data->readiers == 2)
        return;
    while (tmp) {
        if (tmp->fld == sckt && tmp->gotMap == 1 && tmp->gotId == 1) {
            serv_data->readiers += 1;
            break;
        }
        tmp = tmp->next;
    }
}

void *handle_connections(int new_socket, data_t *sr_dt)
{
    char *commands[3] = {"ID", "MAP", "READY"};
    void (*fct_ptr[3])(data_t *sr_dt, int sckt) = {id_fill, send_map, readyer};
    int c_f = 0;
    int i = 0;

    clear_input_taken(new_socket, sr_dt);
    for (; i < 3 && sr_dt->readiers != 2; i++) {
        if (strncmp(commands[i], sr_dt->buffer, strlen(commands[i])) == 0) {
            c_f = 1;
            fct_ptr[i](sr_dt, new_socket);
            break;
        }
    }
    if (c_f == 0 && sr_dt->readiers != 2);
    else if (not_started_yet(sr_dt) == 1)
        return (NULL);
    else
        play_game(sr_dt);
    return (0);
}

void accept_new_connection(data_t *sv_d)
{
    client_t *new_client = init_clt(sv_d);

    if (new_client == NULL)
        exit(84);
    new_client->next = NULL;
    if ((sv_d->new_socket = accept(sv_d->serv_fd,(struct sockaddr *)
        &(sv_d->address), (socklen_t *)&(sv_d->addrlen))) < 0) {
        write(2, "Error, accept failed\n", 22);
        exit (84);
    }
    new_client->fld = sv_d->new_socket;
    if (sv_d->client_list == NULL) {
        sv_d->client_list = new_client;
    } else
        push_back(new_client, &(sv_d->client_list));
}

int stairer_observer(int i, data_t *serv_data)
{
    if (FD_ISSET(i, &serv_data->rd_s)) {
        if (i == serv_data->serv_fd && serv_data->listened != 2) {
            accept_new_connection(serv_data);
            serv_data->listened += 1;
            FD_SET(serv_data->new_socket, &serv_data->ensm);
        }
        if (!(i == serv_data->serv_fd && serv_data->listened != 2)
        && i != serv_data->serv_fd) {
            serv_data->tmp_skt = i;
            handle_connections(i, serv_data);
        }
    }
    return (0);
}

int observer(data_t *serv_data)
{
    serv_data->client_list = NULL;
    FD_ZERO(&(serv_data->ensm));
    FD_SET(serv_data->serv_fd, &(serv_data->ensm));
    while (1) {
        serv_data->rd_s = serv_data->ensm;
        if (select(FD_SETSIZE, &(serv_data->rd_s), NULL, NULL, NULL) < 0)
            exit (84);
        for (int i = 0; i < FD_SETSIZE; i++) {
            stairer_observer(i, serv_data);
        }
    }
    return (0);
}
