# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycarro <ycarro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 10:47:18 by yrabby            #+#    #+#              #
#    Updated: 2023/02/13 12:56:56 by ycarro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile_util.mk

NAME 					= cub3d
export ROOT_DIR			= $(CURDIR)

#---------- HEAD ----------
HEAD_DIR 				= include
HEAD_NAME 				= \
	dll.h \
	tab.h \
	main.h \
	macro.h \
	error_code.h \

HEAD 					= $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

#---------- SRC ----------
SRC_DIR 				= src
SRC 					= \
	src/dll/dll_iterate.c \
	src/dll/dll_add.c \
	src/dll/dll.c \
	src/dll/dll_is.c \
	src/dll/dll_swap.c \
	src/dll/dll_remove.c \
	src/dll/dll_get.c \
	src/tab/tab2.c \
	src/tab/tab.c \
	src/main/main.c \
	src/parser/parse_args.c \

#---------- OBJ ----------
OBJ_DIR 				= obj
OBJ						= $(subst $(SRC_DIR),$(OBJ_DIR), $(SRC:.c=.o))
OBJ_NO_MAIN	 			= $(filter-out obj/main/main.o,$(OBJ))

#---------- LIBFT ----------
LIBFT_NAME				= libft.a
LIBFT_DIR				= libft
LIBFT_HEAD_DIR			= $(LIBFT_DIR)
LIBFT					= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

#---------- TEST ----------
TEST_DIR				= unit_test
TEST_HEAD_DIR			= $(addprefix $(TEST_DIR)/, include)
TEST_HEAD_NMAE			= $(notdir $(wildcard $(TEST_HEAD_DIR)/*.h))
TEST_HEAD				= $(addprefix $(TEST_HEAD_DIR)/, $(TEST_HEAD_NMAE))
TEST_HEAD_FLAG			= -I$(TEST_HEAD_DIR)
TEST_LDLIBS				= -lcunit $(LDLIBS)
export TEST_EXEC		= test.out
export TEST_RES			= unit_test_result.txt
export VALGRIND_OUTPUT 	= valgrind_out.txt
export NORMINETTE_OUTPUT	= norm_out.txt
export NORMINETTE_RES	= norminette_result.txt
TEST_SRC 				= $(wildcard $(TEST_DIR)/**/*.t.c)
TEST_OBJ 				= $(TEST_SRC:.t.c=.t.o)

#---------- CUNIT ----------
CUNIT_DIR				= $(HOME)/.brew/Cellar/cunit/2.1-3/include
LCUNIT_DIR				= $(HOME)/.brew/Cellar/cunit/2.1-3/lib

#---------- SCRIPT ----------
SCRIPT_DIR				= script
TEST_SCRIPT				= $(addprefix $(SCRIPT_DIR)/, test.sh)

#---------- FLAGS ----------
CC 						= cc
HEAD_FLAG				= -I$(HEAD_DIR) -I$(LIBFT_HEAD_DIR) -I$(CUNIT_DIR)
CFLAGS 					= -c -Wall -Wextra -Werror $(HEAD_FLAG)
LDFLAGS 				= -L$(LIBFT_DIR) -L$(LCUNIT_DIR)
LDLIBS 					= -lft

#---------- IMPLICT RULES ----------
$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD)
	@$(CC) $(CFLAGS) $< -o $(@)

$(addprefix $(TEST_DIR)/, %.t.o): $(addprefix $(TEST_DIR)/, %.t.c) $(TEST_HEAD)
	@$(CC) $(CFLAGS) $(TEST_HEAD_FLAG) $< -o $@

#---------- RULES ----------
.PHONY: clean fclean re all check check/leaks check/norm

all: $(OBJ_DIR) $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(OBJ_DIR):
	@cp -a $(SRC_DIR) $(OBJ_DIR)
	@$(RM) $(OBJ:.o=.c)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(GREEN)Compilation was Successful!$(NC)"
	@echo "$(YELLOW)Linking... $(NC)"
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@
	@echo "$(GREEN)$(NAME) READY!$(NC)"

$(TEST_EXEC): $(OBJ_DIR) $(OBJ_NO_MAIN) $(TEST_OBJ) $(LIBFT)
	@$(CC) $(LDFLAGS) $(OBJ_NO_MAIN) $(TEST_OBJ) $(TEST_LDLIBS) -o $(TEST_EXEC)

check: $(TEST_EXEC)
	@bash $(TEST_SCRIPT) unit_test

check/leaks: $(TEST_EXEC)
	@bash $(TEST_SCRIPT) memory

check/norm:
	@bash $(TEST_SCRIPT) norm
	
clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(VALGRIND_OUTPUT)
	@$(RM) $(TEST_RES)
	@$(RM) $(TEST_OBJ)
	@echo "$(RED)Objects Removed!$(NC)"

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(TEST_EXEC)
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) Removed!$(NC)"

re: fclean all
