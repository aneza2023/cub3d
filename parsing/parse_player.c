/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:25:19 by anezka            #+#    #+#             */
/*   Updated: 2026/03/01 23:29:33 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player(t_map **map)
{
	int count;
	int k;
	int i;

	i = 0;
	count = 0;
	while ((*map)->map[i] != NULL)
	{
		k = 0;
		while ((*map)->map[i][k] != '\0')
		{
			if ((*map)->map[i][k] != '0' && (*map)->map[i][k] != '1' && (*map)->map[i][k] != ' ' && (*map)->map[i][k] != 'W' 
				&& (*map)->map[i][k] != 'S' && (*map)->map[i][k] != 'N' && (*map)->map[i][k] != 'E' )
				return (1);
			if ((*map)->map[i][k] == 'W' || (*map)->map[i][k] == 'S' || (*map)->map[i][k] == 'N' || (*map)->map[i][k] == 'E')
				count++;
			k++;
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}
