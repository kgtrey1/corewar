/*
** EPITECH PROJECT, 2020
** UTILS
** File description:
** Edit all tabulation to space (if is not in double quote)
*/

#include "my.h"
#include "asm.h"

void tab_to_space(char *buffer)
{
    char is_in_double_quote = FALSE;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (buffer[i] == '\t' && !is_in_double_quote)
            buffer[i] = ' ';
    }
}
