/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** This is the file that contains the main function for the project
*/

#include "asm.h"
#include "my.h"

int main(int ac, char **av)
{
    char **tab = there_is_an_error(ac, av);
    int len = 0;
    instruction_t *linked_list = NULL;

    if (tab == NULL)
        return (EXIT_ERROR);
    for (; my_strlen(tab[len]) != 0; len++);
    if (len != 2) {
        if ((linked_list = parse_all_instructions(tab)) == NULL)
            return (EXIT_ERROR);
        if (check_if_labels_are_known(linked_list) == EXIT_ERROR) {
            my_perror("Undefined label.\n");
            return (EXIT_ERROR);
        }
        while (linked_list->prev != NULL)
            linked_list = linked_list->prev;
    }
    start_bytecode(linked_list, send_name(tab[0]),
    send_comment(tab[1]), send_file_name_follow_up(av[1]));
    return (EXIT_SUCCESS);
}