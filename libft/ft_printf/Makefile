# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asadanow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 18:38:29 by asadanow          #+#    #+#              #
#    Updated: 2022/11/23 17:10:18 by asadanow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
      ft_putchar_pf.c \
      ft_putnbr_hex_pf.c \
      ft_putnbr_pf.c \
      ft_putnbr_unsigned_pf.c \
      ft_putptr_pf.c \
      ft_putstr_pf.c

CC = cc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

.c.o:
	$(CC) -c $< -I ./ -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
