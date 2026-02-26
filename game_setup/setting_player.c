/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:43:55 by ahavrank          #+#    #+#             */
/*   Updated: 2025/12/17 15:41:24 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int setting_direction_cnt(t_map **map)
{
    if ((*map)->player->direction == 'S')
    {
        (*map)->player->dir_x = 0;
        (*map)->player->dir_y = -1;
    }
    if ((*map)->player->direction == 'E')
    {
        (*map)->player->dir_x = 1;
        (*map)->player->dir_y = 0;
    }

    if ((*map)->player->direction == 'W')
    {
        (*map)->player->dir_x = -1;
        (*map)->player->dir_y = 0;
    }
    return (0);
}

int setting_direction(t_map **map)
{
    int i;
	int	j;

	i = 0;
    while((*map)->map[i] != NULL)
	{
		j = 0;
		while((*map)->map[i][j] != '\0')
		{
			if ((*map)->map[i][j] != '0' && (*map)->map[i][j] != '1' 
				&& (*map)->map[i][j] != ' ' && (*map)->map[i][j] != '\n')
				(*map)->player->direction = (*map)->map[i][j];
			j++;
		}
		i++;
	}
    (*map)->map = (*map)->head_map;
	if ((*map)->player->direction == 'N')
    {
        (*map)->player->dir_x = 0;
        (*map)->player->dir_y = 1;
    }
    setting_direction_cnt(map);
	// printf("(*map)->map[i][j]: %c\n", (*map)->player->direction);
	return (0);
}

int setting_position(t_map **map)
{
    int i;
    int j;

    i = 0;
    while((*map)->map[i] != NULL)
	{
		j = 0;
		while((*map)->map[i][j] != '\0')
		{
			if ((*map)->map[i][j] != '0' && (*map)->map[i][j] != '1' 
				&& (*map)->map[i][j] != ' ' && (*map)->map[i][j] != '\n')
			{
                (*map)->player->pos_x = j;
                (*map)->player->pos_y = i;
            }
			j++;
		}
		i++;
	}
    // printf("x: %f\n", (*map)->player->pos_x);
    // printf("y: %f\n", (*map)->player->pos_y);
    return (0);
}

int setting_player(t_map **map)
{
    setting_position(map);
    setting_direction(map);
    (*map)->player->plane_x = 0;
    // (*map)->player->plane_y = 0,66; now issue because not used
    (*map)->time = 0;
    (*map)->old_time = 0;
    return (0);
}