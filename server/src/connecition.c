/*
** EPITECH PROJECT, 2022
** srv
** File description:
** connecition
*/

#include "my.h"

int server_loop(char *host, data_t *serv_data)
{
    serv_data->address.sin_family = AF_INET;
    serv_data->address.sin_addr.s_addr = INADDR_ANY;
    serv_data->address.sin_port = htons(atoi(host));
    serv_data->readiers = 0;
    serv_data->saidStart = 0;
    serv_data->changed_clock = 0;
    serv_data->before = clock();
    if (bind(serv_data->serv_fd, (struct sockaddr *)
        &(serv_data->address), serv_data->addrlen) < 0) {
        write(2, "Error, bind failed", 19);
        return (84);
    }
    if (listen(serv_data->serv_fd, 3) < 0) {
            write(2, "Error, listen failed", 20);
            return (84);
    }
    return (observer(serv_data));
}

block_t *init_block(float x, float y, char type)
{
    block_t *new_block = malloc(sizeof(block_t));

    if (new_block == NULL)
        return (NULL);
    new_block->posX = x;
    new_block->score = 1;
    new_block->posY = y;
    new_block->type = type;
    new_block->next = NULL;
    return (new_block);
}

int not_rect(char *map)
{
    int Ncount = 0;
    int width = 0;
    int newWidth = 0;
    int Nfound = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        Nfound = 1;
        width += 1;
        if (map[i] == '\n') {
            Ncount += 1;
            Nfound = 0;
            newWidth = (newWidth == 0) ? width : newWidth;
            width = (width == newWidth) ? 0 : -1;
        }
        if (width == -1)
            return (1);
    }
    if (width != newWidth - Nfound || Ncount == 0)
        return (1);
    return (0);
}

char *get_map(char *s)
{
    int file = open(s, O_RDONLY);
    int len = -1;
    char *map;
    struct stat st;

    if (file == -1) {
        write(2, "Error, file not found\n", 21);
        exit(84);
    }
    stat(s, &st);
    len = st.st_size;
    map = malloc(sizeof(char) * (len + 1));
    if (map == NULL || read(file, map, len) == -1 || len <= 2)
        exit(84);
    map[len] = '\0';
    close(file);
    if (not_rect(map) == 1)
        exit(0);
    return (map);
}

void init_two_point_o(data_t *serv_data, int i, int x, int y)
{
    block_t *new_block;

    if (serv_data->game->map[i] == 'e' || serv_data->game->map[i] == 'c') {
        new_block = init_block(x, y, serv_data->game->map[i]);
        if (new_block == NULL)
            exit(84);
        if (serv_data->game->blocks == NULL) {
            serv_data->game->blocks = new_block;
        } else
            push_back_blk(new_block, &(serv_data->game->blocks));
    }
}
