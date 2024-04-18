/*
** EPITECH PROJECT, 2022
** client
** File description:
** client_structs
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct client_s {
    float posX;
    float posY;
    int jetPack;
    int score;
    int id_sc;
    int fld;
    bool scoreup;
    int gotMap;
    int Ready;
    int gotId;
    bool win;
    int coinX;
    int coinY;
    struct client_s *next;
}   client_t;

typedef struct cli_et cli_et;

struct cli_et {
    int socket;
    int port;
    char *ip;
    struct sockaddr_in addr;
    client_t *playerData;
    client_t *opponentData;
    char *map;
    int map_w;
    int map_h;
    int start;
    int coinX;
    int coinY;
    bool running;
    fd_set original;
    fd_set readable;
};

typedef struct blocks_s {
    float posX;
    float posY;
    char type;
    int score;
    struct blocks_s *next;
}   block_t;

typedef struct game_s {
    char *map;
    float gravity;
    int width;
    int height;
    int nb_alive;
    block_t *blocks;
} game_t;

typedef struct data_s {
    int new_socket;
    int serv_fd;
    int val_read;
    char *buffer;
    int tmp_skt;
    fd_set ensm;
    fd_set rd_s;
    struct sockaddr_in address;
    client_t *client_list;
    char **av;
    int addrlen;
    int startedGame;
    int listened;
    char sendPos;
    int readiers;
    int saidStart;
    clock_t before;
    int changed_clock;
    game_t *game;
}   data_t;

int quit(cli_et *a, char *b, char *c);

bool is_num(char *s);

int my_socket(int domain, int type, int protocol);

bool wrong_client_args(char **av);

int my_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

client_t *create_client(void);

void init_client(cli_et *client, char *ip, int port);

char *read_socket(cli_et *client, char *buffer);

void send_command(cli_et *client, int input);

void get_my_id(cli_et *client, char *str);

void get_my_map(cli_et *client, char *str);

void get_my_player(cli_et *client, char *str);

void get_coin_pickup_pos(cli_et *client, char *str);

void end_the_game(cli_et *client, char *str);

void update_details(cli_et *client, char *str);

int handler_socket(cli_et* client, int fd);

int handle_event_on_client(cli_et *client);

int communication(cli_et *client, int a);

void launch(void *data);
