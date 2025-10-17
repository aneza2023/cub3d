# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 22:30:01 by anezkahavra       #+#    #+#              #
#    Updated: 2025/10/17 10:50:47 by anezkahavra      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SOURCES = main.c\
			parsing.c

LIBFTLIB = libft/libft.a
# MLX42LIB = MLX42/build/libmlx42.a

OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS =  -Wall -Werror -Wextra -g 

all:$(NAME)

$(NAME):$(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(MLX42LIB) $(LIBFTLIB) $(MLXFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all