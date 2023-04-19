# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 10:47:18 by yrabby            #+#    #+#              #
#    Updated: 2023/04/19 11:37:07 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				= \033[0;31m
CYAN			= \033[0;36m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
NC 				= \033[0m

NAME 					= cub3D
export ROOT_DIR			= $(CURDIR)

# MAC vs Linux
OS := $(shell uname -s)
ifeq ($(OS),Linux)
OS_TYPE := -DLINUX_ON=1
LIBX_FLAGS := -lmlx_Linux -lXext -lX11 -lm -lz
LIBX_NAME := libmlx_Linux.a
LIBX_DIR := minilibx_linux
else
OS_TYPE := -DMAC_ON=1
LIBX_NAME := libmlx.a
LIBX_DIR := minilibx_mac
LIBX_FLAGS := -lmlx -framework OpenGL -framework AppKit
endif

#---------- LIBX ----------
LIBX = $(addprefix $(LIBX_DIR)/, $(LIBX_NAME))
LIBX_HEAD_DIR = $(LIBX_DIR)
LIBX_LINUX_EXTRA = $(addprefix $(LIBX_DIR)/, libmlx.a)

#---------- HEAD ----------
export HEAD_DIR			= include
HEAD_NAME 				= $(notdir $(wildcard $(HEAD_DIR)/*.h))
HEAD 					= $(addprefix $(HEAD_DIR)/, $(HEAD_NAME))

#---------- SRC ----------
export SRC_DIR			= src
SRC 					= $(wildcard $(SRC_DIR)/**/*.c)

#---------- OBJ ----------
OBJ_DIR 				= obj
OBJ						= $(subst $(SRC_DIR),$(OBJ_DIR), $(SRC:.c=.o))
OBJ_NO_MAIN	 			= $(filter-out obj/main/main.o,$(OBJ))

#---------- LIBFT ----------
LIBFT_NAME				= libft.a
export LIBFT_DIR		= libft
LIBFT_HEAD_DIR			= $(LIBFT_DIR)
LIBFT					= $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

#---------- FLAGS ----------
CC 						= cc
HEAD_FLAG				= -I$(HEAD_DIR) -I$(LIBFT_HEAD_DIR) -I$(LIBX_HEAD_DIR) 
CFLAGS 					= -c -Wall -Wextra -Werror $(HEAD_FLAG) $(OS_TYPE)
LDFLAGS 				= -L$(LIBFT_DIR) -L$(LIBX_DIR) 
LDLIBS 					= -lft $(LIBX_FLAGS)

#---------- IMPLICT RULES ----------
$(addprefix $(OBJ_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c) $(HEAD)
	@$(CC) $(CFLAGS) $< -o $(@)

#---------- RULES ----------
.PHONY: clean fclean re all

all: $(OBJ_DIR) $(NAME)

$(LIBX):
	$(MAKE) -sC ./$(LIBX_DIR)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(OBJ_DIR):
	@cp -a $(SRC_DIR) $(OBJ_DIR)
	@$(RM) $(OBJ:.o=.c)

$(NAME): $(OBJ) $(LIBFT) $(LIBX)
	@echo "$(GREEN)Compilation was Successful!$(NC)"
	@echo "$(YELLOW)Linking... $(NC)"
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@
	@echo "$(GREEN)$(NAME) READY!$(NC)"

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(LIBX)
	@$(RM) $(LIBX_LINUX_EXTRA)
	@echo "$(RED)Objects Removed!$(NC)"

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) Removed!$(NC)"

re: fclean all
