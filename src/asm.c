/*
** EPITECH PROJECT, 2020
** asm.c
** File description:
** This file handles the start of the bytecode part
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_id_by_name(char *name)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, name) == 0)
            return op_tab[i].code;
    }
    return (-1);
}

void for_each_instruction(instruction_t *head, instruction_t *i, int fd)
{
    int id = get_id_by_name(i->type);
    int param_types = get_param_type_according_to_nbr(i);
    int *parameters = get_param_according_to_nbr(head, i);
    int *value = NULL;

    my_write_int_to_file_in_hex(id, fd);
    if (id == ZJMP || id == FORK || id == LFORK) {
        value = get_int_to_hex_info(parameters[parameters[0]], 2);
        for (int i = 1; i < 3; i++)
            my_write_int_to_file_in_hex(value[i], fd);
    } else if (id == LIVE) {
        value = get_int_to_hex_info(parameters[parameters[0]], 4);
        for (int i = 1; i < parameters[0] + 1; i++)
            my_write_int_to_file_in_hex(value[i], fd);
    } else {
        my_write_int_to_file_in_hex(param_types, fd);
        for (int i = 1; i < parameters[0] + 1; i++)
            my_write_int_to_file_in_hex(parameters[i], fd);
    }
}

void start_bytecode(instruction_t *instructions, char *name,
    char *description, char *file_name)
{
    int fd = open(concat(file_name, ".cor"), O_CREAT | O_WRONLY, 0644);
    instruction_t *i = NULL;

    write_name(name, fd);
    write_instr_info(instructions, fd);
    write_desc(description, fd);
    for (i = instructions; i != NULL; i = i->next) {
        for_each_instruction(instructions, i, fd);
    }
    close(fd);
}