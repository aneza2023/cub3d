/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:42 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/12/17 15:39:07 by anezkahavra      ###   ########.fr       */
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
	else
		parse_crossroad(argv[1], &map);
	game_crossroad(&map);
	free_map(&map);
	return (0);
}