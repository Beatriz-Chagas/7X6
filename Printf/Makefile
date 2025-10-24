NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putstr.c ft_putchar.c \
       ft_putnbr.c ft_puthex.c ft_putptr.c

LIB = ft_printf.h

OBJS = ${SRCS:.c=.o}

%.o: %.c $(LIB)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
