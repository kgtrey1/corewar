/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Helpers for string parsing.
*/

#include "asm.h"
#include "my.h"

char **add_label_to_list(instruction_t *list, char *label)
{
    int size = 0;
    char **new_list = NULL;

    for (int i = 0; label[i+1]; i++) {
        if (!is_lower(label[i]) && !is_num(label[i]) && label[i] != '_') {
            my_perror("Invalid label name.\n");
            exit(84);
        }
    }
    for (; list->known_labels && list->known_labels[size]; size++);
    new_list = malloc(sizeof(char *) * (size + 2));
    for (size = 0; list->known_labels && list->known_labels[size]; size++)
        new_list[size] = my_strdup(list->known_labels[size]);
    new_list[size] = my_strdup(label);
    new_list[size + 1] = NULL;
    return (new_list);
}

char **get_new_label(instruction_t *list, char *label)
{
    if (list && label) {
        for (int i = 0; list->known_labels && list->known_labels[i]; i++) {
            (my_strcmp(list->known_labels[i], label) == 0) ?
            my_perror("Multiple definition of the same label\n"), exit(84) : 0;
        }
        return (add_label_to_list(list, label));
    }
    if (!list && label) {
        return (add_label_to_list(list, label));
    }
    if (!list)
        return (NULL);
    return (list->known_labels);
}

int is_lower(char c)
{
    if (c >= 97 && c <= 122)
        return (1);
    else
        return (0);
}

int is_num(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    else
        return (0);
}