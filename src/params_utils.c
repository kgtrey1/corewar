/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** Error handling and type detections.
*/

#include "asm.h"
#include "my.h"

int labelcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 2;

    while (s1[i] && s2[j]) {
        if (s1[i] != s2[j])
            return (0);
        i++;
        j++;
    }
    if (s1[i+1] == '\0' && s2[j] == '\0')
        return (1);
    return (0);
}

int is_valid_label_name(char *param, char **label_list)
{
    int is_valid = 1;

    for (int i = 2; is_valid && param[i]; i++) {
        if (!is_lower(param[i]) && !is_num(param[i]) && param[i] != '_') {
            my_perror("Invalid label name.\n");
            return (84);
        }
    }
    return (1);
}

int is_indirect(char *param, char **label_list)
{
    if (param[0] == '%')
        return (0);
    if (!my_str_isnum(param)) {
        my_perror("The argument given to the instruction is invalid.\n");
        return (84);
    }
    return (1);
}

int is_direct(char *param, char **label_list)
{
    if (param[0] != '%')
        return (0);
    if (param[1] == ':') {
        if (is_valid_label_name(param, label_list))
            return (1);
        else
            return (84);
    }
    for (int i = 1; param[i]; i++) {
        if (!is_num(param[i])) {
            my_perror("The argument given to the instruction is invalid.\n");
            return (84);
        }
    }
    return (1);
}

int is_register(char *param)
{
    char *valid_register[] = {"r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8",
    "r9", "r10", "r11", "r12", "r13", "r14", "r15", "r16", NULL};

    if (param[0] != 'r')
        return (0);
    for (int i = 0; valid_register[i]; i++) {
        if (my_strcmp(valid_register[i], param) == 0)
            return (1);
    }
    my_perror("Invalid register number\n");
    return (84);
}