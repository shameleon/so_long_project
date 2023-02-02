# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 07:46:22 by jmouaike          #+#    #+#              #
#    Updated: 2023/01/10 07:46:28 by jmouaike         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# so_long project
NAME		= so_long
INCL_DIR	= ./include/
SRC_DIR		= ./src/
SRC_FILES	= so_long.c read_file.c parse_map.c validate_map.c \
			path_finding.c libft_utlis.c 
SRC 		= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_FILES:.c=.o))

# minilibx
MLX_DIR		= ./minilibx/
LIB_MLX		= $(addprefix $(MLX_DIR), libmlx.a)

# Libft
LFT_DIR		= ./libft/
LIB_LFT		= $(addprefix $(LFT_DIR), libft.a)

# compilation
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCL_NAME	= -I $(INCL_DIR)
INCL_MLX	= -I $(MLX_DIR)
INCL_LFT	= -I $(LFT_DIR)

# linkage
LFLAGS_LFT	= -L $(LFT_DIR) -lft 
# mlx (Linux)
LFLAGS_MLX		= -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
# mlx (Mac OS X)
SHELL		=/bin/bash
OS_NAME 	= $(shell uname -s)
ifeq ($(OS_NAME), Darwin)
	LMLX_FLAGS	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# ########################## #
#      Makefile rules        #
# ########################## #

all:	$(NAME) $(LIB_MLX) $(LIB_LFT)	

$(NAME): $(OBJ)
	@make -C $(INCL_LIBFT) all
	@make -C $(INCL_MLX) all
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# $(CC) $(CFLAGS) $(OBJ) $(LFLAGS_MLX) $(LFLAGS_LFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo compiling ($<)
	@$(CC) $(CFLAGS) $(INCL_NAME) -c $< -o $@
#	$(CC) $(CFLAGS) $(INCL_NAME) $(INCL_MLX) $(INCL_LFT) -c $<-o $@

clean:
	@rm -rf $(OBJ_DIR)$(OBJ)
	@rmdir $(OBJ_DIR)
	@make -C $(INCL_LIBFT) clean
	@make -C $(INCL_MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(INCL_LIBFT) fclean

re: fclean all

norm:
	@norminette *.c *.h

.PHONY: all clean fclean re norm 

# #-g3 -fsanitize=address
# valgrind --leak-check=full --show-leak-kinds=all -s -q
#  $ env -i <votre-executable>
