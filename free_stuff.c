#include "cub3d.h"

void	free_strings(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		strings[i] = NULL;
		i++;
	}
	free(strings);
	strings = NULL;
}

void	free_pt3(t_map **map)
{
	if ((*map)->map != NULL)
	{
		free((*map)->map);
		(*map)->map = NULL;
	}
	if ((*map)->map_info != NULL)
	{
		free((*map)->map_info);
		(*map)->map_info = NULL;
	}
	if ((*map)->player != NULL)
	{
		free((*map)->player);
		(*map)->player = NULL;
	}
	if ((*map)->head_map != NULL)
	{
		free((*map)->head_map);
		(*map)->head_map = NULL;
	}
	free((*map));
	(*map) = NULL;
}

void	free_rest(t_map **map)
{
	int	i;

	i = 0;
	if ((*map)->F_colour != NULL)
	{
		free((*map)->F_colour);
		(*map)->F_colour = NULL;
	}
	if ((*map)->C_colour != NULL)
	{
		free((*map)->C_colour);
		(*map)->C_colour = NULL;
	}
	if ((*map)->map != NULL)
	{
		i = 0;
		while ((*map)->map[i] != NULL)
		{
			free((*map)->map[i]);
			(*map)->map[i] = NULL;
			i++;
		}
	}
	free_pt3(map);
}

void	free_mlx(t_map *map)
{
	int	i;

	if (!map || !map->mlx)
		return ;
	i = 0;
	while (i < 4)
	{
		if (map->texture[i].img)
		{
			mlx_destroy_image(map->mlx, map->texture[i].img);
			map->texture[i].img = NULL;
		}
		i++;
	}
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	map->mlx = NULL;
}

void	free_map(t_map **map)
{
	free_mlx(*map);
	if ((*map)->NO_texture != NULL)
	{
		free((*map)->NO_texture);
		(*map)->NO_texture = NULL;
	}
	if ((*map)->SO_texture != NULL)
	{
		free((*map)->SO_texture);
		(*map)->SO_texture = NULL;
	}
	if ((*map)->WE_texture != NULL)
	{
		free((*map)->WE_texture);
		(*map)->WE_texture = NULL;
	}
	if ((*map)->EA_texture != NULL)
	{
		free((*map)->EA_texture);
		(*map)->EA_texture = NULL;
	}
	free_rest(map);
}
