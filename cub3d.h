/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2026/02/17 12:50:24 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "libft/getnextline/get_next_line.h"

# define HEIGHT 800 
# define WIDTH 800

typedef struct colours_for_map{
	int	red;
	int	blue;
	int	green;
} t_colour;

typedef struct map_informations {
	int	line_count;
	int	space_count;
	int	map_width;
	int	map_hight;
} t_map_info;

typedef struct game_player{
	char	direction;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_player;

typedef struct	game_information{
	mlx_t	*mlx;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	
}	t_game_info;


typedef struct map{
	char		*NO_texture;
	char		*SO_texture;
	char		*WE_texture;
	char		*EA_texture;
	t_colour	*F_colour;
	t_colour	*C_colour;
	char		**map;
	char		**head_map;
	t_map_info	*map_info;
	t_player	*player;
	double		old_time;
	double		time;
	t_game_info	*game;
} t_map;



void	free_map(t_map **map);
char	*texture_value(char *line);
int     parsing_elements_textures(char *line, t_map **map);
int		parsing_elements_textures_cnt(char *line, t_map **map);
int		parsing_elements_colours(char *line, t_map **map);
int		parsing_elements_colours_cnt(char *line, t_map **map);
int		parse_crossroad(char *argv, t_map **map);
int		parse_map(char *line, t_map **map);
int		part_of_map(char *line);
int		check_all_borders(t_map **map);
int     part_of_map(char *line);
int     still_border(char *line, int side);
int		find_border(char *line, int side);
int		colour_values(char *line, int colour);
int		part_of_map(char *line);
int		prepare_parse_map(char *line, t_map **map);
int		gibberish_present(char *line);
void	free_in_parsing_map(char *line, t_map **map);
int		empty_line(char *line);
int		check_first_border(char *line);
int		compare_start_borders(int start, t_map **map, int spot);
int		compare_end_borders(int end, t_map **map, int spot);
void	map_invalid(t_map **map);
int		space_inside_present(char *line);
int		borders_around_space(t_map **map, int i);
int		borders_next(char *line);
int		*space_positions(t_map **map, int i);
void	set_head(t_map **map);
void	set_start_colours(t_map **map);
void	set_player(t_map **map);
void	set_map_struct(t_map **map);
int		game_crossroad(t_map **map);
int		setting_player(t_map **map);
int		setting_direction(t_map **map);
int		setting_direction_cnt(t_map **map);
int		setting_position(t_map **map);
int		setting_plane(t_map **map);

#endif