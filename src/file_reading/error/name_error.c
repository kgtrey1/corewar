/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check if comment exist and is valid
*/

#include "my.h"
#include "asm.h"

static char is_invalid_name(char const *str)
{
    int size = my_strlen(str);
    int name_len = my_strlen(".name ");
    int double_quote = 0;

    if (str[name_len] != '"' || str[size - 1] != '"')
        return (TRUE);
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '"')
            double_quote++;
    }
    if (double_quote != 2)
        return (TRUE);
    return (FALSE);
}

static char there_is_bad_number_of_name(int number_of_name)
{
    if (number_of_name == 0){
        write(2, "Warning: No name specified.\n", 28);
        return (TRUE);
    }
    if (number_of_name > 1){
        write(2, "The name can only be defined once.\n", 35);
        return (TRUE);
    }
    return (FALSE);
}

char there_is_bad_name(char **tab)
{
    int number_of_name = 0;

    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        if (my_strlen(tab[i]) == 5 && starting_with(".name", tab[i])){
            write(2, "No name specified.\n", 19);
            return (TRUE);
        }
        if (starting_with(".name ", tab[i])){
            if (is_invalid_name(tab[i])){
                write(2, "Syntax error.\n", 14);
                return (TRUE);
            }
            number_of_name++;
        }
    }
    if (there_is_bad_number_of_name(number_of_name))
        return (TRUE);
    return (FALSE);
}
