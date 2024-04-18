/*
** EPITECH PROJECT, 2021
** str_managment
** File description:
** str_managment
*/

#include "jetpack.h"

char *my_itoa(int n)
{
    char *str = malloc(sizeof(char) * my_int_len(n) + 1);

    sprintf(str, "%d", n);
    return str;
}

int my_int_len(int nb)
{
    int i = 1;

    while (nb > 9) {
        nb /= 10;
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    char *str2 = malloc(sizeof(char) * strlen(str) + 1);

    while (j >= 0) {
        str2[i] = str[j];
        i++;
        j--;
    }
    str2[i] = '\0';
    return (str2);
}

char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
