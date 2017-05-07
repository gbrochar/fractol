# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/10 02:28:41 by gbrochar          #+#    #+#              #
#    Updated: 2016/05/30 03:16:28 by gbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c \
		draw.c \
		event_hook.c \
		check_arg.c \
		pixel_put.c \
		draw_0_3.c \
		draw_4_7.c \
		compute.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) libft/libft.a $(SRC) -o $(NAME) -lpthread -lm -lmlx -framework Appkit -framework OpenGL

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
