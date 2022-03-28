/*
** EPITECH PROJECT, 2020
** direct.c
** File description:
** This is a file handles the direct type arguements for instructions.
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include <stdio.h>
#include <stdlib.h>

int get_direct_value(param_t param)
{
    int index = my_get_index_char(param.param, LABEL_CHAR, 1);

    if (index == -1)
        return my_str_to_int(my_cut_string(param.param, 1,
            my_strlen(param.param)));
    else {
        return -1;
    }
    return -1;
}

void get_direct_arg(int *to_fill, param_t param,
    int *index)
{
    for (int i = 0; i < DIR_SIZE - 1; i++) {
        to_fill[*index] = 0;
        *index = *index + 1;
    }
    to_fill[*index] = get_direct_value(param);
    *index = *index + 1;
}