/*
** EPITECH PROJECT, 2020
** my_write_hex_to_file.c
** File description:
** This is file writes hex to a given file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_write_str_to_file_in_hex(char *str, int fd)
{
    int len_name = my_strlen(str);
    unsigned char to_write;

    for (int i = 0; i < len_name; i++) {
        to_write = (int) str[i];
        write(fd, &to_write, sizeof(to_write));
    }
}

void my_write_int_to_file_in_hex(int a, int fd)
{
    unsigned char to_write;

    to_write = (int) a;
    write(fd, &to_write, sizeof(to_write));
}