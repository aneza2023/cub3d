/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:01:01 by anezka            #+#    #+#             */
/*   Updated: 2026/02/18 12:51:15 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	still_border(char *line, int side)
{
	int	i;

	i = 0;
	if (side == 0)
	{
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		while (line[i] != '\0' && line[i] == '1')
			i++;
		return (i - 1);
	}
	if (side == 1)
	{
		i = find_border(line, 1);
		while (i >= 0)
		{
			if (line[i] != '1')
				break;
			i--;
		}
		return (i + 1);
	}
	return (0);
}

int	borders_around_space(t_map **map, int i)
{
	int *space_pos;
	int	*space_pos_temp;
	int	count;

	if (borders_next((*map)->map[i]) == 1){
		map_invalid(map);
	}
	space_pos = space_positions(map, i);
	space_pos_temp = space_pos;
	count = (*map)->map_info->space_count;
	while (count > 0)
	{
		if (i == 0 && ((*map)->map[i + 1][*space_pos] != '1' && (*map)->map[i + 1][*space_pos] != ' '))
		{
			free(space_pos_temp);
			map_invalid(map);
		}
		else if (i != 0 && (*map)->map[i + 1] != NULL)
		{
			if (((*map)->map[i - 1][*space_pos] != '1' && (*map)->map[i - 1][*space_pos] != ' ') 
				|| ((*map)->map[i + 1][*space_pos] != '1' && (*map)->map[i + 1][*space_pos] != ' '))
			{
				free(space_pos_temp);
				map_invalid(map);
			}
		}
		else if ((*map)->map[i + 1] == NULL && ((*map)->map[i - 1][*space_pos] != '1' && (*map)->map[i - 1][*space_pos] != ' '))
		{
			free(space_pos_temp);
			map_invalid(map);
		}
		count--;
		space_pos++;
	}
	free(space_pos_temp);
	return (0);
}

int	check_first_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	find_border(char *line, int side)
{
	int	i;
	int	lenght;

	if (side == 0)
	{
		i = 0;
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if (line[i] != '\0' && line[i] != '1')
			return (-1);
		return(i);
	}
	else if (side == 1)
	{
		lenght = ft_strlen(line) - 1;
		if(line[lenght] == '\n')
			lenght--;
		while (line[lenght] == ' ')
			lenght--;
		while (line[lenght] != '1')
			return (-1);
		return(lenght);
	}
	return (-1);
}
