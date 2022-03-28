/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Check number of args
*/

#include "my.h"
#include "asm.h"

char there_is_bad_number_of_args(int ac)
{
    if (ac > 2){
        write(2, "Error in function open: No such file or directory.\n", 51);
        return (TRUE);
    }
    if (ac == 1){
        write(2, "Usage: ./asm file_name[.s] ....\n", 32);
        return (TRUE);
    }
    return (FALSE);
}
