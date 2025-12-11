/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:49:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/11/26 21:38:52 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_all(t_map **map, char *line)
{
	(void)line;
	if ((*map)->NO_texture == NULL || (*map)->SO_texture == NULL 
		|| (*map)->WE_texture == NULL || (*map)->EA_texture == NULL)
		{
			ft_putstr_fd("Parsing issues with textures\n", STDERR_FILENO);
			free(line);
			free_map(map);
			exit (1);
		}
	if ((*map)->C_colour->red < 0 || (*map)->F_colour->red < 0)
	{
		ft_putstr_fd("Parsing issues with colours\n", STDERR_FILENO);
		free(line);
		free_map(map);
		exit (1);
	}
	//check map ok
	return (0);
}

int	parse_crossroad(char *argv, t_map **map)
{
	int fd;
	char *line;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit (1);
	}
	set_map_struct(map);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0
			|| ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
			parsing_elements_textures(line, map);
		else
			prepare_parse_map(line, map);
		free(line); // issue when comes to end of file but need to work with it more, after proper strdup and othert should be ok
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	check_all_borders(map);
	i = 0;
	while((*map)->map != NULL && (*map)->map[i] != NULL)
	{
		printf("map: %s", (*map)->map[i]);
		i++;
	}
	check_all(map, line);
	free(line);
	return (0);
}
