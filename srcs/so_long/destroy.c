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

void	init_struct(t_map *map, char **line, char **argv)
{
	map->fullmap = line;
	map->lenght = ft_strlen(line[0]);
	map->win_choice = NULL;
	map->movement = ft_strdup("banane");
	map->move_step = 0;
	map->move_count = 0;
	map->height = check_width(argv);
	map->stop = 0;
	map->enemies = count_nbr(map, 'B');
	map->collectible_nbr = count_nbr(map, 'C');
	find_enemy_pos(map, 'B');
}

void	update_struct(t_map *map, int fakey, int fakex)
{
	map->p_pos_y = map->p_pos_y + fakey;
	map->p_pos_x = map->p_pos_x + fakex;
	map->move_count++;
	map->move_step++;
}

void	destroy_img(t_map *map, void *content)
{
	mlx_destroy_image(map->mlx, content);
}

void	space(t_map *map)
{
	if (map->win_choice == NULL)
	{
		mlx_clear_window(map->mlx, map->win);
		destroy_img(map, map->intro);
		destroy_img(map, map->intro2);
		destroy_img(map, map->intro3);
		destroy_img(map, map->intro1);
		map->win_choice = ft_strdup("space");
		game(map);
	}
}

int	escape(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	mlx_loop_end(map->mlx);
	exit (EXIT_SUCCESS);
}
