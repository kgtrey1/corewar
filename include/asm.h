/*
** EPITECH PROJECT, 2020
** project.h
** File description:
** Header for my current project
*/

#ifndef ASM_H
#define ASM_H

#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum parameter_types {REGISTER, DIRECT, INDIRECT, INVALID};

enum instr_types {
    LIVE = 1,
    LD = 2,
    ST = 3,
    ADD = 4,
    SUB = 5,
    AND = 6,
    OR = 7,
    XOR = 8,
    ZJMP = 9,
    LDI = 10,
    STI = 11,
    FORK = 12,
    LLD = 13,
    LLDI = 14,
    LFORK = 15,
    AFF = 16
};

typedef struct param {
    char *param;
    enum parameter_types type;
} param_t;

typedef struct label {
    char *name;
    int is_instr_label;
} label_t;

typedef struct instr_holder {
    char *type;
    int nb_params;
} instr_holder_t;

typedef struct instruction {
    char *type;
    int nb_params;
    char **known_labels;
    struct label label;
    struct param *params;
    struct instruction *next;
    struct instruction *prev;
} instruction_t;

/* MACRO */

#define FALSE   0
#define TRUE    1
#define EXIT_ERROR 84

int start_asm(int ac, char **av);

/* Instruction Parameters */
int get_parameter_types_hexa(int nbr_params, ...);
int *get_param_according_to_nbr(instruction_t *head, instruction_t *i);
int get_param_type_according_to_nbr(instruction_t *i);

int *get_parameter_hexa(instruction_t *head, instruction_t *curr_i,
    int nbr_params, ...);
int *continue_getting_parameter_hexa(instruction_t *head, instruction_t *curr_i,
    param_t *params, int len);
void get_register_arg(int *to_fill, param_t param, int *index);
void get_indirect_arg(int *to_fill, param_t param,
    int *index);
void get_direct_arg(int *to_fill, param_t param,
    int *index);
int *get_label_values(instruction_t *head, instruction_t *curr_i,
    param_t param);
void change_label_values_according_to_type(int *label_vals,
    instruction_t *curr_i, int **to_return, int index);

/* Instruction Linked Lists */
instruction_t *create_instruction_list(void);
void delete_instruction(instruction_t *element);
void add_instruction(instruction_t *element, instr_holder_t holder,
    label_t label, param_t *params);
void clear_instruction_list(instruction_t *head);
void delete_instruction_list(instruction_t **liste);
void print_all_instructions(instruction_t *head);

/* Instruction Handling */
void start_bytecode(instruction_t *instructions, char *name,
    char *description, char *file_name);
void for_each_instruction(instruction_t *head, instruction_t *i, int fd);

/* Utils */
void my_write_str_to_file_in_hex(char *str, int fd);
void my_write_int_to_file_in_hex(int a, int fd);
void write_name(char *name, int fd);
void write_desc(char *description, int fd);
void write_instr_info(instruction_t *i, int fd);
int *get_int_to_hex_info(int value, int len);
int get_id_by_name(char *name);
int get_instruction_byte_size(instruction_t *instr);
int get_instructions_size(instruction_t *head);
int check_if_labels_are_known(instruction_t *instr);

/* File reading */
    // CLEAN
    char *clean_my_buffer(char *buffer);
    char *delete_multiple_space(char *buffer);
    char *delete_empty_lines(char *buffer);
    char *delete_comments(char *buffer);
    char *delete_comma_before_points(char *buffer);
    // ERRORS
    char **there_is_an_error(int ac, char **av);
    char there_is_bad_number_of_args(int ac);
    char **there_is_bad_file(char *path);
    char there_is_bad_comment(char **tab);
    char there_is_bad_name(char **tab);
    char there_is_bad_placement(char **tab);
    char there_is_name_or_comment_bad_length(char **tab);
    char there_is_bad_instruction(char **tab);
    // PARSING
    char *parse_file(char *path);
    char *send_name(char const *str);
    char *send_file_name(char *str);
    char *send_file_name_follow_up(char *str);
    char *send_comment(char const *str);
    // UTILS
    char **convert_buffer_to_tab(char *buffer);
    char *delete_this_char(char *buffer, int line_index);
    void tab_to_space(char *buffer);
    char starting_with(char const *start, char const *full_str);

/* String parsing helpers -> char_booleans.c */
int is_lower(char c);
int is_num(char c);
char **get_new_label(instruction_t *list, char *label);
char **add_label_to_list(instruction_t *list, char *label);

/* Utils for error handling and type detection -> params_utils.c */
int labelcmp(char *s1, char *s2);
int is_valid_label_name(char *param, char **label_list);
int is_indirect(char *param, char **label_list);
int is_direct(char *param, char **label_list);
int is_register(char *param);

/* Parameters formating -> parameters.c */
int get_parameter_type(char *param, char **label_list);
int valid_param_amount(int amount, int i);
param_t *fill_parameters(char **list, int size, char **label_list);
char *get_instruction_type(char **list, int *nb);
instruction_t *add_instruct(instruction_t *prev, char **list, char *label);

/* Verification on instructions */
int type(param_t param, int dir, int ind, int reg);
instruction_t *verify_parameters_four(instruction_t *ins);
instruction_t *verify_parameters_three(instruction_t *ins);
instruction_t *verify_parameters_two(instruction_t *ins);
instruction_t *verify_parameters(instruction_t *ins);

/* Arguments parsing -> parsing_arguments.c */
instruction_t *parse_all_instructions(char **tab);
char *fill_label(char *tab);
char **is_label(char *tab, char **label);

/* Split parts on parameters -> split_parts.c */
char *check_label(char *tab, char *label);
int check_space(char *tab);

#endif
