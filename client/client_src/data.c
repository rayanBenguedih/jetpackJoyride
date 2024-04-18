/*
** EPITECH PROJECT, 2022
** client
** File description:
** data
*/

#include "client_structs.h"

void get_my_map(cli_et *client, char *str)
{
    char *width = strtok(str, " ");
    char *height;
    char *str_map;

    width = strtok(NULL, " ");
    height = strtok(NULL, " ");
    str_map = strtok(NULL, " ");
    client->map = strdup(str_map);
    client->map_w = atoi(width);
    client->map_h = atoi(height);
    client->playerData->gotMap = 1;
    free(str);
}

void get_my_player(cli_et *client, char *str)
{
    char *id = strtok(str, " ");
    char *x;
    char *y;

    id = strtok(NULL, " ");
    x = strtok(NULL, " ");
    y = strtok(NULL, " ");
    if (atoi(id) == client->playerData->id_sc) {
        client->playerData->posX = atof(x);
        client->playerData->posY = atof(y);
    } else {
        client->opponentData->posX = atof(x);
        client->opponentData->posY = atof(y);
    }
    free(str);
}

void end_the_game(cli_et *client, char *str)
{
    char *id = strtok(str, " ");

    id = strtok(NULL, " ");
    printf("winner %s\n", id);
    client->running = false;
    if (atoi(id) != -1) {
        client->playerData->win = atoi(id) == client->playerData->id_sc;
        client->opponentData->win = atoi(id) != client->playerData->id_sc;
    } else {
        client->playerData->win = true;
        client->opponentData->win = true;
    }
    if (client->playerData->win)
        printf("You win !\n");
    else
        printf("You lose !\n");
    if (client->opponentData->win)
        printf("Your opponent win !\n");
    else
        printf("Your opponent lose !\n");
}

void update_details(cli_et *client, char *str)
{
    if (strncmp(str, "PLAYER", 6) != 0)
        printf("%s\n", str);
    if (strncmp(str, "ID", 2) == 0)
        get_my_id(client, strdup(str));
    if (strcmp(str, "START\n") == 0)
        client->start = 1;
    if (strncmp(str, "MAP", 3) == 0)
        get_my_map(client, strdup(str));
    if (strncmp(str, "PLAYER", 6) == 0)
        get_my_player(client, strdup(str));
    if (strncmp(str, "COIN", 4) == 0) {
        get_coin_pickup_pos(client, strdup(str));
        client->playerData->scoreup = true;
    }
    if (strncmp(str, "FINISH", 6) == 0)
        end_the_game(client, strdup(str));
}

int handler_socket(cli_et* client, int fd)
{
    char *_read = malloc(sizeof(char) * BUFFER_SIZE);

    if (client->running == false) {
        free(_read);
        return (19);
    }
    if (FD_ISSET(fd, &client->readable) && fd == 0) {
        send_command(client, client->playerData->jetPack);
    } else if (FD_ISSET(fd, &client->readable) && fd == client->socket) {
        _read = read_socket(client, _read);
        update_details(client, _read);
    } else {
        free(_read);
        return EXIT_FAILURE;
    }
    free(_read);
    return (0);
}
