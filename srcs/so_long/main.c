#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;
	char	**line;

	(void)argc;
	line = putintab(argv);
	init_struct(&map, line, argv);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.lenght * WIDTH, map.height * HEIGHT, "so_long");
	intro_window(&map);
	struct_animated_fog(&map);
	mlx_key_hook(map.win, key_hook, &map);
	// mlx_loop_hook(map.mlx, animation, &map);
	mlx_loop(map.mlx);
	return (0);
}
