/*
** EPITECH PROJECT, 2020
** empty_line_clean.c
** File description:
** Delete all empty lines
*/

#include "my.h"
#include "asm.h"

char *delete_empty_lines(char *buffer)
{
    char there_are_empty_line = FALSE;
    int empty_line_index = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if ((buffer[i] == '\n' && i == 0) ||
        (buffer[i] == '\n' && buffer[i + 1] == '\n')){
            there_are_empty_line = TRUE;
            empty_line_index = i;
            break;
        }
    }
    if (there_are_empty_line){
        buffer = delete_this_char(buffer, empty_line_index);
        delete_empty_lines(buffer);
    }
    else
        return (buffer);
}
