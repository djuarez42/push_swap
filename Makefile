# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djuarez <djuarez@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 19:13:16 by djuarez           #+#    #+#              #
#    Updated: 2025/02/03 20:20:11 by djuarez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Añadimos las variables para la implementación de ft_printf
FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_DIR)/*.c)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libft.a  # Librería estática de ft_printf

# Regla principal
all : $(NAME)

# Generación del ejecutable final
$(NAME) : $(ARCHIVE) $(FT_PRINTF_LIB)
	$(CC) $< $(FT_PRINTF_LIB) -o $@

# Generación de la librería estática principal
$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

# Regla para compilar ft_printf
$(FT_PRINTF_LIB) : $(FT_PRINTF_OBJS)
	$(MAKE_LIB) $(FT_PRINTF_LIB) $^

# Regla para compilar archivos de ft_printf
$(FT_PRINTF_DIR)/%.o : $(FT_PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar archivos .c en archivos .o
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

# Regla para la compilación de bonus
bonus : 
	cd ../checker && make

# Limpiar archivos objetos y la librería estática
clean :
	rm -f $(OBJS) $(ARCHIVE)
	rm -f $(FT_PRINTF_OBJS) $(FT_PRINTF_LIB)

# Limpiar todo, incluidos el ejecutable
fclean : clean
	rm -f $(NAME)
	cd ../checker && make fclean

# Limpiar todo y recompilar
re : fclean all

# Evitar que se confundan las reglas con nombres de archivos
.PHONY : all clean fclean re
