/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:27:14 by ahavrank          #+#    #+#             */
/*   Updated: 2025/12/11 22:16:11 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	raycasting_crossroad(t_map **map)
{
	setting_player(map);
    setting_window(map);
    // game_loop(map);
    return (0);
}