/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:01:01 by anezka            #+#    #+#             */
/*   Updated: 2026/02/18 16:40:39 by anezka           ###   ########.fr       */
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

void	borders_around_space_loop(t_map **map, int count, int *space_pos, int i)
{
	int	k;

	k = 0;
	while (count > 0)
	{
		if (i == 0 && ((*map)->map[i + 1][space_pos[k]] != '1' && (*map)->map[i + 1][space_pos[k]] != ' '))
			free_borders_loop(space_pos, map);
		else if (i != 0 && (*map)->map[i + 1] != NULL)
		{
			if (((*map)->map[i - 1][space_pos[k]] != '1' && (*map)->map[i - 1][space_pos[k]] != ' ') 
				|| ((*map)->map[i + 1][space_pos[k]] != '1' && (*map)->map[i + 1][space_pos[k]] != ' '))
				free_borders_loop(space_pos, map);
		}
		else if ((*map)->map[i + 1] == NULL && ((*map)->map[i - 1][space_pos[k]] != '1' && (*map)->map[i - 1][space_pos[k]] != ' '))
			free_borders_loop(space_pos, map);
		count--;
		i++;
	}
}

int	borders_around_space(t_map **map, int i)
{
	int *space_pos;
	// int	*space_pos_temp;
	int	count;

	if (borders_next((*map)->map[i]) == 1){
		map_invalid(map);
	}
	space_pos = space_positions(map, i);
	// space_pos_temp = space_pos;
	count = (*map)->map_info->space_count;
	borders_around_space_loop(map, count, space_pos, i);
	// free(space_pos_temp);
	free(space_pos);
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

int	check_all_borders(t_map **map)
{
	int	start_border;
	int	end_border;
	int	i;
	int	border_line;

	i = 0;
	set_head(map);
	while ((*map)->map && (*map)->map[i] != NULL)
	{
		if (i == 0 || (*map)->map[i + 1] == NULL)
			border_line = check_first_border((*map)->map[i]);
		start_border = find_border((*map)->map[i], 0);
		end_border = find_border((*map)->map[i], 1);
		if (start_border == -1 || end_border == -1 || border_line == 1)
			map_invalid(map);
		if (compare_start_borders(start_border, map, i) == 1)
			map_invalid(map);
		if (compare_end_borders(end_border, map, i) == 1)
			map_invalid(map);
		if (space_inside_present((*map)->map[i]) == 0)
			borders_around_space(map, i);
		i++;
	}
	return (0);
}
