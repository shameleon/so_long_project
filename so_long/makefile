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
SRC_FILES	= so_long.c load_map.c so_long_utils.c \
			 check_map.c outbound.c pathfinding.c \

SRC 		= $(addprefix $(SRC_DIR),$(SRC_FILES))

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

# ########################## #
#      Makefile rules        #
# ########################## #

all:	$(NAME)	

$(NAME): $(LIB_LFT) $(LIB_MLX)
#	$(CC) $(CFLAGS) $(SRC) $(INCL_NAME) $(INCL_LFT) $(INCL_MLX) $(LFLAGS_LFT) $(LFLAGS_MLX) -o $(NAME)
	$(CC) $(CFLAGS) $(SRC) $(INCL_NAME) $(INCL_LFT) $(LFLAGS_LFT) -o $(NAME)
	@echo making so_long executable [OK]

$(LIB_LFT):
	@make -C $(LFT_DIR) all
	@make -C $(LFT_DIR) bonus
	@echo making libft.a including bonus [OK]

$(LIB_MLX):
	@make -C $(MLX_DIR) all
	@echo making libmlx.a [OK]

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
	@norminette *.c *.h

.PHONY: all clean fclean re norm 

# #-g3 -fsanitize=address
# valgrind --leak-check=full 
#  $ env -i <votre-executable>
# https://makefiletutorial.com/#interrupting-or-killing-make