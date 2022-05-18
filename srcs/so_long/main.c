#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;
	char	**line;

	map.move_step = 0;
	map.move_count = 0;
	map.height = check_width(argv);
	(void)argc;
	map.mlx = mlx_init();
	line = putintab(argv);
	map.fullmap = line;
	map.lenght = ft_strlen(line[0]);
	printf("map LENGHT ---------------------> %d\n", map.height);
	printf("map height ---------------------> %d\n", map.lenght);
	map.win = mlx_new_window(map.mlx, map.lenght * WIDTH, map.height * HEIGHT, "so_long");
	map_insert(&map);
	img_to_win(line, &map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
