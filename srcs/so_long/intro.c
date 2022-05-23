#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	which_penny(t_map *map)
{
	if ((map->lenght * 64) > WIN_X && (map->height * 64) > WIN_Y)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->intro,
			(map->lenght * 32) - WIDTH_INTRO / 2,
			(map->height * 32) - HEIGHT_INTRO / 2);
	}
	else if ((map->lenght * 64) < WIN_X || (map->height * 64) > WIN_Y)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->intro3,
			(map->lenght * 32) - WIDTH_INTRO_SX / 2,
			(map->height * 32) - HEIGHT_INTRO_SY / 2);
	}
	else if ((map->lenght * 64) > WIN_X && (map->height * 64) < WIN_Y)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->intro2,
			(map->lenght * 32) - WIDTH_INTRO_LX / 2,
			(map->height * 32) - HEIGHT_INTRO_LY / 2);
	}
}

void	which_newgame(t_map *map)
{
	if ((map->lenght * 64) > WIN_X && (map->height * 64) > WIN_Y)
		mlx_put_image_to_window(map->mlx, map->win, map->intro1,
			(map->lenght * 32) - WIDTH_NEWGAME / 2,
			(map->height * 32) - HEIGHT_INTRO / 2 + 750);
	else if ((map->lenght * 64) < WIN_X || (map->height * 64) > WIN_Y)
		mlx_put_image_to_window(map->mlx, map->win, map->intro1,
			(map->lenght * 32) - WIDTH_NEWGAME / 2,
			(map->height * 32) - HEIGHT_INTRO / 2 + 610);
	else if ((map->lenght * 64) > WIN_X && (map->height * 64) < WIN_Y)
		mlx_put_image_to_window(map->mlx, map->win, map->intro1,
			(map->lenght * 32) - WIDTH_NEWGAME / 2 + 500,
			(map->height * 32) - HEIGHT_INTRO / 2 + 100);
}

void	intro_window(t_map *map)
{
	int	width_intro;
	int	height_intro;
	int	width_newgame;
	int	height_newgame;

	map->intro = mlx_xpm_file_to_image(map->mlx, IMG_INTRO,
			&width_intro, &height_intro);
	map->intro2 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO2,
			&width_intro, &height_intro);
	map->intro3 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO3,
			&width_intro, &height_intro);
	map->intro1 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO1,
			&width_newgame, &height_newgame);
	map_insert(map);
	which_penny(map);
	which_newgame(map);
}

void	game(t_map *map)
{
	map->lenght = ft_strlen(map->fullmap[0]);
	img_to_win(map->fullmap, map);
}
