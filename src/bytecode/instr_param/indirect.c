/*
** EPITECH PROJECT, 2020
** indirect.c
** File description:
** This is a file handles the indirect type arguements for instructions.
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include <stdio.h>
#include <stdlib.h>

int get_indirect_value(param_t param)
{
    if (my_get_index_char(param.param, LABEL_CHAR, 1) == -1)
        return my_str_to_int(my_cut_string(param.param, 0,
            my_strlen(param.param)));
    else {
        return -1;
    }
    return -1;
}

void get_indirect_arg(int *to_fill, param_t param,
    int *index)
{
    for (int i = 0; i < IND_SIZE - 1; i++) {
        to_fill[*index] = 0;
        *index = *index + 1;
    }
    to_fill[*index] = get_indirect_value(param);
    *index = *index + 1;
}