/*
** EPITECH PROJECT, 2020
** instr_param.c
** File description:
** This is a file gives you the parameters in hex value
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int get_size_according_to_param_type(param_t param)
{
    switch (param.type) {
        case REGISTER:
            return (1);
        case INDIRECT:
            return (IND_SIZE);
        case DIRECT:
            return (DIR_SIZE);
    }
    return (0);
}

void fill_var_according_to_params(int *to_fill,
    param_t param, int *index)
{
    switch (param.type) {
        case REGISTER:
            get_register_arg(to_fill, param, index);
            break;
        case INDIRECT:
            get_indirect_arg(to_fill, param, index);
            break;
        case DIRECT:
            get_direct_arg(to_fill, param, index);
            break;
    }
}

int *continue_getting_parameter_hexa(instruction_t *head,
    instruction_t *curr_i, param_t *params, int len)
{
    int *to_return = NULL;
    int index = 1;

    to_return = malloc(sizeof(int) * (len + 1));
    if (to_return == NULL)
        return (NULL);
    to_return[0] = len;
    for (int i = 0; my_strcmp(params[i].param, "") != 0; i++) {
        fill_var_according_to_params(to_return, params[i], &index);
        if (to_return[index - 1] == -1) {
            change_label_values_according_to_type(get_label_values(head,
                curr_i, params[i]), curr_i, &to_return, index);
        }
    }
    return to_return;
}

int *get_parameter_hexa(instruction_t *head, instruction_t *curr_i,
    int nbr_params, ...)
{
    param_t *params = malloc(sizeof(param_t) * (nbr_params + 1));
    int len = 0;
    va_list list;

    if (params == NULL)
        return NULL;
    va_start(list, nbr_params);
    for (int i = 0; i < nbr_params; i++)
        params[i] = va_arg(list, param_t);
    va_end(list);
    params[nbr_params] = (param_t) {"", REGISTER};
    for (int i = 0; my_strcmp(params[i].param, "") != 0; i++)
        len += get_size_according_to_param_type(params[i]);
    return (continue_getting_parameter_hexa(head, curr_i, params, len));
}

int *get_param_according_to_nbr(instruction_t *head, instruction_t *i)
{
    switch (i->nb_params) {
        case 1:
            return get_parameter_hexa(head, i, 1, i->params[0]);
        case 2:
            return get_parameter_hexa(head, i, 2, i->params[0], i->params[1]);
        case 3:
            return get_parameter_hexa(head, i, 3, i->params[0], i->params[1],
                i->params[2]);
    }
    return (NULL);
}