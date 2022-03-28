/*
** EPITECH PROJECT, 2020
** my_int_to_hexa.c
** File description:
** This is a file for the project
*/

#include "my.h"
#include <stdio.h>

void end_of_int_to_hexa(int i, char *to_return)
{
    if (i == 1)
        to_return[i++] = '0';
    else if (i == 0) {
        to_return[i++] = '0';
        to_return[i++] = '0';
    }
    to_return[i++] = '\0';
}

char *my_int_to_hexa(int a)
{
    long quotient = (long) a;
    long remainder = 0;
    int i = 0;
    char *to_return = malloc(sizeof(char) * 15);

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            to_return[i++] = 48 + remainder;
        else
            to_return[i++] = 55 + remainder;
        quotient = quotient / 16;
    }
    end_of_int_to_hexa(i, to_return);
    return my_revstr(to_return);
}