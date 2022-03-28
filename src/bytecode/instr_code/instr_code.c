/*
** EPITECH PROJECT, 2020
** instr_code.c
** File description:
** This file gives you the instruction code in hexa form
*/

#include "my.h"
#include "op.h"
#include "asm.h"

char *get_instr_code_hexa(int code)
{
    return (my_int_to_hexa(code));
}