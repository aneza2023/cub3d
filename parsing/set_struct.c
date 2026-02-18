/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:35:21 by ahavrank          #+#    #+#             */
/*   Updated: 2026/02/18 12:52:58 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player(t_map **map)
{
	(*map)->player = malloc(sizeof(t_player));
	if ((*map)->player == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
}

void	set_head(t_map **map)
{
	(*map)->head_map = malloc(sizeof(char *) * ((*map)->map_info->line_count + 1));
	if ((*map)->head_map == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
}

void	set_start_colours(t_map **map)
{
	(*map)->F_colour->blue = -1;
	(*map)->F_colour->red = -1;
	(*map)->F_colour->green = -1;	
	(*map)->C_colour->blue = -1;
	(*map)->C_colour->red = -1;
	(*map)->C_colour->green = -1;
	(*map)->map_info = NULL;
	(*map)->map_info = malloc(sizeof(t_map_info));
	if ((*map)->map_info == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
	(*map)->map_info->line_count = 0;
	(*map)->map_info->space_count = 0;
	(*map)->player = NULL;
	set_player(map);
}

void	set_map_struct(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (*map == NULL)
	{
		perror("");
		exit(1);
	}
	(*map)->NO_texture = NULL;
	(*map)->SO_texture = NULL;
	(*map)->WE_texture = NULL;
	(*map)->EA_texture = NULL;
	(*map)->F_colour = NULL;
	(*map)->C_colour = NULL;
	(*map)->map = NULL;
	(*map)->head_map = NULL;
	(*map)->F_colour = malloc(sizeof(t_colour));
	(*map)->C_colour = malloc(sizeof(t_colour));
	if ((*map)->F_colour == NULL || (*map)->C_colour == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
	set_start_colours(map);
}
