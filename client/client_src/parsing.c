/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** parsing
*/

#include "client_structs.h"

void get_coin_pickup_pos(cli_et *client, char *str)
{
    char *id;
    char *x;
    char *y;

    strtok(str, " ");
    id = strtok(NULL, " ");
    x = strtok(NULL, " ");
    y = strtok(NULL, " ");

    if (atoi(id) == client->playerData->id_sc) {
        client->playerData->coinX = atoi(x);
        client->playerData->coinY = atoi(y);
    } else {
        client->playerData->coinX = -1;
        client->playerData->coinY = -1;
    }
    free(str);
}
