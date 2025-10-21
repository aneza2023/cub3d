/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:49:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/10/21 22:43:16 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_head(t_map **map)
{
	(*map)->head_map = malloc(sizeof(char *) * ((*map)->map_info->lenght + 1));
	if ((*map)->head_map == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
}

void	set_start_colours(t_map **map)
{
	(*map)->F_colour->blue = -1;
	(*map)->F_colour->red = -1;
	(*map)->F_colour->green = -1;	
	(*map)->C_colour->blue = -1;
	(*map)->C_colour->red = -1;
	(*map)->C_colour->green = -1;
	(*map)->map_info = malloc(sizeof(t_map_info));
	if ((*map)->map_info == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
	(*map)->map_info->lenght = 0;
	(*map)->map_info->space_count = 0;
}

void	prepare_map(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (*map == NULL)
	{
		perror("");
		exit(1);
	}
	(*map)->NO_texture = NULL;
	(*map)->SO_texture = NULL;
	(*map)->WE_texture = NULL;
	(*map)->EA_texture = NULL;
	(*map)->C_colour = malloc(sizeof(t_colour));
	(*map)->F_colour = malloc(sizeof(t_colour));
	if ((*map)->F_colour == NULL || (*map)->C_colour == NULL)
	{
		perror("");
		free_map(map);
		exit (1);
	}
	set_start_colours(map);
	(*map)->map = NULL;
	(*map)->head_map = NULL;
}

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
	prepare_map(map);
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
