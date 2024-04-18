/*
** EPITECH PROJECT, 2022
** B-SYN-400-LIL-4-1-jetpack2tek3-antoine.jumeaux
** File description:
** map2
*/

#include "jetpack.h"

void init_map(assets_t *assets, char *newmap)
{
    int indx = 0;
    size_t j = 0;

    assets->map.y_max += 1;
    assets->map.level = malloc(sizeof(char *) * (assets->map.y_max + 2));
    for (size_t i = 0; i < assets->map.y_max; i++)
        assets->map.level[i] = malloc(sizeof(char) * (assets->map.x_max + 2));
    for (size_t i = 0; i < assets->map.y_max; i++) {
        for (j = 0; j < assets->map.x_max; j++) {
            assets->map.level[i][j] = (newmap[indx] == '\n') ?
            '_' : newmap[indx++];
        }
    }
    assets->map.level[assets->map.y_max + 1] = NULL;
    for (size_t i = 0; i < assets->map.y_max; i++)
        assets->map.level[i][assets->map.x_max + 1] = '\0';
}

void update_barry_pos(assets_t *assets, char *posxy)
{
    char *x = strtok(posxy, " ");
    char *y = strtok(NULL, " ");

    assets->sprites.barry.pos.x = atof(x);
    assets->sprites.barry.pos.y = atof(y);
}
