/*
** EPITECH PROJECT, 2020
** space_clean.c
** File description:
** Clean multiple space not in double quote
*/

#include "my.h"
#include "asm.h"

char *delete_multiple_space(char *buffer)
{
    char there_are_bad_space = FALSE, is_in_double_quote = FALSE;
    int space_index = 0;
    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (!is_in_double_quote &&
        ((buffer[i] == ' ' && buffer[i + 1] == ' ')
        || (buffer[i] == ' ' && buffer[i + 1] == '\n')
        || (i > 0 && buffer[i - 1] == '\n' && buffer[i] == ' '))){
            there_are_bad_space = TRUE;
            space_index = i;
            break;
        }
    }
    if (there_are_bad_space){
        buffer = delete_this_char(buffer, space_index);
        delete_multiple_space(buffer);
    }
    else
        return (buffer);
}
