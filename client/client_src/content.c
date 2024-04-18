/*
** EPITECH PROJECT, 2022
** client
** File description:
** content
*/

#include "client_structs.h"

client_t *create_client(void)
{
    client_t *client = malloc(sizeof(client_t));

    client->posX = 0;
    client->posY = 0;
    client->jetPack = 0;
    client->score = 0;
    client->id_sc = -1;
    client->fld = 0;
    client->gotMap = 0;
    client->Ready = 0;
    client->gotId = 0;
    client->scoreup = false;
    client->win = false;
    return (client);
}

void init_client(cli_et *client, char *ip, int port)
{
    client->socket = -1;
    client->port = port;
    client->ip = ip;
    client->playerData = create_client();
    client->opponentData = create_client();
    client->map = NULL;
    client->start = 0;
}

char *read_socket(cli_et *client, char *buffer)
{
    int len = 0;

    if (client->running == false)
        return (NULL);
    if (select(client->socket + 1, &client->readable, NULL, NULL, NULL) == -1)
        exit(84);
    ioctl(client->socket, FIONREAD, &len);
    if (len > BUFFER_SIZE) {
        free(buffer);
        buffer = malloc(sizeof(char) * (len + 1));
    }
    read(client->socket, buffer, len);
    buffer[len] = '\0';
    return (buffer);
}

void send_command(cli_et *client, int input)
{
    dprintf(client->socket, "FIRE %d\n", input);
}

void get_my_id(cli_et *client, char *str)
{
    char *id = strtok(str, " ");

    id = strtok(NULL, " ");
    client->playerData->id_sc = atoi(id);
    client->playerData->gotId = 1;
    free(str);
}
