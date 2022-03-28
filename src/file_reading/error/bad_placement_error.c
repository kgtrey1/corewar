/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check if comment and name are in their place
*/

#include "my.h"
#include "asm.h"

char there_is_bad_placement(char **tab)
{
    int name_index = -84;
    int comment_index = -84;

    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        if (name_index == -84 && starting_with(".name ", tab[i]))
            name_index = i;
        if (comment_index == -84 && starting_with(".comment ", tab[i]))
            comment_index = i;
        if (comment_index != -84 && name_index != -84)
            break;
    }
    if (name_index != 0){
        write(2, "The name of your program must be the first line.\n", 49);
        return (TRUE);
    }
    if (name_index + 1 != comment_index){
        write(2, "The comment must be just after the name.\n", 41);
        return (TRUE);
    }
    return (FALSE);
}
