#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	no_fog_exit(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->exit,
		64 * map->location_exit_x, 64 * map->location_exit_y);
}

void	waiting_to_mist(t_map *map)
{
	if (map->move_count == 0)
	{
		map->myst_y = map->p_pos_y;
		map->myst_x = map->p_pos_x;
		if (map->myst_x2 != 0 || map->myst_y2 != 0)
			mlx_put_image_to_window(map->mlx, map->win, map->wall[FOG],
				(64 * (map->myst_x2)), (64 * (map->myst_y2)));
	}
	else if (map->move_count == 1)
	{
		map->myst_y2 = map->p_pos_y;
		map->myst_x2 = map->p_pos_x;
		if (map->myst_x3 != 0 || map->myst_y3 != 0)
			mlx_put_image_to_window(map->mlx, map->win, map->wall[FOG],
				(64 * (map->myst_x3)), (64 * (map->myst_y3)));
	}
	else if (map->move_count == 2)
	{
		map->move_count = -1;
		mlx_put_image_to_window(map->mlx, map->win, map->wall[FOG],
			(64 * (map->myst_x)), (64 * (map->myst_y)));
		map->myst_x3 = map->p_pos_x;
		map->myst_y3 = map->p_pos_y;
	}
	no_fog_exit(map);
}

void	erase_collectible(t_map *map, char	**line, int y, int x)
{
	int	i;

	i = 1;
	map->collectible_nbr -= i;
	line[y][x] = '0';
}

void	collectible_hunter(t_map *map)
{
	int		fakey;
	int		fakex;

	fakey = 0;
	fakex = 0;
	if (!ft_strcmp(map->movement, "up"))
		fakey = -1;
	else if (!ft_strcmp(map->movement, "left"))
		fakex = -1;
	else if (!ft_strcmp(map->movement, "right"))
		fakex = 1;
	else if (!ft_strcmp(map->movement, "down"))
		fakey = 1;
	if (map->fullmap[map->p_pos_y + fakey][map->p_pos_x + fakex] == 'C')
		erase_collectible(map, map->fullmap, map->p_pos_y + fakey,
			map->p_pos_x + fakex);
}


