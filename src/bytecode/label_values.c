/*
** EPITECH PROJECT, 2020
** label_values.c
** File description:
** This is a file gives you the parameters in hex value
*/

#include "my.h"
#include "asm.h"

int *get_label_value_after(instruction_t *head, instruction_t *curr_i,
    param_t param)
{
    int value = 0;
    char *to_find = my_cut_string(param.param, 2, my_strlen(param.param));
    instruction_t *i = curr_i;

    for (i = curr_i; i != NULL; i = i->next) {
        if (i->label.is_instr_label == 1 &&
        my_strcmp(my_cut_string(i->label.name, 0, my_strlen(i->label.name) - 2)
        , to_find) == 0) {
            return get_int_to_hex_info(value, 2);
        }
        value += get_instruction_byte_size(i);
    }
    return (NULL);
}

int *get_label_value_before(instruction_t *head, instruction_t *curr_i,
    param_t param)
{
    int value = 0;
    int found = 0;
    char *to_find = my_cut_string(param.param, 2, my_strlen(param.param));
    instruction_t *i;

    for (i = head; i != curr_i->next; i = i->next) {
        if (found == 1)
            value += get_instruction_byte_size(i);
        if (i->label.is_instr_label == 1 &&
        my_strcmp(my_cut_string(i->label.name, 0, my_strlen(i->label.name) - 2)
        , to_find) == 0) {
            found = 1;
        }
    }
    value++;
    return get_int_to_hex_info((256 * 255) - (value + 2), 2);
}

int *get_label_values(instruction_t *head, instruction_t *curr_i,
    param_t param)
{
    int *to_return = get_label_value_after(head, curr_i, param);

    if (to_return != NULL)
        return (to_return);
    else
        to_return = get_label_value_before(head, curr_i, param);
    return (to_return);
}

void change_label_values_according_to_type(int *label_vals,
    instruction_t *curr_i, int **to_return, int index)
{
    int id = get_id_by_name(curr_i->type);

    if (id == ZJMP || id == FORK || id == LFORK || id == LIVE)
        to_return[0][index - 1] = (label_vals[1] * 255) + label_vals[2];
    else {
        to_return[0][index - 1] = label_vals[2];
        to_return[0][index - 2] = label_vals[1];
    }
}