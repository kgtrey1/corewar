/*
** EPITECH PROJECT, 2020
** UTILS
** File description:
** Check if it start with the same string
*/

#include "my.h"
#include "asm.h"

char starting_with(char const *start, char const *full_str)
{
    int size_full_str = my_strlen(full_str);
    int size_start = my_strlen(start);

    if (size_start > size_full_str)
        return (FALSE);
    for (int i = 0; i < size_start; i++){
        if (full_str[i] != start[i])
            return (FALSE);
    }
    return (TRUE);
}
