/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:49:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2026/02/18 15:37:19 by anezka           ###   ########.fr       */
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
	return (0);
}

int	correct_format(char *argv)
{
	if (ft_strlen(argv) < 5)
	{
		ft_putstr_fd("Program accepts only single argument in *.cub format\n", STDERR_FILENO);
		exit (1);
	}
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", 5) != 0)
	{
		ft_putstr_fd("Program accepts only single argument in *.cub format\n", STDERR_FILENO);
		exit (1);
	}
	return (0);
}

int	correct_textures(t_map **map, char *line)
{
	int	fd;
	int	fd2;
	int	fd3;
	int	fd4;

	fd = open((*map)->NO_texture, O_RDONLY);
	fd2 = open((*map)->SO_texture, O_RDONLY);
	fd3 = open((*map)->EA_texture, O_RDONLY);
	fd4 = open((*map)->WE_texture, O_RDONLY);
	if (fd == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
	{
		free_map(map);
		free(line);
		perror("Textures");
		exit (1);
	}
	return (0);
}

int	parse_crossroad(char *argv, t_map **map)
{
	int fd;
	char *line;
	// int	i;

	correct_format(argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror(".cub file");
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
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	check_all_borders(map);
	// i = 0;
	// while((*map)->map != NULL && (*map)->map[i] != NULL)
	// {
	// 	printf("map: %s", (*map)->map[i]);
	// 	i++;
	// }
	check_all(map, line);
	correct_textures(map, line);
	free(line);
	return (0);
}
