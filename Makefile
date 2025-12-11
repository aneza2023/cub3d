# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 22:30:01 by anezkahavra       #+#    #+#              #
#    Updated: 2025/12/11 20:23:03 by ahavrank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SOURCES = main.c\
			parsing/parsing.c\
			parsing/parse_map.c\
			parsing/parse_map_utils.c\
			parsing/parse_map_borders.c\
			parsing/parse_map_borders_utils.c\
			parsing/parse_colours.c\
			parsing/parse_colours_utils.c\
			parsing/parse_textures.c\
			parsing/set_struct.c\
			free_stuff.c\
			raycasting.c\
			setting_player.c\

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