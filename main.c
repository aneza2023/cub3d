/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:42 by anezkahavra       #+#    #+#             */
/*   Updated: 2026/02/17 13:04:03 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map *map;

	map = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Program accepts only single argument in *.cub format\n", STDERR_FILENO);
		return (1);
	}
	(void)argv;
	(void)map;
	// else
	// 	parse_crossroad(argv[1], &map);
	// game_crossroad(&map);
	// free_map(&map);
	return (0);
}