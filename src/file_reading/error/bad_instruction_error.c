/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check if comment exist and is valid
*/

#include "my.h"
#include "asm.h"

static char is_bad_instruction(char const *instruct)
{
    if (starting_with(".name ", instruct)
    || starting_with(".comment ", instruct))
        return (FALSE);
    return (TRUE);
}

char there_is_bad_instruction(char **tab)
{
    int len = 0;

    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        len = my_strlen(tab[i]);
        if ((len < 8 && tab[i][0] == '.')
        || (len >= 8 && tab[i][0] == '.' && is_bad_instruction(tab[i]))){
            write(2, "Invalid instruction.\n", 21);
            return (TRUE);
        }
    }
    return (FALSE);
}
