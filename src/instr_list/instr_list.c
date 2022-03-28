/*
** EPITECH PROJECT, 2019
** instruction_list.c
** File description:
** This make a linked list with all the instructions
*/

#include "my.h"
#include "asm.h"
#include <unistd.h>
#include <stdlib.h>

instruction_t *create_instruction_list(void)
{
    instruction_t *head = malloc(sizeof(instruction_t));
    head->prev = head;
    head->next = head;
    return head;
}

void delete_instruction(instruction_t *element)
{
    element->prev->next = element->next;
    element->next->prev = element->prev;
    free(element);
}

void add_instruction(instruction_t *element, instr_holder_t holder,
    label_t label, param_t *params)
{
    instruction_t *new_element = NULL;

    new_element = malloc(sizeof(instruction_t));
    new_element->type = holder.type;
    new_element->nb_params = holder.nb_params;
    new_element->params = params;
    new_element->label = label;
    new_element->prev = element->prev;
    new_element->next = element;
    element->prev->next = new_element;
    element->prev = new_element;
}