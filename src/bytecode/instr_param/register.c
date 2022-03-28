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

void get_register_arg(int *to_fill, param_t param, int *index)
{
    to_fill[*index] = my_str_to_int(my_cut_string(param.param,
        1, my_strlen(param.param)));
    *index = *index + 1;
}