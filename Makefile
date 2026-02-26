# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anezka <anezka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 22:30:01 by anezkahavra       #+#    #+#              #
#    Updated: 2026/02/18 16:41:50 by anezka           ###   ########.fr        #
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
			parsing/print_struct.c\
			parsing/for_exit.c\
			free_stuff.c\
			game_setup/game_crossroad.c\
			game_setup/setting_player.c\

LIBFTLIB = libft/libft.a
MLX42LIB = MLX42/build/libmlx42.a


OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS =  -Wall -Werror -Wextra -g 
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm

all:$(NAME)

$(NAME):$(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(MLX42LIB) $(LIBFTLIB) $(MLXFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all