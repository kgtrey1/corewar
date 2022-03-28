/*
** EPITECH PROJECT, 2020
** parameter.c
** File description:
** This file handles parameters for an instuction in corewar project
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void put_parameter_in_var(char *binary, enum parameter_types arg,
    int index)
{
    switch (arg) {
        case REGISTER:
            binary[index] = '0';
            binary[index + 1] = '1';
            break;
        case DIRECT:
            binary[index] = '1';
            binary[index + 1] = '0';
            break;
        case INDIRECT:
            binary[index] = '1';
            binary[index + 1] = '1';
            break;
    }
}

int get_parameter_types_hexa(int nbr_params, ...)
{
    char *binary = malloc(sizeof(char) * (8 + 1));
    int index = 0;
    va_list list;

    if (binary == NULL)
        return (0);
    for (int i = 0; i < 8; i++)
        binary[i] = '0';
    va_start(list, nbr_params);
    for (int i = 0; i < nbr_params; i++) {
        put_parameter_in_var(binary,
        va_arg(list, enum parameter_types), index);
        index += 2;
    }
    binary[8] = '\0';
    va_end(list);
    return (my_binary_to_int(binary));
}

int get_param_type_according_to_nbr(instruction_t *i)
{
    switch (i->nb_params) {
        case 1:
            return get_parameter_types_hexa(1, i->params[0].type);
        case 2:
            return get_parameter_types_hexa(2, i->params[0].type,
                i->params[1].type);
        case 3:
            return get_parameter_types_hexa(3, i->params[0].type,
                i->params[1].type, i->params[2].type);
    }
    return (0);
}