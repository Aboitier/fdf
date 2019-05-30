# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 16:25:54 by aboitier          #+#    #+#              #
#    Updated: 2019/05/28 18:14:49 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc

FLAGS = -Wall -Wextra -Werror 

PATH_TO_INCLUDE = /usr/local/include
PATH_TO_MLXLIB = /usr/local/lib
LMLX = -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit

MLX_COMPIL = -I $(PATH_TO_INCLUDE) -L $(PATH_TO_MLXLIB) $(LMLX) $(FRAMEWORKS)

PATH_LIBFT = libft
LIBFT.A = $(PATH_LIBFT)/libft.a
SRCS = srcs/setup_square.c srcs/init.c srcs/create_image.c srcs/parser.c srcs/draw_line.c 

all : $(NAME)

$(NAME):
	@$(MAKE) $(PATH_LIBFT)
	@$(CC) $(FLAGS) test_mlx.c $(SRCS) $(LIBFT.A) $(MLX_COMPIL) -o $(NAME)
	@echo "$(NAME) has been created\n"
	
clean:
	rm $(NAME)

re: clean all
