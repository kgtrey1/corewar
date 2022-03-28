/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Parse file and check errors with parsing (empty file or not existing file)
*/

#include "my.h"
#include "asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *parse_file(char *path)
{
    char *buffer = NULL;
    int fd = 0;

    if (open(path, O_RDONLY) == -1){
        write(2, "Error in function open: No such file or directory.\n", 51);
        return (NULL);
    }
    if (close(fd) == -1){
        write(2, "Error in function close.\n", 25);
        return (NULL);
    }
    buffer = my_buffer(path, 1, '\0');
    if (buffer == NULL || my_strlen(buffer) == 0){
        write(2, "asm, ", 5);
        write(2, path, my_strlen(path));
        write(2, ": This file is empty.\n", 22);
        return (NULL);
    }
    return (buffer);
}
