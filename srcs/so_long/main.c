#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

// int	main(int argc, char **argv)
// {
// 	t_map	map;
// 	char	**line;

// 	(void)argc;
// 	map.mlx = mlx_init();
// 	line = putintab(argv);
// 	init_struct(&map, line, argv);
// 	printf("map LENGHT ---------------------> %d\n", map.height);
// 	printf("map height ---------------------> %d\n", map.lenght);
// 	map.win = mlx_new_window(map.mlx, map.lenght * WIDTH, map.height * HEIGHT, "so_long");
// 	map_insert(&map);
// 	img_to_win(line, &map);
// 	mlx_key_hook(map.win, key_hook, &map);
// 	mlx_loop(map.mlx);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_map	map;
	char	**line;

	(void)argc;
	line = putintab(argv);
	printf("line[0] %s\n", line[0]);
	printf("line[1] %s\n", line[1]);
	printf("line[2] %s\n", line[2]);
	printf("line[3] %s\n", line[3]);
	printf("line[4] %s\n", line[4]);
	init_struct(&map, line, argv);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 1000, 1000, "so_long");
	intro_window(&map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
