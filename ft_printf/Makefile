# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 21:01:41 by djuarez           #+#    #+#              #
#    Updated: 2024/08/08 18:50:27 by djuarez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = cc
CCFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = libftprintf.a
SRC =	ft_printf.c \
	ft_check_conv.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_pointer.c \
	ft_unsigned_int.c \
	ft_hexadecimal.c \
	ft_putnbr.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o:%.c $(INCLUDE) Makefile
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
