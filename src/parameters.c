/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Instructions formaters.
*/

#include "asm.h"
#include "my.h"

int get_parameter_type(char *param, char **label_list)
{
    int retval = 0;

    retval = is_register(param);
    if (retval != 0)
        return ((retval == 1) ? REGISTER : INVALID);
    retval = is_indirect(param, label_list);
    if (retval != 0)
        return ((retval == 1) ? INDIRECT : INVALID);
    retval = is_direct(param, label_list);
    if (retval != 0)
        return ((retval == 1) ? DIRECT : INVALID);
    return (INVALID);
}

int valid_param_amount(int amount, int i)
{
    int p_size[] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};

    if (amount > p_size[i]) {
        my_perror("Too many arguments given to the instruction.\n");
        return (FALSE);
    }
    else if (amount < p_size[i]) {
        my_perror("Too few arguments given to the instruction.\n");
        return (FALSE);
    }
    return (TRUE);
}

param_t *fill_parameters(char **list, int size, char **label_list)
{
    param_t *params = NULL;
    int p_type = 0;

    if (size <= 0)
        return (NULL);
    params = malloc(sizeof(param_t) * (size));
    if (params == NULL) {
        my_perror("Error: Couldn't allocate memory\n");
        return (NULL);
    }
    for (int i = 0; list[i+1]; i++) {
        p_type = get_parameter_type(list[i+1], label_list);
        if (p_type == INVALID)
            return (NULL);
        else
            params[i] = (param_t){my_strdup(list[i+1]), p_type};
    }
    return (params);
}

char *get_instruction_type(char **list, int *nb)
{
    char *type_list[] = {"live", "ld", "st",
    "add", "sub", "and", "or",
    "xor", "zjmp", "ldi", "sti",
    "fork", "lld", "lldi", "lfork", "aff", NULL};

    for (*nb = 0; list[*nb + 1]; *nb = *nb + 1);
    for (int i = 0; type_list[i]; i++) {
        if (my_strcmp(list[0], type_list[i]) == 0)
            return (valid_param_amount(*nb, i) ? my_strdup(list[0]) : NULL);
    }
    my_perror("Invalid instruction.\n");
    return (NULL);
}

instruction_t *add_instruct(instruction_t *prev, char **list, char *label)
{
    instruction_t *node = malloc(sizeof(instruction_t));

    (node == NULL) ?
    my_perror("Error: Couldn't allocate memory\n"), exit(84) : 0;
    node->known_labels = get_new_label(prev, label);
    node->label = (label == NULL) ? (label_t){NULL, 0} :
    (label_t){my_strdup(label), 1};
    node->type = get_instruction_type(list, &node->nb_params);
    if (node->type == NULL)
        return (NULL);
    node->params = fill_parameters(list, node->nb_params, node->known_labels);
    if (!node->params)
        return (NULL);
    if (!prev)
        node->prev = node->next = NULL;
    else {
        node->prev = prev;
        prev->next = node;
    }
    return (verify_parameters(node));
}