/*
** EPITECH PROJECT, 2019
** asm
** File description:
** parsing_arguments.c
*/

#include "asm.h"
#include "my.h"

char *fill_label(char *tab)
{
    char *label;
    int len = 0;
    int y = 0;

    for (int i = 0; tab[i] != ':'; i++)
        len++;
    label = malloc(sizeof(char) * len + 1);
    for (int i = 0; tab[i] != ':'; i++) {
        label[y] = tab[i];
        y++;
    }
    label[y + 1] = '\0';
    return (label);
}

instruction_t *fill_tab_instruction(instruction_t *instruct, char *tab,
    char **args, char *label)
{
    int col = 0, row = 0, i = 0;

    if (label != NULL)
        for (; tab[i - 1] != ':'; i++);
    if (tab[i] == ' ')
        i++;
    for (; tab[i] != '\0'; i++) {
        if (tab[i] == ' ') {
            col = 0;
            row++;
            continue;
        }
        args[row][col] = tab[i];
        col++;
    }
    instruct = add_instruct(instruct, args, label);
    return (instruct);
}

instruction_t *parse_my_instruction(instruction_t *instruct, char *tab)
{
    char **args = NULL;
    char *label = NULL;

    if ((args = is_label(tab, &label)) != NULL)
        return (add_instruct(instruct, args, label));
    args = my_str_to_word_array(tab);
    return (fill_tab_instruction(instruct, tab, args, NULL));
}

instruction_t *parse_all_instructions(char **tab)
{
    instruction_t *linked_list = NULL;

    for (int i = 2; my_strlen(tab[i]) != 0; i++) {
        linked_list = parse_my_instruction(linked_list, tab[i]);
        if (linked_list == NULL)
            return (NULL);
    }
    return (linked_list);
}