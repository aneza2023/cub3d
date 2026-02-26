/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:18:57 by anezka            #+#    #+#             */
/*   Updated: 2026/02/18 11:13:56 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	part_of_map(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != '\n')
		{
			if (line[i] == 'N' || line[i] == 'W' || line[i] == 'S' || line[i] == 'E')
				count++;
			else
				return (1);
			
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	gibberish_present(char *line)
{
	int	i;

	i = 0;
	while(line[i] != '\0')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while(line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	space_inside_present(char *line)
{
	int	i;
	int	present;

	i = 0;
	present = 0;
	while(line[i] != '\0')
	{
		if (line[i] == ' ')
			present = 1;
		i++;
	}
	if (present == 1)
		return(0);
	return (1);
}
