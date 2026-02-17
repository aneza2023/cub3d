/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:49:25 by anezka            #+#    #+#             */
/*   Updated: 2026/02/17 15:48:51 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*trim_n_cleanup(char **strings, char *path)
{
	char	*trimpath;

	free(strings);
	if (path != NULL)
		trimpath = ft_strtrim(path, "\n");
	free(path);
	return(trimpath);
}

char *texture_value(char *line)
{
	int		count;
	int		i;
	char	*path;
	char	**strings;

	count = 0;
	strings = ft_split(line, ' ');
	while (strings[count] != NULL)
		count++;
	if (count > 1)
		path = ft_strdup(strings[1]);
	if (count != 2)
	{
		ft_putstr_fd("Texture values are invalid\n", STDERR_FILENO);
		free(path);
		path = NULL;
	}
	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	path = trim_n_cleanup(strings, path);
	return (path);
}

int	parsing_elements_textures_cnt(char *line, t_map **map)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		(*map)->WE_texture = texture_value(line);
		if ((*map)->WE_texture == NULL)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		(*map)->EA_texture = texture_value(line);
		if ((*map)->EA_texture == NULL)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
	}
	parsing_elements_colours(line, map); //memory checked here
	parsing_elements_colours_cnt(line, map);
	return (0);
}

// for memory purposes might need to finish running gnl when exiting
int	parsing_elements_textures(char *line, t_map **map)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		(*map)->NO_texture = texture_value(line);
		if ((*map)->NO_texture == NULL)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		(*map)->SO_texture = texture_value(line);
		if ((*map)->SO_texture == NULL)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
	}
	else
		parsing_elements_textures_cnt(line, map);
	return (0);
}
