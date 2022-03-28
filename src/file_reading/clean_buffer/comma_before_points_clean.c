/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Delete and check characters before points
*/

#include "my.h"
#include "asm.h"

static char *delete_this_comma(char *buffer, int line_index, int point_index)
{
    int buffer_size = my_strlen(buffer);
    int new_buffer_index = 0;
    int new_buffer_size = buffer_size - (point_index - line_index - 1);
    char add_one = 1;
    char *new_buffer = malloc(sizeof(char) * new_buffer_size + 1);

    if (line_index == 0)
        add_one = 0;
    new_buffer[new_buffer_size] = '\0';
    for (int i = 0; i < line_index + add_one; i++){
        new_buffer[new_buffer_index] = buffer[i];
        new_buffer_index++;
    }
    for (int i = point_index; buffer[i] != '\0'; i++){
        new_buffer[new_buffer_index] = buffer[i];
        new_buffer_index++;
    }
    free(buffer);
    return (new_buffer);
}


static char there_are_invalid_char_before_point(char *buffer,
int begin, int end)
{
    for (int i = begin + 1; i < end; i++){
        if (buffer[i] != ',' && buffer[i] != ' ')
            return (TRUE);
    }
    return (FALSE);
}

void check_comma(int *line_index, int *point_index,
char *there_is_comma_to_delete, char *buffer)
{
    char is_in_double_quote = FALSE;
    int buffer_size = my_strlen(buffer);

    for (int i = 0; i < buffer_size; i++){
        if (buffer[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (buffer[i] == '\n')
            *line_index = i;
        if (!is_in_double_quote && buffer[i] == '.'
        && ((*line_index != 0 && i != *line_index + 1)
        || (*line_index == 0 && i != 0))){
            if (there_are_invalid_char_before_point(buffer, *line_index, i)){
                write(2, "Syntax error.\n", 14);
                exit (84);
            }
            *point_index = i;
            *there_is_comma_to_delete = TRUE;
            return;
        }
    }
}

char *delete_comma_before_points(char *buffer)
{
    int line_index = 0;
    int point_index = 0;
    char there_is_comma_to_delete = FALSE;

    check_comma(&line_index, &point_index, &there_is_comma_to_delete, buffer);
    if (there_is_comma_to_delete){
        buffer = delete_this_comma(buffer, line_index, point_index);
        delete_comma_before_points(buffer);
    }
    else
        return (buffer);
}
