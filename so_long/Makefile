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
			 check_map.c outbound.c pathfinding.c update_display.c \

SRC 		= $(addprefix $(SRC_DIR),$(SRC_FILES))

# objects
OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# minilibx
MLX_DIR		= ./minilibx-linux/
LIB_MLX		= $(addprefix $(MLX_DIR), libmlx.a)
MLX_INTRA42	= "https://cdn.intra.42.fr/document/document/17922/minilibx-linux.tgz"

# Libft
LFT_DIR		= ./libft/
LIB_LFT		= $(addprefix $(LFT_DIR), libft.a)

# compilation
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
DEBUG		= -g3 -fsanitize=address

# includes
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

$(NAME): $(LIB_LFT) $(LIB_MLX) $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS_LFT) $(LFLAGS_MLX) -o $(NAME)
	@echo $(OR) making so_long executable [OK]  $(RES) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCL_NAME) -c $< -o $@

$(LIB_LFT):
	@make -C $(LFT_DIR) all
	@make -C $(LFT_DIR) bonus
	@echo  $(PK) making libft.a including bonus [OK] $(RES) 

$(LIB_MLX):
	@make -C $(MLX_DIR) all
	@echo $(G) making libmlx.a [OK] $(RES) 

mlx:
	@if [ ! -d $(MLX_DIR) ]; then \
		wget $(MLX_INTRA42); \
		tar -xvzf minilibx-linux.tgz; \
		rm -f minilibx-linux.tgz; \
		fi

clean:
	@make clean -C $(LFT_DIR)
	@make clean -C $(MLX_DIR)
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rfv $(OBJ); \
		rmdir $(OBJ_DIR); \
		fi
	@echo cleaned *.o [OK]

fclean: clean
	rm -rfv $(NAME)
	@make fclean -C $(LFT_DIR)
	@echo fcleaned *.a [OK]

re: fclean all

norm:
	@echo $(VI) "norminette check for *.c *.h files :"
	@echo $(OR) so_long directory $(RES) 
	@norminette $(SRC_DIR)* $(INCL_DIR)*
	@echo $(PK) libft directory $(RES) 
	@norminette $(LFT_DIR)*.c $(LFT_DIR)*.h

.PHONY: all clean fclean re norm mlx


# valgrind --leak-check=full --show-leak-kinds=all -s -q
#
# gcc -Wall -Werror -Wextra ./src/so_long.c ./src/load_map.c ./src/so_long_utils.c ./src/check_map.c
# ./src/outbound.c ./src/pathfinding.c -I ./include/ -I ./libft/ -I ./minilibx-linux-master -L ./libft/ -lft 
# -L ./minilibx-linux-master -lmlx -lX11 -lXext -lm -lz   -o so_long

##### ANSI Escape Codes #####
G 		= "\33[1;32m"
VI		= "\33[1;38:5:55m"
PK		= "\33[1;95:185:55m"
OR		= "\33[1;38:5:214m"
YL		= "\33[1;33m"
CY		= "\33[1;36m"
RES		= "\33[0m"
