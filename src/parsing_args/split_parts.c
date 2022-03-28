/*
** EPITECH PROJECT, 2019
** asm
** File description:
** split_parts.c
*/

#include "asm.h"
#include "my.h"

char *check_label(char *tab, char *label)
{
    for (int i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == ':') {
            label = fill_label(tab);
        }
    }
    return (label);
}

int check_space(char *tab)
{
    int space = 0;

    for (int i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == ' ')
            space++;
    }
    return (space);
}

char **is_label(char *tab, char **label)
{
    char **words = my_str_to_word_array(tab);
    char **to_return = NULL;
    int nbr_words = 0;

    if (words == NULL)
        return (NULL);
    for (; words[nbr_words] != NULL; nbr_words++);
    if (words[0][my_strlen(words[0]) - 1] == ':') {
        to_return = malloc(sizeof(char *) * (nbr_words));
        to_return[nbr_words - 1] = NULL;
        for (int i = 1; words[i] != NULL; i++) {
            to_return[i - 1] = malloc(sizeof(char) * my_strlen(words[i]));
            to_return[i - 1] = my_strdup(words[i]);
        }
        label[0] = malloc(sizeof(char) * (my_strlen(words[0])));
        label[0] = my_cut_string(words[0], 0, my_strlen(words[0]) - 1);
        return (to_return);
    }
    return (NULL);
}