/*
** EPITECH PROJECT, 2020
** CoreWar
** File description:
** This file checks if labels in instructions are defined
*/

#include "asm.h"
#include "my.h"

int is_in_label_list(char *label, char **known_labels)
{
    for (int i = 0; known_labels && known_labels[i] != NULL; i++) {
        if (labelcmp(known_labels[i], label))
            return (1);
    }
    return (0);
}

int check_if_label_is_known(instruction_t *i, char **known_labels)
{
    for (int j = 0; j < i->nb_params; j++) {
        if (my_str_starts_with(i->params[j].param, "%:") &&
            !is_in_label_list(i->params[j].param, known_labels)) {
            return (EXIT_ERROR);
        }
    }
    return (EXIT_SUCCESS);
}

int check_if_labels_are_known(instruction_t *instr)
{
    char **known_labels = instr->known_labels;
    instruction_t *i = instr;

    for (; i != NULL; i = i->prev) {
        if (check_if_label_is_known(i, known_labels) == EXIT_ERROR)
            return (EXIT_ERROR);
    }
    return (EXIT_SUCCESS);
}