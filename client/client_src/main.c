/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** main
*/

#include "jetpack.h"

sfThread *start_graphic_thread(cli_et *client)
{
    sfThread *graphic_thread = sfThread_create(central, client);

    sfThread_launch(graphic_thread);
    return (graphic_thread);
}

sfThread *start_client_thread(cli_et *client)
{
    sfThread *client_thread = sfThread_create(launch, client);

    sfThread_launch(client_thread);
    return client_thread;
}

int main(int ac, char **av)
{
    cli_et client;
    sfThread *client_thread;
    sfThread *graphic_thread;

    if (ac != 5 || wrong_client_args(av)) {
        return (84);
    }
    init_client(&client, av[2], atoi(av[4]));
    printf("Started client thread\n");
    graphic_thread = start_graphic_thread(&client);
    client_thread = start_client_thread(&client);
    sfThread_wait(client_thread);
    sfThread_wait(graphic_thread);
    return (0);
}
