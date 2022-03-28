/*
** EPITECH PROJECT, 2020
** write_instr_info.c
** File description:
** This is file writes information about the instructions in hex
*/

#include "asm.h"
#include "my.h"

int *get_int_to_hex_info(int value, int len)
{
    int *result = malloc(sizeof(int) * (len + 1));
    float temp = value;

    if (result == NULL)
        return (NULL);
    result[0] = len;
    for (int i = len; i > 0; i--) {
        if (temp > 1.0) {
            result[i] = ((int) temp) % 256;
            temp /= 255;
        } else {
            result[i] = 0;
        }
    }
    return (result);
}

int get_instruction_byte_size(instruction_t *instr)
{
    int id = get_id_by_name(instr->type);
    int nbr_bytes = 2;

    if (id == ZJMP || id == FORK || id == LFORK) {
        return (3);
    } else if (id == LIVE)
        return (5);
    for (int i = 0; i < instr->nb_params; i++) {
        if (instr->params[i].type == REGISTER)
            nbr_bytes++;
        else if (instr->params[i].type == INDIRECT)
            nbr_bytes += IND_SIZE;
        else
            nbr_bytes += DIR_SIZE;
    }
    return (nbr_bytes);
}

int get_instructions_size(instruction_t *head)
{
    int result = 0;
    instruction_t *i = NULL;

    for (i = head; i != NULL; i = i->next) {
        result += get_instruction_byte_size(i);
    }
    return (result);
}

void write_instr_info(instruction_t *head, int fd)
{
    int instr_size = get_instructions_size(head);
    int *instr_info = get_int_to_hex_info(instr_size, 8);

    for (int i = 0; i < instr_info[0]; i++)
        my_write_int_to_file_in_hex(instr_info[i + 1], fd);
}