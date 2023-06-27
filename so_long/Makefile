# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 07:46:22 by jmouaike          #+#    #+#              #
#    Updated: 2023/02/06 10:29:00 by jmouaike         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# so_long project
NAME		= so_long
INCL_DIR	= ./include/
SRC_DIR		= ./src/
SRC_FILES	= so_long.c load_map.c so_long_utils.c \
			 check_map.c outbound.c pathfinding.c \
			 update_display.c \

SRC 		= $(addprefix $(SRC_DIR),$(SRC_FILES))

# minilibx
MLX_DIR		= ./minilibx-linux/
LIB_MLX		= $(addprefix $(MLX_DIR), libmlx.a)

# Libft
LFT_DIR		= ./libft/
LIB_LFT		= $(addprefix $(LFT_DIR), libft.a)

# compilation
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 
#-fsanitize=address
INCL_NAME	= -I $(INCL_DIR)
INCL_MLX	= -I $(MLX_DIR)
INCL_LFT	= -I $(LFT_DIR)

# linkage
LFLAGS_LFT	= -L $(LFT_DIR) -lft 
# mlx (Linux)
LFLAGS_MLX		= -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

# colors
G		= "\33[92m"
RES		= "\33[0m"

# ########################## #
#      Makefile rules        #
# ########################## #

all:	$(NAME)	

$(NAME): $(LIB_LFT) $(LIB_MLX)
	$(CC) $(CFLAGS) $(SRC) $(INCL_NAME) $(INCL_LFT) $(INCL_MLX) $(LFLAGS_LFT) $(LFLAGS_MLX) -o $(NAME)
#	$(CC) $(CFLAGS) $(SRC) $(INCL_NAME) $(INCL_LFT) $(LFLAGS_LFT) -o $(NAME)
	@echo $(G) making so_long executable [OK]  $(RES) 

$(LIB_LFT):
	@make -C $(LFT_DIR) all
	@make -C $(LFT_DIR) bonus
	@echo  $(G) making libft.a including bonus [OK] $(RES) 

$(LIB_MLX):
	@make -C $(MLX_DIR) all
	@echo $(G) making libmlx.a [OK] $(RES) 

clean:
	@make -C $(LFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo cleaned *.o [OK]

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LFT_DIR) fclean
#	@make -C $(MLX_DIR) fclean
	@echo fcleaned *.a [OK]

re: fclean all

norm:
	@echo $(G) so_long directory $(RES) 
	@norminette $(SRC_DIR)* $(INCL_DIR)*
	@echo $(G) libft directory $(RES) 
	@norminette $(LFT_DIR)*.c $(LFT_DIR)*.h

.PHONY: all clean fclean re norm

# DEBUG = -g3 -fsanitize=address
# 
# valgrind --leak-check=full --show-leak-kinds=all -s -q
#  $ env -i <votre-executable>
# https://makefiletutorial.com/#interrupting-or-killing-make
#
# gcc -Wall -Werror -Wextra ./src/so_long.c ./src/load_map.c ./src/so_long_utils.c ./src/check_map.c
# ./src/outbound.c ./src/pathfinding.c -I ./include/ -I ./libft/ -I ./minilibx-linux-master -L ./libft/ -lft 
# -L ./minilibx-linux-master -lmlx -lX11 -lXext -lm -lz   -o so_long
