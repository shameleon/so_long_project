# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:29:52 by jmouaike          #+#    #+#              #
#    Updated: 2022/12/08 11:51:43 by jmouaike         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c \
	  ft_strlcpy.c ft_strlcat.c \
	  ft_bzero.c ft_memchr.c ft_memcmp.c ft_memset.c \
	  ft_memcpy.c ft_memmove.c \
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_split.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  get_next_line.c ft_strjoin_free.c \
	  ft_strcountchr.c ft_free_split.c \

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	  ft_lstiter.c ft_lstmap.c \

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
AR	= ar rcs
RL	= ranlib
RM	= /bin/rm -f

all: $(NAME)
	
$(NAME): $(OBJS)
	@$(AR) $@ $^
	@$(RL) $(NAME)
	@echo "making libft.a"

.c.o: 
	@$(CC) $(CFLAGS) -c $^ -o $@

bonus: $(OBJS_B)
	@$(AR) $(NAME) $^
	@$(RL) $(NAME)

(OBJS_B): $(SRCS_B)
	@$(CC) $(FLAGS) -c $^ -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette *.c *.h

.PHONY: all clean fclean re bonus nrom
