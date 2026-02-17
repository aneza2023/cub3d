/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:46:26 by anezka            #+#    #+#             */
/*   Updated: 2026/02/17 16:26:49 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parsing_elements_colours_cnt(char *line, t_map **map)
{
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		(*map)->C_colour->red = colour_values(line, 1);
		if ((*map)->C_colour->red == -1)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
		(*map)->C_colour->green = colour_values(line, 2);
		if ((*map)->C_colour->green == -1)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
		(*map)->C_colour->blue = colour_values(line, 3);
		if ((*map)->C_colour->blue == -1)
		{
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
	}
	return (0);
}

int	parsing_elements_colours(char *line, t_map **map)
{
	if (ft_strncmp(line, "F ", 2) == 0)
    {
        (*map)->F_colour->red = colour_values(line, 1);
        if ((*map)->F_colour->red == -1)
        {
            free(line);
			get_next_line(-3);
            free_map(map);
            exit (1);
        }
        (*map)->F_colour->green = colour_values(line, 2);
        if ((*map)->F_colour->green == -1)
        {
            free(line);
			get_next_line(-3);
            free_map(map);
            exit (1);
        }
        (*map)->F_colour->blue = colour_values(line, 3);
        if ((*map)->F_colour->blue == -1)
        {
            free(line);
			get_next_line(-3);
            free_map(map);
            exit (1);
        }
    }
	return (0);
}
