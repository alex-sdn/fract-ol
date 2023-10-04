# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asadanow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 16:58:17 by asadanow          #+#    #+#              #
#    Updated: 2023/02/04 16:45:48 by asadanow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./src/main.c \
		./src/utils.c \
		./src/hooks.c \
		./src/fractals.c \
		./src/fractals_2.c \
		./src/help_prompt.c \
		./src/colorways.c

LIBDIR = ./libft/

CC = cc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd $(LIBDIR) && $(MAKE)
	$(CC) $(OBJ) ./libft/libft.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lz -o $(NAME) -lm

.c.o:
	$(CC) -I ./includes -I /usr/include -Iminilibx-linux -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	cd $(LIBDIR) && $(MAKE) clean

fclean: clean
	/bin/rm -f $(NAME)
	cd $(LIBDIR) && $(MAKE) fclean

bonus:	all

re: fclean all
