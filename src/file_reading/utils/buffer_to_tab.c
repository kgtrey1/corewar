/*
** EPITECH PROJECT, 2020
** UTILS
** File description:
** Convert simple tab to double tab
*/

#include "my.h"
#include "asm.h"

static void calcul_malloc(int i, int *simple_malloc, char const *buffer)
{
    for (int j = 1; buffer[i + j] != '\0'; j++){
        if (buffer[i + j] == '\n')
            break;
        *simple_malloc += 1;
    }
}

static void fill_tab(char *buffer, char **tab)
{
    int i_index = 0, j_index = 0;
    int simple_malloc = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n'){
            i_index++;
            j_index = 0;
            simple_malloc = 0;
            calcul_malloc(i, &simple_malloc, buffer);
            tab[i_index] = malloc(sizeof(char) * simple_malloc + 1);
            tab[i_index][simple_malloc] = '\0';
            continue;
        }
        tab[i_index][j_index] = buffer[i];
        j_index++;
    }
}

char **convert_buffer_to_tab(char *buffer)
{
    char **tab = NULL;
    int counter = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (i == '\n')
            counter++;
    }
    tab = malloc(sizeof(char *) * (counter + 1));
    tab[counter] = NULL;
    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n'){
            tab[0] = malloc(sizeof(char) * (i + 1) + 1);
            tab[0][i + 1] = '\0';
        }
    }
    fill_tab(buffer, tab);
    return (tab);
}
