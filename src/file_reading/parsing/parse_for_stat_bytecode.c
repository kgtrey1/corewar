/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Parse file name, comment and name
*/

#include "my.h"
#include "asm.h"

char *send_name(char const *str)
{
    char *name = NULL;
    int size = my_strlen(str) - 8;
    int counter = 0;

    if (my_strlen(str) == 8){
        name = malloc(sizeof(char) * 1);
        name[0] = '\0';
        return (name);
    }
    name = malloc(sizeof(char) * size + 1);
    name[size] = '\0';
    for (int i = 7; i < my_strlen(str) - 1; i++){
        name[counter] = str[i];
        counter++;
    }
    return (name);
}

char *send_comment(char const *str)
{
    char *comment = NULL;
    int size = my_strlen(str) - 11;
    int counter = 0;

    if (my_strlen(str) == 11){
        comment = malloc(sizeof(char) * 1);
        comment[0] = '\0';
        return (comment);
    }
    comment = malloc(sizeof(char) * size + 1);
    comment[size] = '\0';
    for (int i = 10; i < my_strlen(str) - 1; i++){
        comment[counter] = str[i];
        counter++;
    }
    return (comment);
}

char *send_file_name(char *str)
{
    char *file_name = NULL;
    int size = my_strlen(str);

    if (size < 2)
        return (str);
    if (!(str[size - 1] == 's' && str[size - 2] == '.'))
        return (str);
    file_name = malloc(sizeof(char) * (size - 2) + 1);
    file_name[size - 2] = '\0';
    for (int i = 0; i < size - 2; i++)
        file_name[i] = str[i];
    return (file_name);
}

char *send_file_name_follow_up(char *str)
{
    if (my_get_index_char(str, '/', 1) != -1) {
        return (send_file_name(my_cut_string(str, my_get_index_char(str, '/',
            my_count_char(str, '/')) + 1, my_strlen(str) - 1)));
    } else {
        return send_file_name(str);
    }
    return (NULL);
}