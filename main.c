#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Program accepts only single argument in *.cub format\n",
			STDERR_FILENO);
		return (1);
	}
	else
		parse_crossroad(argv[1], &map);
	if (setup_game(&map))
		return (free_map(&map), 1);
	run_mlx(map);
	return (0);
}
