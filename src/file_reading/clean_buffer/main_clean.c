/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Call all clean functions
*/

#include "my.h"
#include "asm.h"

char *add_line_return_at_end(char *buffer)
{
    int size_new_buffer = my_strlen(buffer) + 1;
    char *new_buffer = NULL;

    new_buffer = malloc(sizeof(char) * size_new_buffer + 1);
    new_buffer[size_new_buffer] = '\0';
    for (int i = 0; i < my_strlen(buffer); i++)
        new_buffer[i] = buffer[i];
    new_buffer[size_new_buffer - 1] = '\n';
    free(buffer);
    return (new_buffer);
}

void instruction_after_label(char *buffer)
{
    char there_is_space = FALSE;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n')
            there_is_space = FALSE;
        if (buffer[i] == ' ')
            there_is_space = TRUE;
        if (there_is_space == FALSE && buffer[i] == ':'
        && buffer[i + 1] == '\n')
            buffer[i + 1] = ' ';
    }
}

char *clean_my_buffer(char *buffer)
{
    tab_to_space(buffer);
    buffer = my_strdup(delete_multiple_space(buffer));
    buffer = my_strdup(delete_comments(buffer));
    buffer = my_strdup(delete_empty_lines(buffer));
    buffer = my_strdup(delete_comma_before_points(buffer));
    if (buffer[my_strlen(buffer) - 1] != '\n')
        buffer = my_strdup(add_line_return_at_end(buffer));
    instruction_after_label(buffer);
    return (buffer);
}
