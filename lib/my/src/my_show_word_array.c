/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** shows an array of words
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;
    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}