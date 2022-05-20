#include "so_long.h"
# include "../../minilibx-linux/mlx.h"

void	waiting_to_mist(t_map *map, int y, int x)
{
	char **line;

	line = map->fullmap;
	if (map->move_step == 0)
	{
		map->myst_y = y;
		map->myst_x = x;
	}
	if (map->move_step == 2)
	{
		printf("\nRESETH\n");
		map->move_step = 0;
		mlx_put_image_to_window(map->mlx, map->win, map->wall24,
			(64 * (map->p_pos_x)), (64 * (map->p_pos_y)));
		map->myst_y = y;
		map->myst_x = x;
	}
}

void	erase_collectible(t_map *map, char	**line, int y, int x)
{
	int	i;

	i = 1;
	map->collectible_nbr -= i;
	line[y][x] = '0';
}

void	collectible_hunter(t_map *map, int i)
{
	char	**line;

	i = 1;
	line = map->fullmap;
	if (!ft_strcmp(map->movement, "left"))
	{
		if (line[map->p_pos_y][map->p_pos_x - 1] == 'C')
			erase_collectible(map, line, map->p_pos_y, map->p_pos_x - 1);
	}
	else if (!ft_strcmp(map->movement, "right"))
	{
		if (line[map->p_pos_y][map->p_pos_x + 1] == 'C')
			erase_collectible(map, line, map->p_pos_y, map->p_pos_x + 1);
	}
	else if (!ft_strcmp(map->movement, "up"))
	{
		if (line[map->p_pos_y - 1][map->p_pos_x] == 'C')
			erase_collectible(map, line, map->p_pos_y - 1, map->p_pos_x);
	}
	else if (!ft_strcmp(map->movement, "down"))
	{
		if (line[map->p_pos_y + 1][map->p_pos_x] == 'C')
			erase_collectible(map, line, map->p_pos_y + 1, map->p_pos_x);
	}
}


