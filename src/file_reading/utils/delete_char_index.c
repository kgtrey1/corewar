/*
** EPITECH PROJECT, 2020
** UTILS
** File description:
** Delete char in str with his index
*/

#include "my.h"
#include <stdlib.h>

char *delete_this_char(char *buffer, int line_index)
{
    int buff_size = my_strlen(buffer) - 1;
    int actual_index = 0;
    char *new_buffer = malloc(sizeof(char) * buff_size + 1);

    new_buffer[buff_size] = '\0';
    for (int i = 0; i < buff_size + 1; i++){
        if (i != line_index){
            new_buffer[actual_index] = buffer[i];
            actual_index++;
        }
    }
    free(buffer);
    return (new_buffer);
}
