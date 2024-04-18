/*
** EPITECH PROJECT, 2022
** srv
** File description:
** error_handler
*/

#include "my.h"

int is_num(char *s)
{
    int i;

    if (s[0] == '-')
        i = 1;
    else
        i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return (1);
}

int wrong_args(char **av)
{
    if (strcmp(av[1], "-p") != 0 || strcmp(av[3], "-g") != 0 ||
    strcmp(av[5], "-m") != 0) {
        return (84);
    }
    if (is_num(av[2]) == 0 || is_num(av[4]) == 0) {
        return (84);
    }
    return (0);
}

void push_back_blk(block_t *node, block_t **head)
{
    node->next = *head;
    *head = node;
}

void push_back(client_t *node, client_t **head)
{
    node->next = *head;
    *head = node;
}

client_t *init_clt(data_t *sv_d)
{
    client_t *new_client = malloc(sizeof(client_t) * 1);

    if (!new_client)
        return (NULL);
    if (!sv_d)
        exit(86);
    new_client->posX = 0;
    new_client->posY = 0;
    new_client->gotId = 0;
    new_client->gotMap = 0;
    new_client->Ready = 0;
    new_client->jetPack = 1;
    new_client->score = 0;
    new_client->id_sc = 0;
    return (new_client);
}
