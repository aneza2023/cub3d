/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:33:47 by anezka            #+#    #+#             */
/*   Updated: 2026/02/17 15:45:15 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_strings(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	map_invalid(t_map **map)
{
	ft_putstr_fd("Map is invalid\n", STDERR_FILENO);
	free_map(map);
	exit (1);
}

void	free_in_parsing_map(char *line, t_map **map)
{
	free(line);
	free_map(map);
	exit(1);
}

void	free_pt3(t_map **map)
{
	if ((*map)->map_info != NULL)
	{
		free((*map)->map_info);
		(*map)->map_info = NULL;
	}
	if ((*map)->player != NULL)
	{
		free((*map)->player);
		(*map)->player = NULL;
	}
	if ((*map)->head_map != NULL)
	{
		free((*map)->head_map);
		(*map)->head_map = NULL;
	}
	free((*map));
	(*map) = NULL;
}

void	free_rest(t_map **map)
{
	int	i;

	i = 0;
	if ((*map)->F_colour != NULL)
	{
		free((*map)->F_colour);
		(*map)->F_colour = NULL;
	}  
	if ((*map)->C_colour != NULL)
	{
		free((*map)->C_colour);
		(*map)->C_colour = NULL;
	}
	if ((*map)->map != NULL)
	{
		i = 0;
		while((*map)->map[i] != NULL)
		{
			free((*map)->map[i]);
			(*map)->map[i] = NULL;
			i++;
		}
	}
	free_pt3(map);
}

void	free_map(t_map **map)
{
	if ((*map)->NO_texture != NULL)
	{
		free((*map)->NO_texture);
		(*map)->NO_texture = NULL;
	}
	if ((*map)->SO_texture != NULL)
	{
		free((*map)->SO_texture);
		(*map)->SO_texture = NULL;
	}
	if ((*map)->WE_texture != NULL)
	{
		free((*map)->WE_texture);
		(*map)->WE_texture = NULL;
	}
	if ((*map)->EA_texture != NULL)
	{
		free((*map)->EA_texture);
		(*map)->EA_texture = NULL;
	}
	free_rest(map);
}
