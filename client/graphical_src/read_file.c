/*
** EPITECH PROJECT, 2020
** read_file
** File description:
** read_file
*/

#include "jetpack.h"

void read_file(char *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
    char *str;

    str = malloc(sizeof(char) * 450);
    read(filedesc, str, 450);
    write(1, str, 450);
    close(filedesc);
}
