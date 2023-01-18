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

NAME	= so_long
SPATH	= ./src/
SRC		= main.c
OBJ		= 
INCLIB	= minilibx
CC		= clang
CFLAGS	= -Wall -Werror -Wextra
LFLAGS	= -lmlx -lX11 -lXext -lm -lz

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	$(CC) $(SPATH)$(SRC) -I$(INCLIB) -L$(INCLIB) $(LFLAGS)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)
re:

norm:

.PHONY: all clean fclean re norm
