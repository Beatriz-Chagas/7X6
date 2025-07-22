# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 10:59:34 by bchagas-          #+#    #+#              #
#    Updated: 2025/07/17 19:46:56 by bchagas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

//variaveis
SRCDIR = srcs/
INCDIR = includes/
NAME = libft.a
CC = cc -Werror -Wall -Wextra
FILES = srcs/ft_putchar.c $(SRCDIR)ft_putstr.c $(SRCDIR)ft_strcmp.c
OBJS = $(FILES:.c=.o)

//targets
all: $(NAME)

// deleta arquivos .o
clean:
	rm *.o

// deleta arquivos .o e .a
fclean: clean
	rm $(NAME)

// deleta os arquivos .o .a e recria
re: fclean all

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

//
%.o: srcs/%.c
	$(CC) -c $< -o $@
