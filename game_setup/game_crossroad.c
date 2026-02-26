/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_crossroad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:27:14 by ahavrank          #+#    #+#             */
/*   Updated: 2025/12/17 16:36:05 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int setting_window(t_map **map)
{
    mlx_t           *mlx;
    // mlx_image_t*    img;

    mlx = mlx_init(300, 300, "CUB3D", false);
    if (mlx == NULL)
    {
        perror("");
        exit (1);
    }
    (*map)->game->mlx = mlx;
    // img = mlx_new_image(mlx, 300, 300);
    // if (img == NULL)
    // {
    //     perror("");
    //     exit (1);
    // }
	// if ((mlx_image_to_window(mlx, img, 0, 0) < 0))
    // {
    //     perror("");
    //     exit (1);
    // }
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
    return (0);
}

int game_loop(t_map **map)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
      (*map)->game->camera_x = 2 * x / WIDTH - 1;
      (*map)->game->ray_dir_x = (*map)->player->dir_x + (*map)->player->plane_x * (*map)->game->camera_x;
      (*map)->game->ray_dir_y = (*map)->player->dir_y + (*map)->player->plane_y * (*map)->game->camera_x;
    }
    return (0);
}

int where_in_map(t_map **map)
{
    (*map)->game->map_x = (int)(*map)->player->pos_x;
    (*map)->game->map_y = (int)(*map)->player->pos_y;
    // (*map)->game->delta_dist_x = 
    // if ((*map))
    return (0);
}

int	game_crossroad(t_map **map)
{
	// setting_player(map);
    setting_window(map);
    // game_loop(map);
    // where_in_map(map);
    return (0);
}