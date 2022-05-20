#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	intro_window(t_map *map)
{
	int	width_intro;
	int	height_intro;
	int	width_newgame;
	int	height_newgame;

	map->intro = mlx_xpm_file_to_image(map->mlx, IMG_INTRO,
			&width_intro, &height_intro);
	map->intro1 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO1,
			&width_newgame, &height_newgame);
	mlx_put_image_to_window(map->mlx, map->win, map->intro,
		0, 0);
	mlx_put_image_to_window(map->mlx, map->win, map->intro1,
		420, 800);
//	mlx_string_put(map->mlx, map->win, 0, 1100, 255, "\033[1;32mSCORE");

}

void	game(t_map *map)
{
	char	**line;

	// map->mlx = mlx_init();
	line = map->fullmap;
	map->lenght = ft_strlen(line[0]);
	// map->win = mlx_new_window(map->mlx, map->lenght * WIDTH,
			// map->height * HEIGHT, "so_long");
	map_insert(map);
	img_to_win(line, map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_loop(map->mlx);
}
