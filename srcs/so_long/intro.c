#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	which_penny(t_map *map)
{
	if ((map->lenght * 64) > WIN_X && (map->height * 64) > WIN_Y)
	{
		map->intro = create_xpm_file_intro(map, map->intro, IMG_INTRO);
		mlx_put_image_to_window(map->mlx, map->win, map->intro,
			(map->lenght * 32) - WIDTH_INTRO / 2,
			(map->height * 32) - HEIGHT_INTRO / 2);
	}
	else if ((map->lenght * 64) < WIN_X || (map->height * 64) > WIN_Y)
	{
		map->intro = create_xpm_file_intro(map, map->intro, IMG_INTRO3);
		mlx_put_image_to_window(map->mlx, map->win, map->intro,
			(map->lenght * 32) - WIDTH_INTRO_SX / 2,
			(map->height * 32) - HEIGHT_INTRO_SY / 2);
	}
	else if ((map->lenght * 64) > WIN_X && (map->height * 64) < WIN_Y)
	{
		map->intro = create_xpm_file_intro(map, map->intro, IMG_INTRO2);
		mlx_put_image_to_window(map->mlx, map->win, map->intro,
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

void	intro_window(t_map *map, char **argv)
{
	init_struct_intro(map, argv);
	which_penny(map);
	which_newgame(map);
	map->movement = INTRO;
}

void	game(t_map *map)
{
	map_insert(map);
	init_struct(map);
	map->movement = IN_GAME;
	printf("%d\n", map->movement);
	map->lenght = ft_strlen(map->fullmap[0]);
	img_to_win(map->fullmap, map);
}
