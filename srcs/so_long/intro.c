#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	which_penny(t_map *map)
{
	if ((map->lenght * 64) > WIN_X && (map->height * 64) > WIN_Y)
	{
		printf("BIGG PENNY ---------------->\n");
		mlx_put_image_to_window(map->mlx, map->win, map->intro,
			(map->lenght * 32) - WIDTH_INTRO / 2,
			(map->height * 32) - HEIGHT_INTRO / 2);
	}
	else if ((map->lenght * 64) < WIN_X || (map->height * 64) > WIN_Y)
	{
		printf("SMALL PENNY ------------------------->\n");
		mlx_put_image_to_window(map->mlx, map->win, map->intro3,
			(map->lenght * 32) - WIDTH_INTRO_SX / 2,
			(map->height * 32) - HEIGHT_INTRO_SY / 2);
	}
	else if ((map->lenght * 64) > WIN_X && (map->height * 64) < WIN_Y)
	{
		printf("LONG PENNY ----------------->\n");
		mlx_put_image_to_window(map->mlx, map->win, map->intro2,
			(map->lenght * 32) - WIDTH_INTRO_LX / 2,
			(map->height * 32) - HEIGHT_INTRO_LY / 2);
	}
}

void	which_newgame(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->intro1,
		(map->lenght * 32) - WIDTH_NEWGAME / 2,
		(map->height * 32) - HEIGHT_INTRO / 2 + 750);
}

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
	map->intro2 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO2,
			&width_intro, &height_intro);
	map->intro3 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO3,
			&width_intro, &height_intro);
	printf("lenght = %d\n", map->lenght * 64);
	printf("height = %d\n", map->height * 64);
	which_penny(map);
	which_newgame(map);
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
