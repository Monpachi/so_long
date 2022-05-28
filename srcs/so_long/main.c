#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;

	(void)argc;
	map = (t_map){0};
	map.mlx = mlx_init();
	if (!map.mlx)
		return (1);
	intro_window(&map, argv);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop_hook(map.mlx, looking_for_animation, &map);
	mlx_loop(map.mlx);
	return (0);
}
