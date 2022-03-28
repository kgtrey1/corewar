##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## This is my makefile
##


RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
WHITE=\033[1;37m
NC=\033[0m

SRC_DIR	=		src

MAIN 	=		$(SRC_DIR)/main.c

SRC	=	$(SRC_DIR)/asm.c													\
		$(SRC_DIR)/op.c														\
		$(SRC_DIR)/file_reading/error/main_error.c							\
		$(SRC_DIR)/file_reading/error/number_of_args_error.c				\
		$(SRC_DIR)/file_reading/error/file_error.c							\
		$(SRC_DIR)/file_reading/error/comment_error.c						\
		$(SRC_DIR)/file_reading/error/name_error.c							\
		$(SRC_DIR)/file_reading/error/bad_placement_error.c					\
		$(SRC_DIR)/file_reading/error/name_comment_length_error.c			\
		$(SRC_DIR)/file_reading/error/bad_instruction_error.c				\
		$(SRC_DIR)/file_reading/utils/delete_char_index.c					\
		$(SRC_DIR)/file_reading/utils/starting_with.c						\
		$(SRC_DIR)/file_reading/utils/buffer_to_tab.c						\
		$(SRC_DIR)/file_reading/utils/tab_to_space.c						\
		$(SRC_DIR)/file_reading/clean_buffer/main_clean.c					\
		$(SRC_DIR)/file_reading/clean_buffer/comments_clean.c				\
		$(SRC_DIR)/file_reading/clean_buffer/space_clean.c					\
		$(SRC_DIR)/file_reading/clean_buffer/empty_line_clean.c				\
		$(SRC_DIR)/file_reading/clean_buffer/comma_before_points_clean.c	\
		$(SRC_DIR)/file_reading/parsing/parse_file.c						\
		$(SRC_DIR)/file_reading/parsing/parse_for_stat_bytecode.c			\
		$(SRC_DIR)/parsing_args/parsing_arguments.c 						\
		$(SRC_DIR)/parsing_args/split_parts.c 								\
		$(SRC_DIR)/instr_list/instr_list.c									\
		$(SRC_DIR)/instr_list/instr_list_two.c								\
		$(SRC_DIR)/bytecode/instr_param_type/parameter.c					\
		$(SRC_DIR)/bytecode/instr_code/instr_code.c							\
		$(SRC_DIR)/bytecode/instr_param/instr_param.c						\
		$(SRC_DIR)/bytecode/instr_param/direct.c							\
		$(SRC_DIR)/bytecode/instr_param/indirect.c							\
		$(SRC_DIR)/bytecode/instr_param/register.c							\
		$(SRC_DIR)/bytecode/write_name.c									\
		$(SRC_DIR)/bytecode/write_desc.c									\
		$(SRC_DIR)/bytecode/write_instr_info.c								\
		$(SRC_DIR)/bytecode/label_values.c									\
		$(SRC_DIR)/my_write_str_to_file_in_hex.c							\
		$(SRC_DIR)/parameters.c												\
		$(SRC_DIR)/params_utils.c											\
		$(SRC_DIR)/char_booleans.c											\
		$(SRC_DIR)/params_verification.c									\
		$(SRC_DIR)/labels_are_known.c

SRC_TESTS=		tests/corewar_tests.c

DIR_INCLUDE =	include
NAME_LIB =		libmy.a



CFLAGS		=	-Iinclude -Wall -Wextra -pedantic -Wpedantic -g3
LFLAGS		=	-L. -lmy
DIR_LIB =		lib/my
NAME	=		asm
NAME_TESTS	=	unit_tests

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)
OBJ_NO_MAIN =	$(SRC:.c=.o)
OBJ_TESTS =		$(SRC_TESTS:.c=.o)


all:	$(NAME)

$(NAME):		make_lib compil

make_lib:
	@cd $(DIR_LIB) && make

compil:		$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)


tests_run:	make_lib $(OBJ_NO_MAIN) $(OBJ_TESTS)
	@gcc -o $(NAME_TESTS) $(OBJ_NO_MAIN) $(OBJ_TESTS) $(CFLAGS) $(LFLAGS) --coverage -lcriterion;
	./unit_tests;

debug: $(OBJ)
	@gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	@echo -e "${GREEN}[CLEAN] ${WHITE}Removing ${BLUE}project components${WHITE}...${NC}"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo -e "${GREEN}[FCLEAN] ${WHITE}Removing ${BLUE}${NAME_LIB}${WHITE}...${NC}"
	@rm -f $(NAME_LIB)
	@cd $(DIR_LIB) && make fclean

re: fclean all

.PHONY: re
