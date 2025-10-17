/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:49:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/10/17 11:03:57 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_elements(char *line, t_map *map)
{
	(void)line;
	(void)map;
	return (0);
}

t_map	*parse_crossroad(char *argv, t_map *map)
{
	int fd;
	char *line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
			parsing_elements(line, map);
		// else
		// 	parsing_map(line, map);
		printf("line: %s", line);
		free(line);
	}
	return (map);
}
