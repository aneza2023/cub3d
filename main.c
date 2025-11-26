/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:42 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/11/26 18:14:22 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free_map(&map);
	//comment
	return (0);
}