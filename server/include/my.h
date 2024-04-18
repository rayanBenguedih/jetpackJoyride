/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** my
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
    struct client_s *next;
} client_t;

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
    fd_set original;
    fd_set readable;
    char *user_name;
    char *uuid;
};

typedef struct blocks_s {
    float posX;
    float posY;
    char type;
    int score;
    struct blocks_s *next;
} block_t;

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
} data_t;

int is_num(char *s);

int wrong_args(char **av);

void push_back_blk(block_t *node, block_t **head);

void push_back(client_t *node, client_t **head);

client_t *init_clt(data_t *sv_d);

void clear_input_taken(int new_socket, data_t *serv_data);

void liberate(data_t *serv_data);

int get_victor(data_t *serv_data, client_t *winner);

int get_loser(data_t *serv_data, client_t *winner);

int end_of_game(data_t *serv_data, int type, client_t *winner);

void move_char(data_t *serv_data, clock_t now);

void send_coin_pickup(client_t *pl, data_t *serv, block_t *blk);

void take_actions(block_t *block, client_t *player, data_t *serv_data);

void send_map(data_t *serv_data, int sckt);

int same_coords(float Px, float Py, float Bx, float By);

void check_blocks(client_t *player, block_t *blocks, data_t *serv_data);

void check_collision(data_t *serv_data);

void fire_one(data_t *sr_dt, int sckt);

void fire_zero(data_t *sr_dt, int sckt);

void process_commands(data_t *serv_data);

void send_playing(data_t *serv_data);

void play_game(data_t *serv_data);

int not_started_yet(data_t *serv_data);

int get_unique_id(client_t *list);

void id_fill(data_t *serv_data, int sckt);

void readyer(data_t *serv_data, int sckt);

void *handle_connections(int new_socket, data_t *sr_dt);

void accept_new_connection(data_t *sv_d);

int stairer_observer(int i, data_t *serv_data);

int observer(data_t *serv_data);

int server_loop(char *host, data_t *serv_data);

block_t *init_block(float x, float y, char type);

int not_rect(char *map);

char *get_map(char *s);

void init_two_point_o(data_t *serv_data, int i, int x, int y);

void clean_map(data_t *serv_data);

void init_more_tings(data_t *serv_data, char **av);

int start_server_game(char **av);
