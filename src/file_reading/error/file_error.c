/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check if file exist and is not empty
*/

#include "my.h"
#include "asm.h"

char **there_is_bad_file(char *path)
{
    char **tab = NULL;
    char *buffer = parse_file(path);

    if (buffer == NULL)
        return (NULL);
    buffer = clean_my_buffer(buffer);
    if (buffer == NULL)
        return (NULL);
    tab = convert_buffer_to_tab(buffer);
    return (tab);
}
