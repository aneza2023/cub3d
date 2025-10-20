/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_borders_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:29:01 by anezka            #+#    #+#             */
/*   Updated: 2025/10/20 17:33:25 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	*space_positions(char *line)
{
	int	i;
	int	count;
	int	*positions;

	i = 0;
	count = 0;
	printf("line: %s", line);
	while(line[i] != '\0')
	{
		while (line[i] == '1' || line[i] == '0')
			i++;
		while (line[i] == ' ')
		{
			count++;
			i++;
		}
		i++;
	}
	printf("count_bef: %d\n", count);
	// positions = malloc(sizeof(int) * count);
	(void)positions;
	return (NULL);
}
