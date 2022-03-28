/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check length of comments and names
*/

#include "my.h"
#include "asm.h"

char there_is_name_or_comment_bad_length(char **tab)
{
    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        if (starting_with(".comment ", tab[i])){
            if (my_strlen(tab[i]) > COMMENT_LENGTH + 11){
                write(2, "The comment is too long.\n", 25);
                return (TRUE);
            }
        }
        if (starting_with(".name ", tab[i])){
            if (my_strlen(tab[i]) > PROG_NAME_LENGTH + 8){
                write(2, "The name is too long.\n", 22);
                return (TRUE);
            }
        }
    }
    return (FALSE);
}
