# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 16:09:06 by fmouhtas          #+#    #+#              #
#    Updated: 2018/06/25 12:07:12 by fmouhtas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fmouhtas.filler

FLAGS = -Wall -Wextra -Werror

LFT = -L ./libft/ -lft

SRCS = 	main.c \
		get_map.c \
		get_piece.c \
		put_piece.c \
		skip_line.c

SRCS_PATH = $(addprefix srcs/, $(SRCS))

OBJ = $(SRCS_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/ 
	gcc $(FLAGS) $^ $(LFT) -I ./includes/ -o $@

%.o: %.c ./includes/filler.h 
	gcc $(FLAGS) -c $< -I ./includes/ -o $@

clean:
	make -C ./libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean all
