/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Verification on parameters.
*/

#include "asm.h"
#include "my.h"

int type(param_t param, int dir, int ind, int reg)
{
    if (param.type == DIRECT && dir)
        return (TRUE);
    if (param.type == INDIRECT && ind)
        return (TRUE);
    if (param.type == REGISTER && reg)
        return (TRUE);
    return (FALSE);
}

instruction_t *verify_parameters_four(instruction_t *ins)
{
    if (my_strcmp(ins->type, "lld") == 0) {
        if (ins->nb_params == 2 && type(ins->params[0], 1, 1, 0) &&
        type(ins->params[1], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "lldi") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 1, 1, 1) &&
        type(ins->params[1], 1, 0, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "lfork") == 0) {
        if (ins->nb_params == 1 && type(ins->params[0], 1, 0, 0))
            return (ins);
    }
    if (my_strcmp(ins->type, "aff") == 0) {
        if (ins->nb_params == 1 && type(ins->params[0], 0, 0, 1))
            return (ins);
    }
    my_perror("The argument given to the instruction is invalid.\n");
    return (NULL);
}

instruction_t *verify_parameters_three(instruction_t *ins)
{
    if (my_strcmp(ins->type, "xor") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 1, 1, 1) &&
        type(ins->params[1], 1, 1, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "ldi") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 1, 1, 1) &&
        type(ins->params[1], 1, 0, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "sti") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 0, 0, 1) &&
        type(ins->params[1], 1, 1, 1) && type(ins->params[2], 1, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "fork") == 0) {
        if (ins->nb_params == 1 && type(ins->params[0], 1, 0, 0))
            return (ins);
    }
    return (verify_parameters_four(ins));
}

instruction_t *verify_parameters_two(instruction_t *ins)
{
    if (my_strcmp(ins->type, "sub") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 0, 0, 1) &&
        type(ins->params[1], 0, 0, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "and") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 1, 1, 1) &&
        type(ins->params[1], 1, 1, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "or") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 1, 1, 1) &&
        type(ins->params[1], 1, 1, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "zjmp") == 0) {
        if (ins->nb_params == 1 && type(ins->params[0], 1, 0, 0))
            return (ins);
    }
    return (verify_parameters_three(ins));
}

instruction_t *verify_parameters(instruction_t *ins)
{
    if (my_strcmp(ins->type, "live") == 0) {
        if (ins->nb_params == 1 && type(ins->params[0], 1, 0, 0))
            return (ins);
    }
    if (my_strcmp(ins->type, "ld") == 0) {
        if (ins->nb_params == 2 && type(ins->params[0], 1, 1, 0) &&
        type(ins->params[1], 0, 0, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "st") == 0) {
        if (ins->nb_params == 2 && type(ins->params[0], 0, 0, 1) &&
        type(ins->params[1], 0, 1, 1))
            return (ins);
    }
    if (my_strcmp(ins->type, "add") == 0) {
        if (ins->nb_params == 3 && type(ins->params[0], 0, 0, 1) &&
        type(ins->params[1], 0, 0, 1) && type(ins->params[2], 0, 0, 1))
            return (ins);
    }
    return (verify_parameters_two(ins));
}