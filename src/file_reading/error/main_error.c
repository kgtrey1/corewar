/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Call all error functions
*/

#include "my.h"
#include "asm.h"

char *parse_new_buffer(char **tab, int counter)
{
    char *new_buffer = NULL;
    int new_buffer_index = 0;

    new_buffer = malloc(sizeof(char) * counter + 1);
    new_buffer[counter] = '\0';
    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        for (int j = 0; j < my_strlen(tab[i]); j++){
            new_buffer[new_buffer_index] = tab[i][j];
            new_buffer_index++;
        }
        new_buffer[new_buffer_index] = '\n';
        new_buffer_index++;
    }
    new_buffer = my_strdup(delete_multiple_space(new_buffer));
    new_buffer = my_strdup(delete_empty_lines(new_buffer));
    return (new_buffer);
}

char *comma_to_space(char **tab)
{
    char is_in_double_quote = FALSE;
    int counter = 0;

    for (int i = 0; my_strlen(tab[i]) != 0; i++){
        counter++;
        for (int j = 0; j < my_strlen(tab[i]); j++){
            counter++;
            if (tab[i][j] == '"')
                is_in_double_quote = !is_in_double_quote;
            if (tab[i][j] == ',' && !is_in_double_quote)
                tab[i][j] = ' ';
        }
    }
    return (parse_new_buffer(tab, counter));
}

char **there_is_an_error(int ac, char **av)
{
    char **tab = NULL;
    char **new_tab = NULL;

    if (there_is_bad_number_of_args(ac))
        return (NULL);
    tab = there_is_bad_file(av[1]);
    if (tab == NULL)
        return (NULL);
    if (there_is_bad_comment(tab))
        return (NULL);
    if (there_is_bad_name(tab))
        return (NULL);
    if (there_is_bad_placement(tab))
        return (NULL);
    if (there_is_name_or_comment_bad_length(tab))
        return (NULL);
    if (there_is_bad_instruction(tab))
        return (NULL);
    new_tab = convert_buffer_to_tab(comma_to_space(tab));
    return (new_tab);
}
