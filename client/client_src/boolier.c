/*
** EPITECH PROJECT, 2022
** client
** File description:
** boolier
*/

#include "client_structs.h"

int quit(cli_et *a, char *b, char *c)
{
    if (a == NULL)
        exit(84);
    if (b)
        free(b);
    b = NULL;
    if (c)
        free(c);
    exit(1);
}

bool is_num(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

int my_socket(int domain, int type, int protocol)
{
    int serverfd = -1;

    serverfd = socket(domain, type, protocol);
    if (serverfd == -1) {
        perror("Error server\n");
        return (-1);
    }
    return (serverfd);
}

bool wrong_client_args(char **av)
{
    if (strcmp(av[1], "-h") != 0
        || strcmp(av[3], "-p") != 0 || !is_num(av[4])) {
        return true;
    }
    return false;
}

int my_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int my_connect = -1;

    my_connect = connect(sockfd, addr, addrlen);
    if (my_connect == -1) {
        perror("connect");
        exit(84);
    }
    return 0;
}
