/*
** EPITECH PROJECT, 2022
** client
** File description:
** additional
*/

#include "client_structs.h"

int handle_event_on_client(cli_et *client)
{

    for (int i = 0; i != client->socket + 1; i++) {
        if (handler_socket(client, i) == 19)
            return 0;
    }
    return (EXIT_SUCCESS);
}

int communication(cli_et *clt, int a)
{
    clt->running = true;
    while (clt->running) {
        if (clt->playerData->gotMap != 0 && clt->playerData->Ready == 0) {
            dprintf(clt->socket, "READY\n");
        }
        if (clt->playerData->gotId == 0) {
            dprintf(clt->socket, "ID\n");
        }
        if (clt->playerData->gotId != 0 && clt->playerData->gotMap == 0) {
            dprintf(clt->socket, "MAP\n");
        }
        clt->readable = clt->original;
        if (handle_event_on_client(clt) == 19) {
            printf("supposedly stopped\n");
            return (0);
        }
    }
    if (a == 2)
        return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

void launch(void *data)
{
    cli_et *clt = data;
    int ret = 0;

    clt->addr.sin_family = AF_INET;
    clt->addr.sin_port = htons(clt->port);
    clt->addr.sin_addr.s_addr = inet_addr(clt->ip);
    clt->socket = my_socket(AF_INET, SOCK_STREAM, 0);
    FD_ZERO(&clt->original);
    FD_SET(clt->socket, &clt->original);
    FD_SET(0, &clt->original);
    if (inet_pton(AF_INET, clt->ip, &clt->addr.sin_addr) <= 0) {
        exit(84);
    }
    my_connect(clt->socket, (struct sockaddr *)&clt->addr, sizeof(clt->addr));
    communication(clt, ret);
}
