/*
** EPITECH PROJECT, 2020
** my_write_hex_to_file.c
** File description:
** This is file writes hex to a given file
*/

#include "asm.h"
#include "my.h"

void write_name(char *name, int fd)
{
    int nb_zeros_after_name = (PROG_NAME_LENGTH - my_strlen(name));

    my_write_int_to_file_in_hex(00, fd);
    my_write_int_to_file_in_hex(234, fd);
    my_write_int_to_file_in_hex(131, fd);
    my_write_int_to_file_in_hex(243, fd);
    my_write_str_to_file_in_hex(name, fd);
    for (int i = 0; i < nb_zeros_after_name; i++)
        my_write_int_to_file_in_hex(00, fd);
}