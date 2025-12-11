/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:11 by anezka            #+#    #+#             */
/*   Updated: 2025/12/11 18:42:51 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	compare_end_borders(int end, t_map **map, int spot)
{
	int	prev_end;
	int	border_cont;

	if (spot == 0)
		return (0);
	prev_end = find_border((*map)->map[spot- 1], 1);
	if (end < prev_end)
	{
		border_cont = still_border((*map)->map[spot - 1], 1);
		if (border_cont > end)
			return (1);
	}
	else if (end > prev_end)
	{
		border_cont = still_border((*map)->map[spot], 1);
		if (border_cont > prev_end)
			return (1);
	}
	return (0);
}

int	compare_start_borders(int start, t_map **map, int spot)
{
	int	prev_start;
	int	border_cont;

	if (spot == 0)
		return (0);
	prev_start = find_border((*map)->map[spot- 1], 0);
	if (prev_start > start)
	{
		border_cont = still_border((*map)->map[spot], 0);
		if (border_cont < prev_start)
			return (1);

	}
	else if (prev_start < start)
	{
		border_cont = still_border((*map)->map[spot - 1], 0);;
		if (border_cont < start)
			return (1);
	}
	return (0);
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

int	parse_map(char *line, t_map **map)
{
	static int	count;
	char		**temp_map;

	temp_map = malloc(sizeof(char *) * (count + 2));
	if (temp_map == NULL)
	{
		perror("");
		free_in_parsing_map(line, map);
	}
	int i = 0;
	while ((*map)->map != NULL && (*map)->map[i] != NULL)
	{
		temp_map[i] = (*map)->map[i];
		i++;
	}
	(*map)->map = temp_map;
	(*map)->map[count] = ft_strdup(line);
	if ((*map)->map[count] == NULL)
	{
		ft_putstr_fd("Map is not valid\n", STDERR_FILENO);
		free_in_parsing_map(line, map);
	}
	count++;
	(*map)->map[count] = NULL;
	return (0);
}

int	prepare_parse_map(char *line, t_map **map)
{
	static int	before_map;

	if (part_of_map(line) == 1 && gibberish_present(line) == 1)
	{
		ft_putstr_fd("Incorrect symbols found\n", STDERR_FILENO);
		free(line);
		free_map(map);
		exit (1);
	}
	if (part_of_map(line) == 0 && empty_line(line) == 0)
	{
		if (before_map == 1)
		{
			ft_putstr_fd("Empty line present inside of map\n", STDERR_FILENO);
			free(line);
			free_map(map);
			exit (1);
		}
		return (0);
	}
	parse_map(line, map);
	(*map)->map_info->line_count++;
	before_map = 1;
	return (0);
}
