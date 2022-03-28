/*
** EPITECH PROJECT, 2019
** instr_list_two.c
** File description:
** This is the second file that handles instruction linked lists
*/

#include "asm.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void clear_instruction_list(instruction_t *head)
{
    instruction_t *i, *next;

    for (i = head->next; i != head; i = next) {
        next = i->next;
        free(i);
    }
}

void delete_instruction_list(instruction_t **liste)
{
    clear_instruction_list(*liste);
    free(*liste);
    *liste = NULL;
}

void print_all_instructions(instruction_t *head)
{
    instruction_t *i;
    int index = 0;

    for (i = head->next; i != head; i = i->next) {
        my_printf("Instruction: %s\n", i->type);
        index++;
    }
}