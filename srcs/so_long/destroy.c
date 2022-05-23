#include "so_long.h"
# include "../../minilibx-linux/mlx.h"


void	collectible_nbr(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	map->collectible_nbr = 0;
	while (map->fullmap[y])
	{
		x = 0;
		while (map->fullmap[y][x])
		{
			if (map->fullmap[y][x] == 'C')
				map->collectible_nbr++;
			x++;
		}
		y++;
	}
}

void	enemy_nbr(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	map->enemies = 0;
	while (map->fullmap[y])
	{
		x = 0;
		while (map->fullmap[y][x])
		{
			if (map->fullmap[y][x] == 'E')
				map->enemies++;
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
	map->movement = NULL;
	map->move_step = 0;
	map->move_count = 0;
	map->height = check_width(argv);
	collectible_nbr(map);
}

void	space(t_map *map)
{
	if (map->win_choice == NULL)
	{
		mlx_clear_window(map->mlx, map->win);
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
