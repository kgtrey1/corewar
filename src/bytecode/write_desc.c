/*
** EPITECH PROJECT, 2020
** write_desc.c
** File description:
** This file writes the desc of the prorgramm to the file
*/

#include "asm.h"
#include "my.h"

void write_desc(char *description, int fd)
{
    int len_desc = my_strlen(description);
    int nb_zeros_after_desc = (COMMENT_LENGTH - len_desc) + 4;

    my_write_str_to_file_in_hex(description, fd);
    for (int i = 0; i < nb_zeros_after_desc; i++)
        my_write_int_to_file_in_hex(00, fd);
}