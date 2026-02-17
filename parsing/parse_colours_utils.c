/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colours_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:49:14 by anezka            #+#    #+#             */
/*   Updated: 2026/02/17 15:50:17 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_first_colour(char *string)
{
    int			i;
	static int	count;

    i = 0;
	while(string[i] == ' ')
		i++;
	if (string[i] == 'C' || string[i] == 'F')
		count++;
	else if (string[i] != 'C' && string[i] != 'F')
		return (1);
	i++;
	while(string[i] == ' ')
		i++;
	while (string[i] != '\0')
	{
		if (string[i] < '0' || string[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_other_colour(char *string)
{
	char	*trim_str;
	int		i;

	trim_str = ft_strtrim(string, " ");
	i = 0;
	while(trim_str[i] != '\0')
	{
		if ((trim_str[i] < '0' || trim_str[i] > '9') && trim_str[i] != '\n')
			return (1);
		i++;
	}
	return (0);

}

int	colour_values_cnt(char **strings, int colour)
{
	int		colour_nb;

	if (colour == 1)
	{
		if (check_first_colour(strings[0]) == 1)
		{
			ft_putstr_fd("Colours values are invalid\n", STDERR_FILENO);
			return (-1);
		}
		colour_nb = ft_atoi(ft_strtrim(strings[0], "FC"));
	}
	if (check_other_colour(strings[1]) == 1 || check_other_colour(strings[2]) == 1)
	{
		ft_putstr_fd("Colours values are invalid\n", STDERR_FILENO);
		return (-1);
	}
	if (colour == 2)
		colour_nb = ft_atoi(strings[1]);
	if (colour == 3)
		colour_nb = ft_atoi(strings[2]);
	return (colour_nb);
}

int	colour_values(char *line, int colour)
{
	int		count;
	char	**strings;
	int		colour_nb;

	count = 0;
	strings = ft_split(line, ',');
	while(strings[count] != NULL)
		count++;
	if (count != 3)
	{
		ft_putstr_fd("Too many arguments for colour\n", STDERR_FILENO);
		free_strings(strings, count);
		return (-1);
	}
	colour_nb = colour_values_cnt(strings, colour);
	if (colour_nb > 255)
	{
		ft_putstr_fd("Colour values are invalid\n", STDERR_FILENO);
		colour_nb = -1;
	}
	if (colour_nb < 0)
		return (-1);
	return(colour_nb);
}
