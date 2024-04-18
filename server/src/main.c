/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "my.h"

void clean_map(data_t *serv_data)
{
    int lim = strlen(serv_data->game->map);
    char *dupliMap = malloc(sizeof(char) * lim);
    int len = 0;

    if (dupliMap == NULL)
        exit(84);
    for (int i = 0; i < lim; i++) {
        if (serv_data->game->map[i] != '\n') {
            dupliMap[len++] = serv_data->game->map[i];
        }
    }
    dupliMap[len-1] = '\0';
    free(serv_data->game->map);
    serv_data->game->map = dupliMap;
}

void init_more_tings(data_t *serv_data, char **av)
{
    float x = 0;
    float y = 0;

    serv_data->game = malloc(sizeof(game_t) * 1);
    serv_data->game->blocks = NULL;
    serv_data->av = av;
    if (serv_data->game == NULL)
        exit(84);
    serv_data->game->map = get_map(av[6]);
    serv_data->game->nb_alive = 0;
    serv_data->game->gravity = atof(av[4]);

    for (int i = 0; serv_data->game->map[i] != '\0'; i++) {
        y = (serv_data->game->map[i] == '\n') ? y + 1 : y;
        x = (serv_data->game->map[i] == '\n') ? 0 : x + 1;
        init_two_point_o(serv_data, i, x, y);
    }
    serv_data->game->height = y;
    serv_data->game->width = x;
    clean_map(serv_data);
}

int start_server_game(char **av)
{
    data_t *my_serv_data = malloc(sizeof(data_t) * 1);

    my_serv_data->listened = 0;
    my_serv_data->startedGame = 0;
    if (my_serv_data == NULL)
        return (23);
    my_serv_data->buffer = malloc(sizeof(char) * 4096);
    if (!my_serv_data->buffer)
        return (21);
    my_serv_data->addrlen = sizeof(my_serv_data->address);
    my_serv_data->serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (my_serv_data->serv_fd == -1) {
        write(2, "Error, socket failed", 19);
        return (84);
    }
    init_more_tings(my_serv_data, av);
    return (server_loop(av[2], my_serv_data));
}

int main(int ac, char **av)
{
    if (ac != 7 || wrong_args(av) == 84) {
        return (84);
    } else {
        srand(time(NULL));
        start_server_game(av);
    }
    return (0);
}
