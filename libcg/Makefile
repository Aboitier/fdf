# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboitier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 19:26:20 by aboitier          #+#    #+#              #
#    Updated: 2019/05/30 21:58:41 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcg.a

FILES =  	matrices.c
FILES += 	matrix_rot.c
FILES += 	vertex.c

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

GFX = -I . 
FT = -I ../libft
MLX = -I ../minilibx

all: $(NAME)

re: fclean all

clean:
	rm -rf build

fclean:
	rm -rf $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	@echo "Making $@"
	ar rcs $(NAME) $(OBJS)

build/%.o: srcs/%.c | build
	@echo "Building $@"
	gcc $(FLAGS) $(FT) $(MLX) $(GFX) -c $< -o $@

