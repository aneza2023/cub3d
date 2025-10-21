/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_borders_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:29:01 by anezka            #+#    #+#             */
/*   Updated: 2025/10/21 22:42:47 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	borders_next(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '0')
		return (1);
	return (0);
}

int	count_spaces(t_map **map, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while ((*map)->map[i][j] == ' ')
		j++;
	while ((*map)->map[i][j] != '\0')
	{
		if ((*map)->map[i][j] == ' ')
			count++;
		j++;
	}
	while (i > 0 && ((*map)->map[i][j] != '1' && (*map)->map[i][j] != '0')) 
	{
		if ((*map)->map[i][j] == ' ')
			count--;
		j--;
	}
	(*map)->map_info->space_count = count;
	return (count);
}

int	add_position(char *line, char find, int last)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == find && i > last)
			return (i);
		i++;
	}
	return (-1);
}

int	*space_positions(t_map **map, int i)
{
	int	count;
	int	last;
	int	j;
	int	*positions;

	count = count_spaces(map, i);
	if (count == 0)
		return (NULL);
	positions = malloc(sizeof(int) * count);
	if (positions == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
	last = 0;
	j = 0;
	while(count > 0)
	{
		positions[j] = add_position((*map)->map[i], ' ', last);
		last = positions[j];
		j++;
		count--;
	}
	return (positions);
}
