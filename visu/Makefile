# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmouhtas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 13:59:03 by fmouhtas          #+#    #+#              #
#    Updated: 2018/06/28 17:11:25 by fmouhtas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu

FLAGS = -Wall -Wextra -Werror

FRAMEWORK = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

LFT = -L ../libft/ -lft

SRCS =	main.c \
		skip_funct.c \
		key_press.c \
		get_infos.c

SRCS_PATH = $(addprefix srcs/, $(SRCS))

OBJ = $(SRCS_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx_macos/
	gcc $(FLAGS) $^ $(LFT) $(FRAMEWORK) -I ./includes/ -o $@

%.o: %.c ./includes/visu.h
	gcc $(FLAGS) -c $< -I ./includes/ -o $@

clean:
	make -C ./minilibx_macos/ clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
