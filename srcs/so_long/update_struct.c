#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

int	count_nbr(t_map *map, char c)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (map->fullmap[y])
	{
		x = 0;
		while (map->fullmap[y][x])
		{
			if (map->fullmap[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	find_enemy_pos(t_map *map, char c)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map->fullmap[y])
	{
		x = 0;
		while (map->fullmap[y][x])
		{
			if (map->fullmap[y][x] == c)
			{
				map->enemy_pos_x = x;
				map->enemy_pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	*create_xpm_file_intro(t_map *map, void *ptr, char *img)
{
	int	width_intro;
	int	height_intro;

	ptr = mlx_xpm_file_to_image(map->mlx, img, &width_intro, &height_intro);
	return (ptr);
}

void	init_struct_intro(t_map *map, char **argv)
{
	int	width_newgame;
	int	height_newgame;

	map->fullmap = putintab(argv);
	map->lenght = ft_strlen(map->fullmap[0]);
	map->movement = 9999;
	map->height = check_width(argv);
	map->win_choice = 0;
	map->intro1 = mlx_xpm_file_to_image(map->mlx, IMG_INTRO1,
			&width_newgame, &height_newgame);
	map->win = mlx_new_window(map->mlx, map->lenght * WIDTH,
			map->height * HEIGHT, "so_long");
}

void	init_struct(t_map *map)
{
	map->win_choice = 0;
	map->movement = 9999;
	map->move_step = 0;
	map->move_count = 0;
	map->stop = 0;
	map->e_move_count = 0;
	map->collectible_nbr = count_nbr(map, 'C');
	map->time = 0;
	map->fog_changer = 0;
	find_enemy_pos(map, 'B');
}

void	update_struct(t_map *map, int fakey, int fakex)
{
	map->p_pos_y = map->p_pos_y + fakey;
	map->p_pos_x = map->p_pos_x + fakex;
	map->move_count++;
	map->move_step++;
}
