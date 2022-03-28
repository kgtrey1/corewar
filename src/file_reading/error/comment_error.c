/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check if comment exist and is valid
*/

#include "my.h"
#include "asm.h"

static char is_invalid_comment(char const *str)
{
    int size = my_strlen(str);
    int comment_len = my_strlen(".comment ");
    int double_quote = 0;

    if (str[comment_len] != '"' || str[size - 1] != '"')
        return (TRUE);
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '"')
            double_quote++;
    }
    if (double_quote != 2)
        return (TRUE);
    return (FALSE);
}

static char there_is_bad_number_of_comments(int number_of_comments)
{
    if (number_of_comments == 0){
        write(2, "Warning: No comment specified.\n", 31);
        return (TRUE);
    }
    if (number_of_comments > 1){
        write(2, "The comment can only be defined once.\n", 38);
        return (TRUE);
    }
    return (FALSE);
}

char there_is_bad_comment(char **tab)
{
    int number_of_comments = 0;

    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        if (my_strlen(tab[i]) == 8 && starting_with(".comment", tab[i])){
            write(2, "No comment specified.\n", 22);
            return (TRUE);
        }
        if (starting_with(".comment ", tab[i])){
            if (is_invalid_comment(tab[i])){
                write(2, "Syntax error.\n", 14);
                return (TRUE);
            }
            number_of_comments++;
        }
    }
    if (there_is_bad_number_of_comments(number_of_comments))
        return (TRUE);
    return (FALSE);
}
