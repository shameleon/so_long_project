# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 08:57:41 by jmouaike          #+#    #+#              #
#    Updated: 2022/12/29 09:58:11 by jmouaike         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= explo04
SRC		= explo04.c
CC		= clang
INCLIB	= minilibx
CFLAGS	= -Wall -Werror -Wextra 
LFLAGS	= -lmlx -lX11 -lXext -lm -lz

all:	$(NAME)

$(NAME):
	$(CC) $(SRC) -I$(INCLIB) -L$(INCLIB) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)
re:	clean all

.PHONY : all clean fclean re
